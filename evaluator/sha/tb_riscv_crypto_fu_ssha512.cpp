#include <verilated.h>
#include "Vriscv_crypto_fu_ssha512.h"
#include <iostream>
#include <vector>
#include "verilated_vcd_c.h"

#include <random>


int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    Vriscv_crypto_fu_ssha512* top = new Vriscv_crypto_fu_ssha512;


    VerilatedVcdC* vcd = new VerilatedVcdC;
    top->trace(vcd, 99);
    vcd->open("trace.vcd");

   // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    

    // Initialize inputs
    top->g_clk = 0;
    top->g_resetn = 0;
    top->valid = 1;
    top->rs1 = 0x1234;
    top->rs2 = 0x5678;
    top->op_ssha512_sum0r = 1;
    top->op_ssha512_sum1r = 0;
    top->op_ssha512_sig0l = 1;
    top->op_ssha512_sig0h = 0;
    top->op_ssha512_sig1l = 1;
    top->op_ssha512_sig1h = 0;
    top->op_ssha512_sig0 = 1;
    top->op_ssha512_sig1 = 0;
    top->op_ssha512_sum0 = 1;
    top->op_ssha512_sum1 = 0;

    // Provide inputs

    // Add your test case code here

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
        std::cout << "Cycle " << i << std::endl;
        std::cout << "Internal Signal Values:" << std::endl;
        std::cout << "  sig0: " << top->riscv_crypto_fu_ssha512__DOT__rv64_ssha512__DOT__ssha512_sig0 << std::endl;
        std::cout << "  sig1: " << top->riscv_crypto_fu_ssha512__DOT__op_ssha512_sig0l << std::endl;

        // Dump the current simulation state
        vcd->dump(i);



    }

    delete top;
    return 0;
}
