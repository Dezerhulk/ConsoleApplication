
#include <iostream>
#include "scanner.h"
#include "uploader.h"

int main() {
    std::cout << "FileUploadScanner v2\n";

    scanDirectory("./test_scan");

    uploadFile(
        "http://localhost/upload.php",
        "file",
        "test_scan/test.php"
    );

    return 0;
}
