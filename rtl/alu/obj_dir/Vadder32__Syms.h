// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VADDER32__SYMS_H_
#define VERILATED_VADDER32__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vadder32.h"

// INCLUDE MODULE CLASSES
#include "Vadder32___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vadder32__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vadder32* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vadder32___024root             TOP;

    // CONSTRUCTORS
    Vadder32__Syms(VerilatedContext* contextp, const char* namep, Vadder32* modelp);
    ~Vadder32__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
