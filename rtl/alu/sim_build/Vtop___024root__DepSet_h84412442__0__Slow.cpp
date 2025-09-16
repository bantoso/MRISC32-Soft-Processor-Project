// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void Vtop___024root___configure_coverage(Vtop___024root* vlSelf, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___configure_coverage\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    (void)first;  // Prevent unused variable warning
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[0]), first, "/home/baiquni/hdl_ws/projects/mrisc32_core/rtl/alu/adder32.sv", 3, 25, ".adder32", "v_toggle/adder32", "A");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[64]), first, "/home/baiquni/hdl_ws/projects/mrisc32_core/rtl/alu/adder32.sv", 4, 25, ".adder32", "v_toggle/adder32", "B");
    vlSelf->__vlCoverToggleInsert(0, 1, 1, &(vlSymsp->__Vcoverage[128]), first, "/home/baiquni/hdl_ws/projects/mrisc32_core/rtl/alu/adder32.sv", 5, 25, ".adder32", "v_toggle/adder32", "pack_mode");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[132]), first, "/home/baiquni/hdl_ws/projects/mrisc32_core/rtl/alu/adder32.sv", 6, 25, ".adder32", "v_toggle/adder32", "result");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[196]), first, "/home/baiquni/hdl_ws/projects/mrisc32_core/rtl/alu/adder32.sv", 10, 18, ".adder32", "v_toggle/adder32", "word_sum");
    vlSelf->__vlCoverToggleInsert(0, 15, 1, &(vlSymsp->__Vcoverage[260]), first, "/home/baiquni/hdl_ws/projects/mrisc32_core/rtl/alu/adder32.sv", 11, 18, ".adder32", "v_toggle/adder32", "half_sum_lo");
    vlSelf->__vlCoverToggleInsert(0, 15, 1, &(vlSymsp->__Vcoverage[292]), first, "/home/baiquni/hdl_ws/projects/mrisc32_core/rtl/alu/adder32.sv", 11, 31, ".adder32", "v_toggle/adder32", "half_sum_hi");
    vlSelf->__vlCoverToggleInsert(0, 7, 1, &(vlSymsp->__Vcoverage[324]), first, "/home/baiquni/hdl_ws/projects/mrisc32_core/rtl/alu/adder32.sv", 12, 18, ".adder32", "v_toggle/adder32", "byte_sum0");
    vlSelf->__vlCoverToggleInsert(0, 7, 1, &(vlSymsp->__Vcoverage[340]), first, "/home/baiquni/hdl_ws/projects/mrisc32_core/rtl/alu/adder32.sv", 12, 29, ".adder32", "v_toggle/adder32", "byte_sum1");
    vlSelf->__vlCoverToggleInsert(0, 7, 1, &(vlSymsp->__Vcoverage[356]), first, "/home/baiquni/hdl_ws/projects/mrisc32_core/rtl/alu/adder32.sv", 12, 40, ".adder32", "v_toggle/adder32", "byte_sum2");
    vlSelf->__vlCoverToggleInsert(0, 7, 1, &(vlSymsp->__Vcoverage[372]), first, "/home/baiquni/hdl_ws/projects/mrisc32_core/rtl/alu/adder32.sv", 12, 51, ".adder32", "v_toggle/adder32", "byte_sum3");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[388]), first, "/home/baiquni/hdl_ws/projects/mrisc32_core/rtl/alu/adder32.sv", 31, 18, ".adder32", "v_line/adder32", "case", "31");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[389]), first, "/home/baiquni/hdl_ws/projects/mrisc32_core/rtl/alu/adder32.sv", 32, 18, ".adder32", "v_line/adder32", "case", "32");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[390]), first, "/home/baiquni/hdl_ws/projects/mrisc32_core/rtl/alu/adder32.sv", 33, 18, ".adder32", "v_line/adder32", "case", "33");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[391]), first, "/home/baiquni/hdl_ws/projects/mrisc32_core/rtl/alu/adder32.sv", 34, 13, ".adder32", "v_line/adder32", "case", "34");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[392]), first, "/home/baiquni/hdl_ws/projects/mrisc32_core/rtl/alu/adder32.sv", 28, 5, ".adder32", "v_line/adder32", "block", "28-30");
}
