#include "../include/parser.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

HTTPRequest parseHTTPRequest(const char *raw_request) {
    HTTPRequest req;
    memset(&req, 0, sizeof(req));

    strncpy(req.raw, raw_request, sizeof(req.raw) - 1);

    char raw_copy[MAX_RAW];
    strncpy(raw_copy, raw_request, sizeof(raw_copy) - 1);
    char *request_line = strtok(raw_copy, "\r\n");
    if (request_line) {
        char *method = strtok(request_line, " ");
        char *path = strtok(NULL, " ");
        char *version = strtok(NULL, " ");

        if (method)     strncpy(req.method, method, sizeof(req.method) - 1);
        if (path)       strncpy(req.path, path, sizeof(req.path) - 1);
        if (version)    strncpy(req.http_version, version, sizeof(req.http_version) - 1);
    }

    char *header_end = strstr(raw_request, "\r\n\r\n");
    if (header_end) {
        char *body_start = header_end + 4;
        strncpy(req.body, body_start, sizeof(req.body) - 1);
    }

    return req;
}

HTTPResponse parseHTTPResponse(const char *raw_response) {
    HTTPResponse res;
    memset(&res, 0, sizeof(res));

    strncpy(res.raw, raw_response, sizeof(res.raw) - 1);

    char raw_copy[MAX_RAW];
    strncpy(raw_copy, raw_response, sizeof(raw_copy) - 1);

    char *response_line = strtok(raw_copy, "\r\n");
    if (response_line) {
        char *version = strtok(response_line, " ");
        char *status_code_str = strtok(NULL, " ");
        char *reason_phrase = strtok(NULL, "");

        if (version) strncpy(res.http_version, version, sizeof(res.http_version) - 1);
        if (status_code_str) res.status_code = (unsigned short)atoi(status_code_str);
        if (reason_phrase) strncpy(res.reason_phrase, reason_phrase, sizeof(res.reason_phrase) - 1);
    }

    char *header_end = strstr(raw_response, "\r\n\r\n");
    if (header_end) {
        char *body_start = header_end + 4;
        strncpy(res.body, body_start, sizeof(res.body) - 1);
    }

    return res;
}

int getHeader(const char *raw, const char *name, char *out_value, size_t max_len) {
    char *header_line = strstr((char *)raw, name);
    if (!header_line) return 0;

    char *colon = strchr(header_line, ':');
    if (!colon) return 0;

    char *value_start = colon + 1;
    while (*value_start == ' ') value_start++;

    char *value_end = strstr(header_line, "\r\n");
    if (!value_end) return 0;

    size_t value_len = value_end - value_start;
    if (value_len >= max_len) value_len = max_len - 1;

    strncpy(out_value, value_start, value_len);
    out_value[value_len] = '\0';
    return 1;
}
