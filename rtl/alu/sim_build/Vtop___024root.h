// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_cov.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(pack_mode,1,0);
    CData/*1:0*/ adder32__DOT__pack_mode;
    CData/*7:0*/ adder32__DOT__byte_sum0;
    CData/*7:0*/ adder32__DOT__byte_sum1;
    CData/*7:0*/ adder32__DOT__byte_sum2;
    CData/*7:0*/ adder32__DOT__byte_sum3;
    CData/*1:0*/ adder32__DOT____Vtogcov__pack_mode;
    CData/*7:0*/ adder32__DOT____Vtogcov__byte_sum0;
    CData/*7:0*/ adder32__DOT____Vtogcov__byte_sum1;
    CData/*7:0*/ adder32__DOT____Vtogcov__byte_sum2;
    CData/*7:0*/ adder32__DOT____Vtogcov__byte_sum3;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ adder32__DOT__half_sum_lo;
    SData/*15:0*/ adder32__DOT__half_sum_hi;
    SData/*15:0*/ adder32__DOT____Vtogcov__half_sum_lo;
    SData/*15:0*/ adder32__DOT____Vtogcov__half_sum_hi;
    VL_IN(A,31,0);
    VL_IN(B,31,0);
    VL_OUT(result,31,0);
    IData/*31:0*/ adder32__DOT__A;
    IData/*31:0*/ adder32__DOT__B;
    IData/*31:0*/ adder32__DOT__result;
    IData/*31:0*/ adder32__DOT__word_sum;
    IData/*31:0*/ adder32__DOT____Vtogcov__A;
    IData/*31:0*/ adder32__DOT____Vtogcov__B;
    IData/*31:0*/ adder32__DOT____Vtogcov__result;
    IData/*31:0*/ adder32__DOT____Vtogcov__word_sum;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
    void __vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp);
    void __vlCoverToggleInsert(int begin, int end, bool ranged, uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp);
};


#endif  // guard
