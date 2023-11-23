#include <verilated.h>
#include <verilated_vcd_c.h>


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <random>
#include <stdint.h>
#include <bitset>

#define NUM_CYCLES 50000

// Random number generator

// Function to generate a random 64-bit number with a specific Hamming weight
template <typename T>
T distHw(int weight, std::mt19937_64& gen) {
    T result = 0;
    constexpr int bitWidth = sizeof(T) * 8;
    for (int i = 0; i < weight; ++i) {
        int bitPosition = std::uniform_int_distribution<int>(0, bitWidth - 1 - i)(gen);
        result |= (T(1) << bitPosition);
    }
    return result;
}

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
    tfp->open("obj_dir/sim.vcd"); // Open the VCD file

    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    std::mt19937_64 generator(std::random_device{}());
    std::uniform_int_distribution<uint64_t> dis64(0,64);
    std::uniform_int_distribution<uint64_t> dis32(0,32);
    std::uniform_int_distribution<uint64_t> dis4(0,4);    
    std::uniform_int_distribution<uint64_t> dis2(0,2);
    
    // Open a CSV file for writing
    std::ofstream outputFile("actual.csv");
    ADD_HEADER_TO_CSV();
    outputFile << "0" << std::endl; // Align the inputs with outputs
    // Simulate for N clock cycles
    for (int i = 0; i < NUM_CYCLES; i++) {
        // Assign random values to inputs
        SET_RAND_VALS();

        // Evaluate the module
        top->eval();

        // Dump VCD values
        tfp->dump(i); 
        
        // Save rs1 and rs2 values to the CSV file
        ADD_ROW_TO_CSV();
    }

    // Close the VCD file and cleanup
    tfp->close();
    delete tfp;

    // Delete the module and return success
    delete top;
    return 0;
}
