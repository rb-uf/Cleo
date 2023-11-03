#include <verilated.h>
#include "Vriscv_crypto_fu_ssha512.h"

#include <iostream>
#include <vector>
#include <string>
#include <random>

#define MODULENAME "riscv_crypto_fu_ssha512"

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    // Instantiate the module
    Vriscv_crypto_fu_ssha512 *top = new Vriscv_crypto_fu_ssha512;

    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    
    // Parse the header file to extract the local signals
    std::ifstream headerFile("Vriscv_crypto_fu_ssha512.h");
    std::string line;
    bool readSignals = false;
    std::vector<std::string> localSignals;

    while (std::getline(headerFile, line)) {
        if (line.find("// LOCAL SIGNALS") != std::string::npos) {
            readSignals = true;
            continue;
        }
        if (line.find("// LOCAL VARIABLES") != std::string::npos) {
            break;
        }
        if (readSignals && line.find("DATA") != std::string::npos) {
            std::string signal = line.substr(line.find("riscv_crypto_fu_ssha512") + 26);
            signal.erase(0, signal.find_first_not_of(' '));
            signal.erase(signal.find_last_not_of(' ') + 1);
            localSignals.push_back(signal);
        }
    }

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

        // Print internal signal values
        // std::cout << "Cycle " << i << std::endl;
        // std::cout << "Internal Signal Values:" << std::endl;
        // std::cout << "  sig0: " << top->riscv_crypto_fu_ssha512__DOT__rv64_ssha512__DOT__ssha512_sig0 << std::endl;
        // std::cout << "  sig1: " << top->riscv_crypto_fu_ssha512__DOT__op_ssha512_sig0l << std::endl;


        // Print local signal values
        std::cout << "Cycle " << i << std::endl;
        std::cout << "Local Signal Values:" << std::endl;
        for (const auto &signal : localSignals) {
            if (signal.find("riscv_crypto_fu_ssha512__DOT__") == std::string::npos) {
                std::cout << "  " << signal << ": " << top->getSignalByName(signal.c_str()) << std::endl;
            } else {
                std::cout << "  " << signal << ": " << top->eval(signal.c_str()) << std::endl;
            }
        }

    }

    // Delete the module and return success
    delete top;
    return 0;
}
