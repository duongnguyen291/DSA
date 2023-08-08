#include <iostream>
#include <fstream>
#include <string>

int main() {
    int a, b;
    std::ifstream inputFile("testcase.txt");
    std::ofstream outputFile("test1.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cout << "Failed to open files." << std::endl;
        return 1;
    }

    std::string line;
    int lineNumber = 1;

    std::cout << "Enter starting line (a): ";
    std::cin >> a;
    std::cout << "Enter ending line (b): ";
    std::cin >> b;

    while (std::getline(inputFile, line)) {
        if (lineNumber >= a && lineNumber <= b) {
            outputFile << line << std::endl;
        }
        lineNumber++;

        if (lineNumber > b) {
            break;
        }
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Lines from " << a << " to " << b << " copied to 2.txt." << std::endl;

    return 0;
}
