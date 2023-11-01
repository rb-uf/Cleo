#include <iostream>
#include <vector>
#include "Vsimple_adder.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int hamming_weight(uint32_t n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    Vsimple_adder* top = new Vsimple_adder;

    VerilatedVcdC* vcd = new VerilatedVcdC;
    top->trace(vcd, 99);
    vcd->open("trace.vcd");

    std::vector<int> hamming_weights;
    
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            top->a = i;
            top->b = j;
            top->eval();
            vcd->dump(i * 16 + j);

            int hw = hamming_weight(top->sum) + hamming_weight(top->carry);
            hamming_weights.push_back(hw);

            std::cout << "a = " << i << ", b = " << j
                      << ", sum = " << (int)top->sum
                      << ", carry = " << (int)top->carry 
                      << ", Hamming weight = " << hw << std::endl;
        }
    }

    vcd->close();
    delete vcd;
    delete top;

    // Print the Hamming weights vector
    std::cout << "Hamming weights for each clock cycle: " << std::endl;
    for (size_t i = 0; i < hamming_weights.size(); ++i) {
        std::cout << "Cycle " << i << ": " << hamming_weights[i] << std::endl;
    }

    return 0;
}