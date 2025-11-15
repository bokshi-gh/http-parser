#include "parser.hpp"
#include <cstring>
#include <string>

HTTPRequest http_request_parse(const char* raw_request) {
    HTTPRequest request;
    request.raw = raw_request;

    size_t len = std::strlen(raw_request) + 1;
    char* buffer = new char[len];
    std::strcpy(buffer, raw_request);

    char* line = strtok(buffer, "\r\n");
    if (line) {
        char* token = strtok(line, " ");
        if (token) request.method = token;

        token = strtok(nullptr, " ");
        if (token) request.path = token;

        token = strtok(nullptr, " ");
        if (token) request.http_version = token;
    }

    while ((line = strtok(nullptr, "\r\n")) != nullptr) {
        if (line[0] == '\0') {
            // Empty line → body starts
            break;
        }
        std::string header_line(line);
        size_t colon_pos = header_line.find(':');
        if (colon_pos != std::string::npos) {
            std::string key = header_line.substr(0, colon_pos);
            std::string value = header_line.substr(colon_pos + 1);
            size_t first = value.find_first_not_of(" ");
            if (first != std::string::npos)
                value = value.substr(first);
            request.headers[key] = value;
        }
    }

    // everything after empty line
    char* body = strtok(nullptr, ""); // remaining string
    if (body) {
        request.body = body;
    }

    delete[] buffer;
    return request;
}
