#pragma once
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_RAW 8192
#define MAX_METHOD 16
#define MAX_PATH 256
#define MAX_VERSION 16
#define MAX_BODY 4096
#define MAX_REASON 128

typedef struct {
    char raw[MAX_RAW];
    char method[MAX_METHOD];
    char path[MAX_PATH];
    char http_version[MAX_VERSION];
    char body[MAX_BODY];
} HTTPRequest;

typedef struct {
    char raw[MAX_RAW];
    char http_version[MAX_VERSION];
    unsigned short status_code;
    char reason_phrase[MAX_REASON];
    char body[MAX_BODY];
} HTTPResponse;

HTTPRequest parseHTTPRequest(const char *raw_request);
HTTPResponse parseHTTPResponse(const char *raw_response);
int getHeader(const char *raw, const char *name, char *out_value, size_t max_len);
