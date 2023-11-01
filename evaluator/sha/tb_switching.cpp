#include <verilated.h>
#include "Vriscv_crypto_fu_ssha512.h"

#include <iostream>
#include <vector>
#include <random>

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    // Instantiate the module
    Vriscv_crypto_fu_ssha512 *top = new Vriscv_crypto_fu_ssha512;

    // Get the internal scope
    const std::vector<VerilatedSignal *> &signals = top->getInternalScope();

    // Store the names of all wires and registers
    std::vector<std::string> signalList;
    for (const auto &signal : signals) {
        signalList.push_back(signal->getName());
    }

    // Initialize arrays for transition counts
    std::vector<int> transition_0_to_1(signalList.size(), 0);
    std::vector<int> transition_1_to_0(signalList.size(), 0);

    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    // Initialize inputs
    top->g_clk = 0;
    top->g_resetn = 0;
    top->valid = 0;
    top->rs1 = 0;
    top->rs2 = 0;
    top->op_ssha512_sum0r = 0;
    top->op_ssha512_sum1r = 0;
    top->op_ssha512_sig0l = 0;
    top->op_ssha512_sig0h = 0;
    top->op_ssha512_sig1l = 0;
    top->op_ssha512_sig1h = 0;
    top->op_ssha512_sig0 = 0;
    top->op_ssha512_sig1 = 0;
    top->op_ssha512_sum0 = 0;
    top->op_ssha512_sum1 = 0;

    // Reset
    top->g_resetn = 0;
    top->eval();
    top->g_resetn = 1;

    // Simulate for 100 clock cycles
    for (int i = 0; i < 100; i++) {
        // Assign random values to inputs
        top->valid = dis(gen);
        top->rs1 = dis(gen);
        top->rs2 = dis(gen);
        top->op_ssha512_sum0r = dis(gen);
        top->op_ssha512_sum1r = dis(gen);
        top->op_ssha512_sig0l = dis(gen);
        top->op_ssha512_sig0h = dis(gen);
        top->op_ssha512_sig1l = dis(gen);
        top->op_ssha512_sig1h = dis(gen);
        top->op_ssha512_sig0 = dis(gen);
        top->op_ssha512_sig1 = dis(gen);
        top->op_ssha512_sum0 = dis(gen);
        top->op_ssha512_sum1 = dis(gen);

        // Access internal signals
        top->valid = 1;
        top->eval();

        // Record switching activities
        for (int j = 0; j < signalList.size(); j++) {
            bool prev_value = top->top__DOT__u_riscv_crypto_fu_ssha512->*(Verilated::getpValue(signalList[j].c_str()));
            bool current_value = top->top__DOT__u_riscv_crypto_fu_ssha512->*(Verilated::getpValue(signalList[j].c_str()));
            if (prev_value == 0 && current_value == 1) {
                transition_0_to_1[j]++;
            } else if (prev_value == 1 && current_value == 0) {
                transition_1_to_0[j]++;
            }
        }

        top->valid = 0;
        top->eval();
    }

    // Print switching activity details
    for (int j = 0; j < signalList.size(); j++) {
        std::cout << "Signal: " << signalList[j] << std::endl;
        std::cout << "Transitions from 0 to 1: " << transition_0_to_1[j] << std::endl;
        std::cout << "Transitions from 1 to 0: " << transition_1_to_0[j] << std::endl;
    }

    // Delete the module and return success
    delete top;
    return 0;
}