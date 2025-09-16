# tb_adder32.py — pyuvm-style testbench for adder32.sv (TinyALU pattern)

import random
import cocotb
from cocotb.triggers import *

from pyuvm import *
import logging
import enum

# =========================
# Reference model & enums
# =========================
PACK_WORD, PACK_HALF, PACK_BYTE = 0, 1, 2

def add_model(A, B, mode):
    A &= 0xFFFF_FFFF
    B &= 0xFFFF_FFFF
    if mode == PACK_WORD:
        return (A + B) & 0xFFFF_FFFF
    if mode == PACK_HALF:
        lo = ((A & 0xFFFF) + (B & 0xFFFF)) & 0xFFFF
        hi = (((A >> 16) & 0xFFFF) + ((B >> 16) & 0xFFFF)) & 0xFFFF
        return ((hi & 0xFFFF) << 16) | lo
    if mode == PACK_BYTE:
        r = 0
        for i in range(4):
            s = ((A >> (8*i)) & 0xFF) + ((B >> (8*i)) & 0xFF)
            r |= (s & 0xFF) << (8*i)
        return r & 0xFFFF_FFFF
    return 0

# ==================
# BFM (like TinyALU)
# ==================
class Adder32Bfm:
    """
    TinyALU-style BFM singleton that uses cocotb.top for DUT access.
    No ConfigDB usage for the DUT, so no 'uvm_test_top ... not in ConfigDB' issues.
    """
    _inst = None

    def __new__(cls):
        if cls._inst is None:
            cls._inst = super().__new__(cls)
            cls._inst._init_once()
        return cls._inst

    def _init_once(self):
        self.dut = cocotb.top
        for sig in ("A", "B", "pack_mode", "result"):
            if not hasattr(self.dut, sig):
                raise AttributeError(f"DUT missing signal '{sig}'")

    # Writes must happen in a write phase — call this only when NOT in ReadOnly.
    def drive(self, A, B, mode):
        self.dut.A.value = A & 0xFFFF_FFFF
        self.dut.B.value = B & 0xFFFF_FFFF
        self.dut.pack_mode.value = mode

    # Reads happen in ReadOnly.
    def sample(self):
        return {
            "A":    int(self.dut.A.value),
            "B":    int(self.dut.B.value),
            "mode": int(self.dut.pack_mode.value),
            "R":    int(self.dut.result.value),
        }
    async def reset(self):
        self.dut.A.value = 0
        self.dut.B.value = 0
        self.dut.pack_mode.value = 0
        self.dut.result.value = 0

        #self.dut.reset_n.value = 1


    def start_bfm(self):
        cocotb.start_soon(self.drive(self.dut.A.value, self.dut.B.value, self.dut.pack_mode.value))
        cocotb.start_soon(self.cmd_mon_bfm())
        cocotb.start_soon(self.result_mon_bfm())

# =========
# Transaction
# =========
class AddTxn(uvm_sequence_item):
    def __init__(self, name="add_txn", A=0, B=0, mode=PACK_WORD):
        super().__init__(name)
        self.A = A & 0xFFFF_FFFF
        self.B = B & 0xFFFF_FFFF
        self.mode = mode

# =========
# Sequences
# =========
class DirectedSeq(uvm_sequence):
    async def body(self):
        cases = [
            (0xFFFF_FFFF, 0x0000_0001, PACK_WORD),
            (0x0000_0003, 0x0000_0004, PACK_WORD),
            (0x0001_FFFF, 0x0001_0001, PACK_HALF),
            (0x00FF_0000, 0x0001_0000, PACK_BYTE),
        ]
        for A, B, m in cases:
            t = AddTxn(A=A, B=B, mode=m)
            await self.start_item(t)
            await self.finish_item(t)

class RandomSeq(uvm_sequence):
    def __init__(self, name="random_seq", n_items=300):
        super().__init__(name)
        self.n_items = n_items

    async def body(self):
        for _ in range(self.n_items):
            m = random.choice([PACK_WORD, PACK_HALF, PACK_BYTE])
            A = random.getrandbits(32)
            B = random.getrandbits(32)
            t = AddTxn(A=A, B=B, mode=m)
            await self.start_item(t)
            await self.finish_item(t)

# ================
# Driver & Monitor
# ================
class AddDriver(uvm_driver):
    def build_phase(self):
        self.ap = uvm_analysis_port("ap", self)
    def start_of_simulation_phase(self):
        self.bfm = Adder32Bfm()
    async def launch_tb(self):
        await self.bfm.reset()
        self.bfm.start_bfm()
    async def run_phase(self):
        bfm = Adder32Bfm()
        while True:
            await self.launch_tb()

            # Ensure we are *not* in ReadOnly before writing
            # Timer(0) advances to a new delta cycle with write access
            await Timer(0, "ns")

            # Write inputs
            bfm.drive(txn.A, txn.B, txn.mode)

            # Now move to ReadOnly to let the value settle and be observable
            await ReadOnly()

            self.seq_item_port.item_done()

class AddMonitor(uvm_component):
    def build_phase(self):
        super().build_phase()
        self.ap = uvm_analysis_port("ap", self)
        self._last = None

    async def run_phase(self):
        bfm = Adder32Bfm()
        while True:
            # Only read in ReadOnly phase
            await ReadOnly()
            act = bfm.sample()
            key = (act["A"], act["B"], act["mode"], act["R"])
            if key != self._last:
                self._last = key
                self.ap.write(act)
            # Light polling to avoid tight loop
            await Timer(1, "ns")

# ===========
# Scoreboard
# ===========
class AddScoreboard(uvm_component):
    def build_phase(self):
        super().build_phase()
        self.cmd_fifo = uvm_tlm_analysis_fifo("cmd_fifo", self)
        self.result_fifo = uvm_tlm_analysis_fifo("result_fifo", self)
        self.cmd_export = self.cmd_fifo.analysis_export
        self.result_export = self.result_fifo.analysis_export
        self.errors = 0

    # In pyuvm, subscribers receive via write()
    def write(self, act):
        want = add_model(act["A"], act["B"], act["mode"]) & 0xFFFF_FFFF
        got  = act["R"] & 0xFFFF_FFFF
        if got != want:
            self.errors += 1
            self.uvm_report_error(
                "SCB",
                f"Mismatch: A={act['A']:08x} B={act['B']:08x} mode={act['mode']} got={got:08x} exp={want:08x}"
            )
        else:
            self.uvm_report_info("SCB", "OK", verbosity=200)

# =========
# Agent/Env
# =========
class AddAgent(uvm_component):
    def build_phase(self):
        super().build_phase()
        self.seqr = uvm_sequencer("seqr", self)
        self.drv  = AddDriver("drv", self)
        self.mon  = AddMonitor("mon", self)


class AddEnv(uvm_component):
    def build_phase(self):
        super().build_phase()
        self.agent = AddAgent("agent", self)
        self.scb   = AddScoreboard("scb", self)

    def connect_phase(self):
        # Monitor publishes via analysis_port; scoreboard subscribes via analysis_export
        self.agent.mon.ap.connect(self.scb.result_export)
        self.agent.mon.ap.connect(self.scb.cmd_export)

# =====
# Test
# =====
class AdderTest(uvm_test):
    def build_phase(self):
        super().build_phase()
        self.env = AddEnv("env", self)

    async def run_phase(self):
        self.raise_objection()

        # Run directed first
        await DirectedSeq("dir").start(self.env.agent.seqr)

        # Then randomized
        await RandomSeq("rand", n_items=300).start(self.env.agent.seqr)

        # Let the last sample propagate
        await Timer(5, "ns")

        self.drop_objection()

# ====================
# Cocotb entry point
# ====================
@cocotb.test()
async def run_uvm(dut):
    # No ConfigDB for DUT; BFM uses cocotb.top (TinyALU pattern)
    await uvm_root().run_test("AdderTest")
