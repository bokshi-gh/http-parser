# HTTP Codec

A simple C++ library for encoding and decoding HTTP requests and responses.  
It provides structured classes for `HTTPRequest` and `HTTPResponse` and functions to convert between raw HTTP strings and structured objects.

## Features

- Encode `HTTPRequest` / `HTTPResponse` into raw HTTP strings.
- Decode raw HTTP strings into structured `HTTPRequest` / `HTTPResponse`.
- Handles optional headers and body safely.
- Compatible with HTTP/1.1 request and response formats.

## Getting Started

The project includes the following files:

- `include/http_codec.hpp` - Class definitions and function declarations.
- `src/http_codec.cpp` - Implementation of encoding and decoding functions.
- `src/main.cpp` - Example code demonstrating how to build, encode, and decode HTTP requests and responses.
