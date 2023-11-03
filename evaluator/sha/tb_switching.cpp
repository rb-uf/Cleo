#include <verilated.h>
#include "Vriscv_crypto_fu_ssha512.h"

#include <iostream>
#include <vector>
#include <random>

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    // Instantiate the module
    Vriscv_crypto_fu_ssha512 *top = new Vriscv_crypto_fu_ssha512;

    // Get the list of signals
    std::vector<std::string> signalList = {
        "valid",
        "rs1",
        "rs2",
        "op_ssha512_sum0r",
        "op_ssha512_sum1r",
        "op_ssha512_sig0l",
        "op_ssha512_sig0h",
        "op_ssha512_sig1l",
        "op_ssha512_sig1h",
        "op_ssha512_sig0",
        "op_ssha512_sig1",
        "op_ssha512_sum0",
        "op_ssha512_sum1"
    };

    // Initialize arrays for transition counts
    std::vector<int> transition_0_to_1(signalList.size(), 0);
    std::vector<int> transition_1_to_0(signalList.size(), 0);

    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

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

        // Evaluate the module
        top->eval();

        // Record switching activities
        for (int j = 0; j < signalList.size(); j++) {
            bool prev_value = 0; // Assuming initial value is 0
            bool current_value = dis(gen); // Generate a random value

            if (prev_value == 0 && current_value == 1) {
                transition_0_to_1[j]++;
            } else if (prev_value == 1 && current_value == 0) {
                transition_1_to_0[j]++;
            }
        }
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