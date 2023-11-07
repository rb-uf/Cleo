#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void mergeCSVColumns(const std::string& inputFilePath1, const std::string& inputFilePath2, const std::string& outputFilePath) {
    std::ifstream inputFile1(inputFilePath1);
    std::ifstream inputFile2(inputFilePath2);
    std::ofstream outputFile(outputFilePath);

    if (!inputFile1.is_open() || !inputFile2.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files." << std::endl;
        return;
    }

    std::string line1, line2;
    while (std::getline(inputFile1, line1) && std::getline(inputFile2, line2)) {

        outputFile << line1 << "," << line2 << "\n";

    }

    inputFile1.close();
    inputFile2.close();
    outputFile.close();

    std::cout << "Merged the columns successfully." << std::endl;
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <outputFilePath>" << std::endl;
        return 1;
    }

    std::string outputFilePath = argv[1];

    mergeCSVColumns("actual.csv", "toggle.csv", outputFilePath);

    return 0;
}
