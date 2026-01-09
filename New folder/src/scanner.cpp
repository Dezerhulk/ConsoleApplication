
#include "scanner.h"
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

bool isDangerous(const std::string& line) {
    return line.find("system(") != std::string::npos ||
           line.find("strcpy") != std::string::npos ||
           line.find("../") != std::string::npos;
}

void scanDirectory(const char* path) {
    std::cout << "[SCAN] Directory: " << path << "\n";

    for (auto& p : fs::recursive_directory_iterator(path)) {
        if (p.path().extension() == ".cpp" || p.path().extension() == ".php") {
            std::ifstream file(p.path());
            std::string line;
            int ln = 0;

            while (std::getline(file, line)) {
                ln++;
                if (isDangerous(line)) {
                    std::cout << "[WARNING] "
                              << p.path() << ":" << ln << "\n";
                }
            }
        }
    }
}
