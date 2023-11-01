// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsimple_adder.h for the primary calling header

#include "Vsimple_adder.h"
#include "Vsimple_adder__Syms.h"

//==========

VL_CTOR_IMP(Vsimple_adder) {
    Vsimple_adder__Syms* __restrict vlSymsp = __VlSymsp = new Vsimple_adder__Syms(this, name());
    Vsimple_adder* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vsimple_adder::__Vconfigure(Vsimple_adder__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vsimple_adder::~Vsimple_adder() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vsimple_adder::_eval_initial(Vsimple_adder__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_adder::_eval_initial\n"); );
    Vsimple_adder* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vsimple_adder::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_adder::final\n"); );
    // Variables
    Vsimple_adder__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vsimple_adder* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vsimple_adder::_eval_settle(Vsimple_adder__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_adder::_eval_settle\n"); );
    Vsimple_adder* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vsimple_adder::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_adder::_ctor_var_reset\n"); );
    // Body
    a = VL_RAND_RESET_I(4);
    b = VL_RAND_RESET_I(4);
    sum = VL_RAND_RESET_I(4);
    carry = VL_RAND_RESET_I(1);
}
