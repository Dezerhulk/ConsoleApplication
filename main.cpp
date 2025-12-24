#include <iostream>
#include <map>
#include "uploader.h"
#include "scanner.h"
#include "config_loader.h"

int main() {
    std::cout << "FileUploadScanner demo" << std::endl;
    AppConfig cfg;
    if (!loadConfig("config/config.txt", cfg)) {
        cfg.targetUrl = "http://localhost/upload.php";
        cfg.fileParam = "file";
    }
    Uploader up;
    Scanner sc;
    std::map<std::string, std::string> extra;
    extra["submit"] = "Upload";
    if (up.uploadFile(cfg.targetUrl, cfg.fileParam, "test.txt", extra)) {
        sc.analyzeServerResponse("OK");
    }
    return 0;
}
