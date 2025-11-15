#include <iostream>
#include "http_codec.hpp"

int main() {
    const char* raw_request =
        "POST /submit HTTP/1.1\r\n"
        "Host: example.com\r\n"
        "User-Agent: MyClient/1.0\r\n"
        "Content-Type: text/plain\r\n"
        "\r\n"
        "This is the body of the request.\nIt can be multiple lines.";

    // Parse the HTTP request
    HTTPRequest request = decode_http_request(raw_request);

    // Print request line
    std::cout << "Method: " << request.method << "\n";
    std::cout << "Path: " << request.path << "\n";
    std::cout << "HTTP Version: " << request.http_version << "\n\n";

    // Print headers
    std::cout << "Headers:\n";
    for (const auto& [key, value] : request.headers) {
        std::cout << key << ": " << value << "\n";
    }

    // Print body
    std::cout << "\nBody:\n" << request.body << "\n";

    return 0;
}
