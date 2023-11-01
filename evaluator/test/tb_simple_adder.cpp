#include <iostream>
#include "Vsimple_adder.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv); // Initialize Verilator
    Verilated::traceEverOn(true); // Enable tracing
    Vsimple_adder* top = new Vsimple_adder; // Instantiate the design

    VerilatedVcdC* vcd = new VerilatedVcdC;
    top->trace(vcd, 99);
    vcd->open("trace.vcd");

    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            top->a = i;
            top->b = j;
            top->eval(); // Evaluate the design
            vcd->dump(i * 16 + j); // Dump VCD trace

            std::cout << "a = " << i << ", b = " << j
                      << ", sum = " << (int)top->sum
                      << ", carry = " << (int)top->carry << std::endl;
        }
    }

    vcd->close();
    delete vcd;
    delete top;
    return 0;
}

