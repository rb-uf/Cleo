#include <iostream>
#include <vector>
#include "Vsimple_adder.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

void count_transitions(uint32_t prev, uint32_t curr, int& pos_trans, int& neg_trans) {
    for (int i = 0; i < 32; ++i) {
        bool prev_bit = (prev >> i) & 1;
        bool curr_bit = (curr >> i) & 1;
        if (!prev_bit && curr_bit) pos_trans++;
        if (prev_bit && !curr_bit) neg_trans++;
    }
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    Vsimple_adder* top = new Vsimple_adder;

    VerilatedVcdC* vcd = new VerilatedVcdC;
    top->trace(vcd, 99);
    vcd->open("trace.vcd");

    std::vector<int> pos_transitions, neg_transitions;
    uint32_t prev_sum = 0, prev_carry = 0;

    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            top->a = i;
            top->b = j;
            top->eval();
            vcd->dump(i * 16 + j);

            int pos_trans = 0, neg_trans = 0;
            count_transitions(prev_sum, top->sum, pos_trans, neg_trans);
            count_transitions(prev_carry, top->carry, pos_trans, neg_trans);
            pos_transitions.push_back(pos_trans);
            neg_transitions.push_back(neg_trans);

            prev_sum = top->sum;
            prev_carry = top->carry;

            std::cout << "a = " << i << ", b = " << j
                      << ", sum = " << (int)top->sum
                      << ", carry = " << (int)top->carry 
                      << ", Positive Transitions = " << pos_trans
                      << ", Negative Transitions = " << neg_trans << std::endl;
        }
    }

    vcd->close();
    delete vcd;
    delete top;

    // Print the transitions vectors
    std::cout << "Positive and Negative Transitions for each clock cycle: " << std::endl;
    for (size_t i = 0; i < pos_transitions.size(); ++i) {
        std::cout << "Cycle " << i << ": "
                  << "Positive Transitions = " << pos_transitions[i] 
                  << ", Negative Transitions = " << neg_transitions[i] << std::endl;
    }

    return 0;
}
