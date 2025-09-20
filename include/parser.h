#pragma once

typedef struct {
	char *raw;
	char *method;
	char *path;
	char *http_version;
	char *body;
	
} HTTPRequest;

HTTPRequest parseHTTPRequest(char *raw_request);
HTTPRequest parseHTTPResponse(char *raw_response);
char* getHeader(char *raw, char *name);

