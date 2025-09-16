// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadder32.h for the primary calling header

#ifndef VERILATED_VADDER32___024ROOT_H_
#define VERILATED_VADDER32___024ROOT_H_  // guard

#include "verilated.h"


class Vadder32__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vadder32___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(pack_mode,1,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    VL_IN(A,31,0);
    VL_IN(B,31,0);
    VL_OUT(result,31,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vadder32__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vadder32___024root(Vadder32__Syms* symsp, const char* v__name);
    ~Vadder32___024root();
    VL_UNCOPYABLE(Vadder32___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
