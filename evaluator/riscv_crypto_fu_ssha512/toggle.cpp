#include <iostream>
#include <fstream>
#include <map>
#include <string>


// Function to calculate the Hamming distance between two strings
int hammingDistance(const std::string &str1, const std::string &str2) {
    int count = 0;
    for (size_t i = 0; i < str1.size(); ++i) {
        if (str1[i] != str2[i]) {
            count++;
        }
    }
    return count;
}

// Function to compute the Hamming weight of a string
int hammingWeight(const std::string &str) {
    int weight = 0;
    for (char c : str) {
        if (c == '1') {
            weight++;
        }
    }
    return weight;
}

// Function to process the VCD file
void processVCDFile(std::ifstream &file, const std::string &outputFileName) {
    std::ofstream outputFile(outputFileName);
    outputFile << "Cycle,ToggleCount,HammingWeight\n";

    std::string line;
    std::map<std::string, std::string> signalValues;
    std::map<std::string, int> toggleCounts;
    std::map<std::string, int> hammingWeights;

    while (std::getline(file, line)) {
        if (line.find("$var") != std::string::npos) {
            std::string signalId;
            file >> signalId;
            signalId = signalId.substr(1); // Remove the '#' from the signal ID
            signalValues[signalId] = "";
            toggleCounts[signalId] = 0;
            hammingWeights[signalId] = 0;
        } else if (line[0] == '#') {
            std::string cycleStr = line.substr(1);
            int cycle = 0;
            try {
                cycle = std::stoi(cycleStr);
            } catch (const std::invalid_argument &e) {
                std::cerr << "Invalid argument: " << e.what() << '\n';
                continue;
            }
            for (auto &signal : signalValues) {
                std::string value;
                file >> value;
                if (!signal.second.empty()) {
                    toggleCounts[signal.first] += hammingDistance(signal.second, value);
                    hammingWeights[signal.first] += hammingWeight(value);
                }
                signalValues[signal.first] = value;
            }
            for (const auto &signalId : signalValues) {
                outputFile << cycle << "," << toggleCounts[signalId.first] << "," << hammingWeights[signalId.first] << "\n";
            }
        }
    }
    outputFile.close();
}

int main() {
    std::ifstream file("obj_dir/sim.vcd"); // Replace "example.vcd" with your VCD file's name
    if (file.is_open()) {
        processVCDFile(file, "toggle.csv");
        file.close();
    } else {
        std::cerr << "Unable to open file";
    }
    return 0;
}
