#include "../include/parser.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

HTTPRequest parseHTTPRequest(char *raw_request) {
  HTTPRequest parsed_request = {.raw = raw_request};

  char *request_line = strtok(raw_request, "\r\n");
  if (!request_line)
    return parsed_request;

  parsed_request.method = strtok(request_line, " ");
  parsed_request.path = strtok(NULL, " ");
  parsed_request.http_version = strtok(NULL, " ");

  char *header_end = strstr(raw_request, "\r\n\r\n");
  if (header_end)
    parsed_request.body = header_end + 4; // body starts after \r\n\r\n
  else
    parsed_request.body = NULL;

  return parsed_request;
}

HTTPResponse parseHTTPResponse(char *raw_response) {
  HTTPResponse parsed_response = {.raw = raw_response};

  char *response_line = strtok(raw_response, "\r\n");
  if (!response_line)
    return parsed_response;

  parsed_response.http_version = strtok(response_line, " ");
  char *status_code_str = strtok(NULL, " ");
  if (status_code_str)
    parsed_response.status_code = atoi(status_code_str);

  char *reason_phrase = strtok(NULL, "");
  parsed_response.reason_phrase = reason_phrase; // rest of line

  char *header_end = strstr(raw_response, "\r\n\r\n");
  if (header_end)
    parsed_response.body = header_end + 4;
  else
    parsed_response.body = NULL;

  return parsed_response;
}

char *getHeader(char *raw, char *name) {
  char *header_line = strstr(raw, name);
  if (!header_line)
    return NULL;

  char *colon = strchr(header_line, ':');
  if (!colon)
    return NULL;

  char *value_start = colon + 1;
  while (*value_start == ' ')
    value_start++;

  char *value_end = strstr(header_line, "\r\n");
  if (!value_end)
    return NULL;

  size_t value_len = value_end - value_start;
  char *value = (char *)malloc(value_len + 1);
  if (!value)
    return NULL;

  strncpy(value, value_start, value_len);
  value[value_len] = '\0';

  return value;
}
