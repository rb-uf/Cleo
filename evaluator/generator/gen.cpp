#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <random>
#include <stdint.h>
#include <bitset>

#define TEST 500

// Random number generator

// Function to generate a random 64-bit number with a specific Hamming weight
uint64_t dist64hw(int weight, std::mt19937_64& gen) {
    std::uniform_int_distribution<uint64_t> dist(0, std::numeric_limits<uint64_t>::max());

    uint64_t result = 0;
    for (int i = 0; i < weight; ++i) {
        int bitPosition = std::uniform_int_distribution<int>(0, 63 - i)(gen);
        result |= (1ULL << bitPosition);
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


    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());


    std::mt19937_64 generator(std::random_device{}());
    std::uniform_int_distribution<uint64_t> dis64(0,64);
    std::uniform_int_distribution<uint64_t> randoms(0, ((uint64_t)1 << 64) - 1);

    // Open a CSV file for writing
    std::ofstream outputFile("generator.csv");
    outputFile << "hw(random), hw(HWGEN)" << std::endl;

    // Simulate for N clock cycles
    for (int i = 0; i < TEST; i++) {
        outputFile << hammingWeight(randoms(gen)) << "," <<  hammingWeight(dist64hw(dis64(gen), generator)) << std::endl;
    }



    return 0;
}
