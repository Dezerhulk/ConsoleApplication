#include "uploader.h"
#include <iostream>

bool Uploader::uploadFile(const std::string& url,
                          const std::string& fileParam,
                          const std::string& filePath,
                          const std::map<std::string, std::string>& extraParams) {
    std::cout << "[Uploader] Target URL: " << url << std::endl;
    std::cout << "[Uploader] File param: " << fileParam << std::endl;
    std::cout << "[Uploader] File path: " << filePath << std::endl;
    for (const auto& p : extraParams) {
        std::cout << "[Uploader] Extra param: " << p.first << "=" << p.second << std::endl;
    }
    std::cout << "[Uploader] (Demo) File sent successfully" << std::endl;
    return true;
}
