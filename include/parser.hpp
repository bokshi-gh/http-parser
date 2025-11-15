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

HTTPRequest http_request_parse(const char *raw_request);
