#include <verilated.h>


#include <verilated_vcd_c.h>

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <random>

// Function to calculate the Hamming weight of a value
int hammingWeight(uint64_t value) {
    int weight = 0;
    while (value > 0) {
        weight += value & 1;
        value >>= 1;
    }
    return weight;
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

     Verilated::traceEverOn(true); // Enable VCD tracing


    // Instantiate the module
    MODULENAME *top = new MODULENAME;

    // Initialize VCD trace
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99); // Trace 99 levels of hierarchy
    tfp->open("sim.vcd"); // Open the VCD file

    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);


    std::mt19937_64 generator(std::random_device{}());
    std::uniform_int_distribution<uint64_t> dis64(0, ((uint64_t)1 << 64) - 1);

    
    // Open a CSV file for writing
    std::ofstream outputFile("../actual.csv");
    outputFile << "rs1 input" << "," << "rs2 input" << "," << "hw(rs1)" << "," << "hw(rs2)" << std::endl;

    // Simulate for 100 clock cycles
    for (int i = 0; i < 10; i++) {
        // Assign random values to inputs
        top->valid = dis(gen);
        top->rs1 = dis64(gen);
        top->rs2 = dis64(gen);
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
        
        // Calculate Hamming weight and distance
        int hw_rs1 = hammingWeight(top->rs1);
        int hw_rs2 = hammingWeight(top->rs2);

        // Save rs1 and rs2 values to the CSV file
        outputFile << top->rs1 << "," << top->rs2 << "," << hw_rs1 << "," << hw_rs2 << std::endl;



 

    }

    // Close the VCD file and cleanup
    tfp->close();
    delete tfp;

    // Delete the module and return success
    delete top;
    return 0;
}
