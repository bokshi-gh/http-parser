#pragma once

typedef struct {
	char *raw;
	char *method;
	char *path;
	char *http_version;
	char *body;
	
} HTTPRequest;

typedef struct {
	char *raw;
	char *http_version;
	char *status_code;
	char *reason_phrase;
	char *body;
	
} HTTPResponse;


HTTPRequest parseHTTPRequest(char *raw_request);
HTTPResponse parseHTTPResponse(char *raw_response);
char* getHeader(char *raw, char *name);

