#include "../include/parser.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

HTTPRequest parseHTTPRequest(char *raw_request){
	HTTPRequest parsed_request = { .raw = raw_request };

	char *request_line = strtok(raw_request, "\r\n");
	parsed_request.method = strtok(request_line, " ");
	parsed_request.path = strtok(NULL, " ");
	parsed_request.http_version = strtok(NULL, " ");

	char *header_end = strstr(raw_request, "\r\n\r\n");
	char *body_start = header_end + 4;

	parsed_request.body = body_start;

	return parsed_request;
}

char* getHeader(char *raw, char *name){
	char *header_line = strstr(raw, name);

	if(header_line == NULL) return NULL;

	char *colon = strchr(header_line, ':');
	char *value_start = colon + 1;
	while (*value_start == ' ') value_start++;
	char *value_end = strstr(header_line, "\r\n");
	size_t value_len = value_start - value_end;

	char *value = (char*)malloc(value_len + 1);
	if (value == NULL) return NULL;

	strncpy(value, value_start, value_len);
	value[value_len] = '\0';

	return value;
}
