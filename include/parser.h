#pragma once
#define MAX_HEADERS 32
#define MAX_NAME 64
#define MAX_VALUE 256

typedef struct {
    char name[MAX_NAME];
    char value[MAX_VALUE];
} Header;

typedef struct {
    char *raw;
    char *method;
    char *path;
    char *http_version;
    char *body;
    Header headers[MAX_HEADERS];
    int header_count;
} HTTPRequest;

HTTPRequest parseHTTPRequest(char *raw);
char* getHeader(HTTPRequest *request, const char *name);
