#pragma once

#include <string>
#include <map>

using namespace std;

class HTTPRequest {
public:
    string raw;
    string method;
    string path;
    string http_version;
    map<string, string> headers;
    string body;
};

class HTTPResponse {
public:
    string raw;
    string http_version;
    unsigned short int status_code;
    string reason_phrase;
    map<string, string> headers;
    string body;
};

HTTPRequest decode_http_request(const char *raw_request);
HTTPResponse decode_http_response(const char *raw_response);
