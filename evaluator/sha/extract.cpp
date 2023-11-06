#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct Signal {
    std::string name;
    std::string type;
    std::string symbol;
};

int main() {
    std::ifstream vcdFile("obj_dir/sim.vcd"); // Replace with your VCD file name
    std::string line;
    std::vector<Signal> signals;

    if (vcdFile.is_open()) {
        while (std::getline(vcdFile, line)) {
            if (line.find("$var") != std::string::npos) {
                std::istringstream iss(line);
                std::string token;
                Signal signal;
                for (int i = 0; i < 5; ++i) {
                    iss >> token;
                    if (i == 2) {
                        signal.type = token;
                    } else if (i == 3) {
                        signal.symbol = token;
                    } else if (i == 4) {
                        signal.name = token;
                    }
                }
                signals.push_back(signal);
            }
        }
        vcdFile.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    // Printing extracted signal information
    for (const auto& signal : signals) {
        std::cout << "Signal name: " << signal.name << ", Signal type: " << signal.type << ", Signal symbol: " << signal.symbol << std::endl;
    }

    return 0;
}