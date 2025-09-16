// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadder32.h for the primary calling header

#include "Vadder32__pch.h"
#include "Vadder32___024root.h"

VL_INLINE_OPT void Vadder32___024root___ico_sequent__TOP__0(Vadder32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder32___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->result = 0U;
    vlSelf->result = ((0U == (IData)(vlSelf->pack_mode))
                       ? (vlSelf->A + vlSelf->B) : 
                      ((1U == (IData)(vlSelf->pack_mode))
                        ? ((((vlSelf->A >> 0x10U) + 
                             (vlSelf->B >> 0x10U)) 
                            << 0x10U) | (0xffffU & 
                                         (vlSelf->A 
                                          + vlSelf->B)))
                        : ((2U == (IData)(vlSelf->pack_mode))
                            ? ((((vlSelf->A >> 0x18U) 
                                 + (vlSelf->B >> 0x18U)) 
                                << 0x18U) | ((0xff0000U 
                                              & (((vlSelf->A 
                                                   >> 0x10U) 
                                                  + 
                                                  (vlSelf->B 
                                                   >> 0x10U)) 
                                                 << 0x10U)) 
                                             | ((0xff00U 
                                                 & (((vlSelf->A 
                                                      >> 8U) 
                                                     + 
                                                     (vlSelf->B 
                                                      >> 8U)) 
                                                    << 8U)) 
                                                | (0xffU 
                                                   & (vlSelf->A 
                                                      + vlSelf->B)))))
                            : 0U)));
}

void Vadder32___024root___eval_ico(Vadder32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder32___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vadder32___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vadder32___024root___eval_triggers__ico(Vadder32___024root* vlSelf);

bool Vadder32___024root___eval_phase__ico(Vadder32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder32___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vadder32___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vadder32___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vadder32___024root___eval_act(Vadder32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder32___024root___eval_act\n"); );
}

void Vadder32___024root___eval_nba(Vadder32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder32___024root___eval_nba\n"); );
}

void Vadder32___024root___eval_triggers__act(Vadder32___024root* vlSelf);

bool Vadder32___024root___eval_phase__act(Vadder32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder32___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vadder32___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vadder32___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vadder32___024root___eval_phase__nba(Vadder32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder32___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vadder32___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder32___024root___dump_triggers__ico(Vadder32___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder32___024root___dump_triggers__nba(Vadder32___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadder32___024root___dump_triggers__act(Vadder32___024root* vlSelf);
#endif  // VL_DEBUG

void Vadder32___024root___eval(Vadder32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder32___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vadder32___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("adder32.sv", 2, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vadder32___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vadder32___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("adder32.sv", 2, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vadder32___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("adder32.sv", 2, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vadder32___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vadder32___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vadder32___024root___eval_debug_assertions(Vadder32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder32___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->pack_mode & 0xfcU))) {
        Verilated::overWidthError("pack_mode");}
}
#endif  // VL_DEBUG
