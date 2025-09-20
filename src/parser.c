#include "../include/parser.h"
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
