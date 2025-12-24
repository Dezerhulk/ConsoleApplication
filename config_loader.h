#pragma once
#include <string>

struct AppConfig {
    std::string targetUrl;
    std::string fileParam;
};

bool loadConfig(const std::string& path, AppConfig& config);
