#include <stdio.h>
#include "../include/parser.h"

int main() {
    // ---------------- HTTP Request Example ----------------
    const char *raw_request =
        "POST /submit HTTP/1.1\r\n"
        "Host: example.com\r\n"
        "Content-Type: application/json\r\n"
        "Content-Length: 13\r\n\r\n"
        "Hello=World!";

    HTTPRequest req = parseHTTPRequest(raw_request);

    printf("---- HTTP Request ----\n");
    printf("Method: %s\n", req.method);
    printf("Path: %s\n", req.path);
    printf("HTTP Version: %s\n", req.http_version);
    printf("Body: %s\n", req.body);

    char header_value[128];

    if (getHeader(req.raw, "Host", header_value, sizeof(header_value)))
        printf("Host: %s\n", header_value);

    if (getHeader(req.raw, "Content-Type", header_value, sizeof(header_value)))
        printf("Content-Type: %s\n", header_value);

    if (getHeader(req.raw, "Content-Length", header_value, sizeof(header_value)))
        printf("Content-Length: %s\n", header_value);

    // ---------------- HTTP Response Example ----------------
    const char *raw_response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: application/json\r\n"
        "Content-Length: 27\r\n\r\n"
        "{\"status\":\"success\"}";

    HTTPResponse res = parseHTTPResponse(raw_response);

    printf("\n---- HTTP Response ----\n");
    printf("HTTP Version: %s\n", res.http_version);
    printf("Status Code: %u\n", res.status_code);
    printf("Reason Phrase: %s\n", res.reason_phrase);
    printf("Body: %s\n", res.body);

    if (getHeader(res.raw, "Content-Type", header_value, sizeof(header_value)))
        printf("Content-Type: %s\n", header_value);

    if (getHeader(res.raw, "Content-Length", header_value, sizeof(header_value)))
        printf("Content-Length: %s\n", header_value);

    return 0;
}
