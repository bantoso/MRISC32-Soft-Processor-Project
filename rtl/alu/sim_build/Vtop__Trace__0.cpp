// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgIData(oldp+0,(vlSelfRef.A),32);
    bufp->chgIData(oldp+1,(vlSelfRef.B),32);
    bufp->chgCData(oldp+2,(vlSelfRef.pack_mode),2);
    bufp->chgIData(oldp+3,(vlSelfRef.result),32);
    bufp->chgIData(oldp+4,(vlSelfRef.adder32__DOT__A),32);
    bufp->chgIData(oldp+5,(vlSelfRef.adder32__DOT__B),32);
    bufp->chgCData(oldp+6,(vlSelfRef.adder32__DOT__pack_mode),2);
    bufp->chgIData(oldp+7,(vlSelfRef.adder32__DOT__result),32);
    bufp->chgIData(oldp+8,(vlSelfRef.adder32__DOT__word_sum),32);
    bufp->chgSData(oldp+9,(vlSelfRef.adder32__DOT__half_sum_lo),16);
    bufp->chgSData(oldp+10,(vlSelfRef.adder32__DOT__half_sum_hi),16);
    bufp->chgCData(oldp+11,(vlSelfRef.adder32__DOT__byte_sum0),8);
    bufp->chgCData(oldp+12,(vlSelfRef.adder32__DOT__byte_sum1),8);
    bufp->chgCData(oldp+13,(vlSelfRef.adder32__DOT__byte_sum2),8);
    bufp->chgCData(oldp+14,(vlSelfRef.adder32__DOT__byte_sum3),8);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
