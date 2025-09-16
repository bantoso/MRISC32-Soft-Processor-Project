// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vadder32__pch.h"

//============================================================
// Constructors

Vadder32::Vadder32(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vadder32__Syms(contextp(), _vcname__, this)}
    , pack_mode{vlSymsp->TOP.pack_mode}
    , A{vlSymsp->TOP.A}
    , B{vlSymsp->TOP.B}
    , result{vlSymsp->TOP.result}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vadder32::Vadder32(const char* _vcname__)
    : Vadder32(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vadder32::~Vadder32() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vadder32___024root___eval_debug_assertions(Vadder32___024root* vlSelf);
#endif  // VL_DEBUG
void Vadder32___024root___eval_static(Vadder32___024root* vlSelf);
void Vadder32___024root___eval_initial(Vadder32___024root* vlSelf);
void Vadder32___024root___eval_settle(Vadder32___024root* vlSelf);
void Vadder32___024root___eval(Vadder32___024root* vlSelf);

void Vadder32::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vadder32::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vadder32___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vadder32___024root___eval_static(&(vlSymsp->TOP));
        Vadder32___024root___eval_initial(&(vlSymsp->TOP));
        Vadder32___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vadder32___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vadder32::eventsPending() { return false; }

uint64_t Vadder32::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vadder32::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vadder32___024root___eval_final(Vadder32___024root* vlSelf);

VL_ATTR_COLD void Vadder32::final() {
    Vadder32___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vadder32::hierName() const { return vlSymsp->name(); }
const char* Vadder32::modelName() const { return "Vadder32"; }
unsigned Vadder32::threads() const { return 1; }
void Vadder32::prepareClone() const { contextp()->prepareClone(); }
void Vadder32::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vadder32::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vadder32::trace()' called on model that was Verilated without --trace option");
}
