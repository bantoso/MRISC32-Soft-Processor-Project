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
    if (((IData)(vlSelfRef.adder32__DOT__pack_mode) 
         ^ (IData)(vlSelfRef.adder32__DOT____Vtogcov__pack_mode))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSymsp->__Vcoverage + 128, vlSelfRef.adder32__DOT__pack_mode, vlSelfRef.adder32__DOT____Vtogcov__pack_mode);
        vlSelfRef.adder32__DOT____Vtogcov__pack_mode 
            = vlSelfRef.adder32__DOT__pack_mode;
    }
    if ((vlSelfRef.adder32__DOT__A ^ vlSelfRef.adder32__DOT____Vtogcov__A)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 0, vlSelfRef.adder32__DOT__A, vlSelfRef.adder32__DOT____Vtogcov__A);
        vlSelfRef.adder32__DOT____Vtogcov__A = vlSelfRef.adder32__DOT__A;
    }
    if ((vlSelfRef.adder32__DOT__B ^ vlSelfRef.adder32__DOT____Vtogcov__B)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 64, vlSelfRef.adder32__DOT__B, vlSelfRef.adder32__DOT____Vtogcov__B);
        vlSelfRef.adder32__DOT____Vtogcov__B = vlSelfRef.adder32__DOT__B;
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
    if ((vlSelfRef.adder32__DOT__word_sum ^ vlSelfRef.adder32__DOT____Vtogcov__word_sum)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 196, vlSelfRef.adder32__DOT__word_sum, vlSelfRef.adder32__DOT____Vtogcov__word_sum);
        vlSelfRef.adder32__DOT____Vtogcov__word_sum 
            = vlSelfRef.adder32__DOT__word_sum;
    }
    if (((IData)(vlSelfRef.adder32__DOT__half_sum_lo) 
         ^ (IData)(vlSelfRef.adder32__DOT____Vtogcov__half_sum_lo))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSymsp->__Vcoverage + 260, vlSelfRef.adder32__DOT__half_sum_lo, vlSelfRef.adder32__DOT____Vtogcov__half_sum_lo);
        vlSelfRef.adder32__DOT____Vtogcov__half_sum_lo 
            = vlSelfRef.adder32__DOT__half_sum_lo;
    }
    if (((IData)(vlSelfRef.adder32__DOT__half_sum_hi) 
         ^ (IData)(vlSelfRef.adder32__DOT____Vtogcov__half_sum_hi))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSymsp->__Vcoverage + 292, vlSelfRef.adder32__DOT__half_sum_hi, vlSelfRef.adder32__DOT____Vtogcov__half_sum_hi);
        vlSelfRef.adder32__DOT____Vtogcov__half_sum_hi 
            = vlSelfRef.adder32__DOT__half_sum_hi;
    }
    if (((IData)(vlSelfRef.adder32__DOT__byte_sum0) 
         ^ (IData)(vlSelfRef.adder32__DOT____Vtogcov__byte_sum0))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSymsp->__Vcoverage + 324, vlSelfRef.adder32__DOT__byte_sum0, vlSelfRef.adder32__DOT____Vtogcov__byte_sum0);
        vlSelfRef.adder32__DOT____Vtogcov__byte_sum0 
            = vlSelfRef.adder32__DOT__byte_sum0;
    }
    if (((IData)(vlSelfRef.adder32__DOT__byte_sum1) 
         ^ (IData)(vlSelfRef.adder32__DOT____Vtogcov__byte_sum1))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSymsp->__Vcoverage + 340, vlSelfRef.adder32__DOT__byte_sum1, vlSelfRef.adder32__DOT____Vtogcov__byte_sum1);
        vlSelfRef.adder32__DOT____Vtogcov__byte_sum1 
            = vlSelfRef.adder32__DOT__byte_sum1;
    }
    if (((IData)(vlSelfRef.adder32__DOT__byte_sum2) 
         ^ (IData)(vlSelfRef.adder32__DOT____Vtogcov__byte_sum2))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSymsp->__Vcoverage + 356, vlSelfRef.adder32__DOT__byte_sum2, vlSelfRef.adder32__DOT____Vtogcov__byte_sum2);
        vlSelfRef.adder32__DOT____Vtogcov__byte_sum2 
            = vlSelfRef.adder32__DOT__byte_sum2;
    }
    if (((IData)(vlSelfRef.adder32__DOT__byte_sum3) 
         ^ (IData)(vlSelfRef.adder32__DOT____Vtogcov__byte_sum3))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSymsp->__Vcoverage + 372, vlSelfRef.adder32__DOT__byte_sum3, vlSelfRef.adder32__DOT____Vtogcov__byte_sum3);
        vlSelfRef.adder32__DOT____Vtogcov__byte_sum3 
            = vlSelfRef.adder32__DOT__byte_sum3;
    }
    vlSelfRef.adder32__DOT__result = 0U;
    if ((0U == (IData)(vlSelfRef.adder32__DOT__pack_mode))) {
        vlSelfRef.adder32__DOT__result = vlSelfRef.adder32__DOT__word_sum;
        ++(vlSymsp->__Vcoverage[388]);
    } else if ((1U == (IData)(vlSelfRef.adder32__DOT__pack_mode))) {
        ++(vlSymsp->__Vcoverage[389]);
        vlSelfRef.adder32__DOT__result = (((IData)(vlSelfRef.adder32__DOT__half_sum_hi) 
                                           << 0x10U) 
                                          | (IData)(vlSelfRef.adder32__DOT__half_sum_lo));
    } else if ((2U == (IData)(vlSelfRef.adder32__DOT__pack_mode))) {
        ++(vlSymsp->__Vcoverage[390]);
        vlSelfRef.adder32__DOT__result = ((((IData)(vlSelfRef.adder32__DOT__byte_sum3) 
                                            << 0x18U) 
                                           | ((IData)(vlSelfRef.adder32__DOT__byte_sum2) 
                                              << 0x10U)) 
                                          | (((IData)(vlSelfRef.adder32__DOT__byte_sum1) 
                                              << 8U) 
                                             | (IData)(vlSelfRef.adder32__DOT__byte_sum0)));
    } else {
        ++(vlSymsp->__Vcoverage[391]);
        vlSelfRef.adder32__DOT__result = 0U;
    }
    if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.adder32__DOT__pack_mode)) 
                                            << 2U) 
                                           | (((1U 
                                                == (IData)(vlSelfRef.adder32__DOT__pack_mode)) 
                                               << 1U) 
                                              | (0U 
                                                 == (IData)(vlSelfRef.adder32__DOT__pack_mode)))))))))) {
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
    ++(vlSymsp->__Vcoverage[392]);
    if ((vlSelfRef.adder32__DOT__result ^ vlSelfRef.adder32__DOT____Vtogcov__result)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 132, vlSelfRef.adder32__DOT__result, vlSelfRef.adder32__DOT____Vtogcov__result);
        vlSelfRef.adder32__DOT____Vtogcov__result = vlSelfRef.adder32__DOT__result;
    }
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
