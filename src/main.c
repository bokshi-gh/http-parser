#include <stdio.h>
#include <stdlib.h>
#include "../include/parser.h"

int main() {
    // ===== HTTP Request Example =====
    char raw_request[] =
        "GET /index.html HTTP/1.1\r\n"
        "Host: example.com\r\n"
        "User-Agent: curl/7.81.0\r\n"
        "\r\n"
        "body-content-here";

    HTTPRequest req = parseHTTPRequest(raw_request);

    printf("=== HTTP Request ===\n");
    printf("Method: %s\n", req.method);
    printf("Path: %s\n", req.path);
    printf("HTTP Version: %s\n", req.http_version);
    printf("Body: %s\n", req.body);

    char *host = getHeader(raw_request, "Host");
    if (host) {
        printf("Host Header: %s\n", host);
        free(host);
    }

    // ===== HTTP Response Example =====
    char raw_response[] =
        "HTTP/1.1 404 Not Found\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: 23\r\n"
        "\r\n"
        "<h1>Page not found</h1>";

    HTTPResponse res = parseHTTPResponse(raw_response);

    printf("\n=== HTTP Response ===\n");
    printf("HTTP Version: %s\n", res.http_version);
    printf("Status Code: %d\n", res.status_code);
    printf("Reason Phrase: %s\n", res.reason_phrase);
    printf("Body: %s\n", res.body);

    char *ctype = getHeader(raw_response, "Content-Type");
    if (ctype) {
        printf("Content-Type Header: %s\n", ctype);
        free(ctype);
    }

    return 0;
}
