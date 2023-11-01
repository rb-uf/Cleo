#include <iostream>
#include "Vsimple_adder.h"
#include "verilated.h"

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv); // Initialize Verilator
    Vsimple_adder* top = new Vsimple_adder; // Instantiate the design

    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            top->a = i;
            top->b = j;
            top->eval(); // Evaluate the design

            std::cout << "a = " << i << ", b = " << j
                      << ", sum = " << (int)top->sum
                      << ", carry = " << (int)top->carry << std::endl;
        }
    }
    delete top;
    return 0;
}
