#include "parser.h"
#include <string.h>

HTTPRequest parseHTTPRequest(char *raw) {
  HTTPRequest parsed_request = {.raw = raw};

  char *saveptr1;
  char *request_line = strtok_r(raw, "\r\n", &saveptr1);

  char *saveptr2;
  char *method = strtok_r(request_line, " ", &saveptr2);
  parsed_request.method = method;
  parsed_request.path = strtok_r(NULL, " ", &saveptr2);
  parsed_request.http_version = strtok_r(NULL, " ", &saveptr2);

  parsed_request.header_count = 0;
  char *header_line;
  while ((header_line = strtok_r(NULL, "\r\n", &saveptr1))) {
    if (header_line[0] == '\0') {     // empty line = end of headers
      parsed_request.body = saveptr1;
      break;
    }

    char *colon = strchr(header_line, ':');
    if (!colon)
      continue;

    *colon = '\0';
    char *name = header_line;
    char *value = colon + 1;
    while (*value == ' ')
      value++; // trim leading spaces

    strncpy(parsed_request.headers[parsed_request.header_count].name, name,
            MAX_NAME - 1);
    parsed_request.headers[parsed_request.header_count].name[MAX_NAME - 1] =
        '\0';

    strncpy(parsed_request.headers[parsed_request.header_count].value, value,
            MAX_VALUE - 1);
    parsed_request.headers[parsed_request.header_count].value[MAX_VALUE - 1] =
        '\0';

    parsed_request.header_count++;
  }

  return parsed_request;
}

char *getHeader(HTTPRequest *request, const char *name) {
  for (int i = 0; i < request->header_count; i++) {
    if (strcasecmp(request->headers[i].name, name) == 0)
      return request->headers[i].value;
  }
  return NULL;
}
