#include <iostream>
#include "http_codec.hpp"

using namespace std;

int main() {
    // Build HTTPRequest object
    HTTPRequest req;
    req.method = "POST";
    req.path = "/api/data";
    req.version = "HTTP/1.1";
    req.headers["Host"] = "example.com";
    req.headers["Content-Type"] = "application/json";
    req.headers["Content-Length"] = "27";
    req.body = R"({"name":"Alice","age":30})";  // JSON body

    // Encode HTTPRequest to string
    string raw_request = encode_http_request(req);
    cout << "Encoded HTTP Request:\n" << raw_request << "\n";

    // Decode HTTPRequest back from string
    HTTPRequest decoded_req = decode_http_request(raw_request.c_str());
    cout << "\nDecoded HTTP Request:" << endl;
    cout << "Method: " << decoded_req.method << endl;
    cout << "Path: " << decoded_req.path << endl;
    cout << "Version: " << decoded_req.version << endl;
    cout << "Headers:" << endl;
    for (const auto &h : decoded_req.headers) {
        cout << h.first << ": " << h.second << endl;
    }
    cout << "Body: " << decoded_req.body << endl;

    return 0;
}
