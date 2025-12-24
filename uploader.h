#pragma once
#include <string>
#include <map>

class Uploader {
public:
    bool uploadFile(const std::string& url,
                    const std::string& fileParam,
                    const std::string& filePath,
                    const std::map<std::string, std::string>& extraParams);
};
