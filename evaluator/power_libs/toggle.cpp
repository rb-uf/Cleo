#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include<bits/stdc++.h>


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

struct SignalInfo {
    std::string prevValue;
    std::string nowValue;
};

// Function to process the VCD file
void processVCDFile(std::ifstream &file, const std::string &outputFileName) {
    std::ofstream outputFile(outputFileName);
    outputFile << "TC,HW\n";
    std::map<std::string, SignalInfo> signalDictionary;
    std::string line;
    int HW, HD;


    while (std::getline(file, line)) {
        if (line.find("$var") != std::string::npos) { // variable names found
            std::string signalId;
            std::istringstream iss(line);
            std::string var;
            iss >> var >> var >> var >> signalId;
            signalDictionary[signalId].nowValue = "0"; 
            signalDictionary[signalId].prevValue = "0"; 

        } else if (line[0] == '#') { // New clock cycle found
            HW = 0; 
            HD = 0;

            for (const auto& pair : signalDictionary) {
                // std::cout << "  {\"" << pair.first << "\", " << pair.second.nowValue << "}," << std::endl;
                HW = HW + hammingWeight(pair.second.nowValue);
                HD = HD + hammingDistance(pair.second.nowValue, pair.second.prevValue);
                signalDictionary[pair.first].prevValue = pair.second.nowValue;
            }   

            std::string cycleStr = line.substr(1);
            int cycle = 0;
            try {
                cycle = std::stoi(cycleStr);
            } catch (const std::invalid_argument &e) {
                std::cerr << "Invalid argument: " << e.what() << '\n';
                continue;
            }            
            outputFile << HD << "," << HW << "\n";
        }

        else if (line[0] == 'b') { // multibit variable found
            std::string multbitVal = (line.substr(1)).substr(0, (line.substr(1)).find(' '));
            std::string net = (line.substr(1)).substr((line.substr(1)).find(' ') + 1);
            signalDictionary[net].nowValue = multbitVal;
    
        }
        else if (line[0] == '1' || line[0] == '0') { // singlebit variable found
            std::string bitVal(1, line[0]);
            std::string net = line.substr(1);
            signalDictionary[net].nowValue = bitVal;
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
