// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.adder32__DOT__pack_mode = vlSelfRef.pack_mode;
    vlSelfRef.adder32__DOT__A = vlSelfRef.A;
    vlSelfRef.adder32__DOT__B = vlSelfRef.B;
    if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.adder32__DOT__pack_mode)) 
                               << 2U) | (((1U == (IData)(vlSelfRef.adder32__DOT__pack_mode)) 
                                          << 1U) | 
                                         (0U == (IData)(vlSelfRef.adder32__DOT__pack_mode)))))))) {
        if ((0U != (((2U == (IData)(vlSelfRef.adder32__DOT__pack_mode)) 
                     << 2U) | (((1U == (IData)(vlSelfRef.adder32__DOT__pack_mode)) 
                                << 1U) | (0U == (IData)(vlSelfRef.adder32__DOT__pack_mode)))))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: adder32.sv:30: Assertion failed in %Nadder32: unique case, but multiple matches found for '2'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),2,(IData)(vlSelfRef.adder32__DOT__pack_mode));
                VL_STOP_MT("/home/baiquni/hdl_ws/projects/mrisc32_core/rtl/alu/adder32.sv", 30, "");
            }
        }
    }
    vlSelfRef.adder32__DOT__word_sum = (vlSelfRef.adder32__DOT__A 
                                        + vlSelfRef.adder32__DOT__B);
    vlSelfRef.adder32__DOT__half_sum_lo = (0xffffU 
                                           & (vlSelfRef.adder32__DOT__A 
                                              + vlSelfRef.adder32__DOT__B));
    vlSelfRef.adder32__DOT__half_sum_hi = (0xffffU 
                                           & ((vlSelfRef.adder32__DOT__A 
                                               >> 0x10U) 
                                              + (vlSelfRef.adder32__DOT__B 
                                                 >> 0x10U)));
    vlSelfRef.adder32__DOT__byte_sum0 = (0xffU & (vlSelfRef.adder32__DOT__A 
                                                  + vlSelfRef.adder32__DOT__B));
    vlSelfRef.adder32__DOT__byte_sum1 = (0xffU & ((vlSelfRef.adder32__DOT__A 
                                                   >> 8U) 
                                                  + 
                                                  (vlSelfRef.adder32__DOT__B 
                                                   >> 8U)));
    vlSelfRef.adder32__DOT__byte_sum2 = (0xffU & ((vlSelfRef.adder32__DOT__A 
                                                   >> 0x10U) 
                                                  + 
                                                  (vlSelfRef.adder32__DOT__B 
                                                   >> 0x10U)));
    vlSelfRef.adder32__DOT__byte_sum3 = (0xffU & ((vlSelfRef.adder32__DOT__A 
                                                   >> 0x18U) 
                                                  + 
                                                  (vlSelfRef.adder32__DOT__B 
                                                   >> 0x18U)));
    vlSelfRef.adder32__DOT__result = ((0U == (IData)(vlSelfRef.adder32__DOT__pack_mode))
                                       ? vlSelfRef.adder32__DOT__word_sum
                                       : ((1U == (IData)(vlSelfRef.adder32__DOT__pack_mode))
                                           ? (((IData)(vlSelfRef.adder32__DOT__half_sum_hi) 
                                               << 0x10U) 
                                              | (IData)(vlSelfRef.adder32__DOT__half_sum_lo))
                                           : ((2U == (IData)(vlSelfRef.adder32__DOT__pack_mode))
                                               ? ((
                                                   ((IData)(vlSelfRef.adder32__DOT__byte_sum3) 
                                                    << 0x18U) 
                                                   | ((IData)(vlSelfRef.adder32__DOT__byte_sum2) 
                                                      << 0x10U)) 
                                                  | (((IData)(vlSelfRef.adder32__DOT__byte_sum1) 
                                                      << 8U) 
                                                     | (IData)(vlSelfRef.adder32__DOT__byte_sum0)))
                                               : 0U)));
    vlSelfRef.result = vlSelfRef.adder32__DOT__result;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}
