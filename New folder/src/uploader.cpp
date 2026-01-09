
#include "uploader.h"
#include <curl/curl.h>
#include <iostream>

bool uploadFile(const char* url, const char* field, const char* filename) {
    CURL* curl = curl_easy_init();
    if (!curl) return false;

    curl_mime* mime = curl_mime_init(curl);
    curl_mimepart* part = curl_mime_addpart(mime);

    curl_mime_name(part, field);
    curl_mime_filedata(part, filename);

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_MIMEPOST, mime);

    CURLcode res = curl_easy_perform(curl);

    curl_mime_free(mime);
    curl_easy_cleanup(curl);

    std::cout << "[UPLOAD] Status: " << res << "\n";
    return res == CURLE_OK;111111
}
