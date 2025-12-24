#include "config_loader.h"
#include <fstream>
#include <iostream>

bool loadConfig(const std::string& path, AppConfig& config) {
    std::ifstream f(path);
    if (!f.is_open()) return false;
    std::getline(f, config.targetUrl);
    std::getline(f, config.fileParam);
    return true;
}
