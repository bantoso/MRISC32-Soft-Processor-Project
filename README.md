# MRISC32 Soft Processor Core

This project implements and verifies components of the [MRISC-A1 RISC-V processor](https://github.com/mrisc32/mrisc32-a1)
 in SystemVerilog with a Cocotb + uvm testbench framework.

The current focus is on verifying the 32-bit adder (adder32) module and implementing different coverage tests, and creating a modular library to be used on other components of the processor.

## 📌 Current Status

✅ RTL design for adder32.sv (from MRISC-A1) included

✅ pyuvm testbench (tb_adder32.py) implemented

✅ Directed and randomized sequences working

✅ Reference model (add_model) for result comparison

⚠️ Waveform dumping enabled but needs refinement

## 📝 To-Do

 Expand directed tests (overflow, boundary conditions)

 Add functional coverage for different pack modes

 Improve scoreboard for pipelined DUTs

 Refactor BFM for cleaner DUT interface

 Add documentation for Makefile usage

 Set up CI (GitHub Actions) for automated verification

## 🚀 Goal

Develop a fully functional pipelined processor implementing the complete MRISC32 ISA, with reusable verification components and libraries that can be applied across future modules and projects.
