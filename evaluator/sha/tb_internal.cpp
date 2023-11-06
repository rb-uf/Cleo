#include <verilated.h>
#include "Vriscv_crypto_fu_ssha512.h"

#include <verilated_vcd_c.h>

#include <iostream>
#include <vector>
#include <string>
#include <random>

#define MODULENAME "riscv_crypto_fu_ssha512"

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

     Verilated::traceEverOn(true); // Enable VCD tracing


    // Instantiate the module
    Vriscv_crypto_fu_ssha512 *top = new Vriscv_crypto_fu_ssha512;

    // Initialize VCD trace
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99); // Trace 99 levels of hierarchy
    tfp->open("sim.vcd"); // Open the VCD file

    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);
    

    // Simulate for 100 clock cycles
    for (int i = 0; i < 10; i++) {
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

        // Dump VCD values
        tfp->dump(i); 


        // Print internal signal values
        std::cout << "Cycle " << i << std::endl;
        std::cout << "Internal Signal Values:" << std::endl;
        std::cout << "  sig0: " << top->riscv_crypto_fu_ssha512__DOT__rv64_ssha512__DOT__ssha512_sig0 << std::endl;
        std::cout << "  sig1: " << top->riscv_crypto_fu_ssha512__DOT__op_ssha512_sig0l << std::endl;


 

    }

    // Close the VCD file and cleanup
    tfp->close();
    delete tfp;

    // Delete the module and return success
    delete top;
    return 0;
}
