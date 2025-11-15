# HTTP Parser

A lightweight HTTP request and response parser written in C++, capable of parsing HTTP messages, extracting headers, and accessing the message body. Designed for learning, testing, and building simple HTTP clients or servers

## Features

- Parse HTTP requests: method, path, HTTP version, headers, and body.
- Parse HTTP responses: HTTP version, status code, reason phrase, headers, and body.
- Extract specific header values dynamically.
- Works directly on raw HTTP strings.
- Simple, dependency-free, and easy to integrate.

## Getting Started

Check the following files:

- `include/parser.hpp` - class and function definition
- `src/parser.cp` - function implementation
- `src/main.c` - example code demonstrating how to use http parser
