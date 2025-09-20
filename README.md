# HTTP Parser

A lightweight HTTP request and response parser written in C, capable of parsing HTTP messages, extracting headers, and accessing the message body. Designed for learning, testing, and building simple HTTP clients or servers

## Features

- Parse HTTP requests: method, path, HTTP version, headers, and body.
- Parse HTTP responses: HTTP version, status code, reason phrase, headers, and body.
- Extract specific header values dynamically.
- Works directly on raw HTTP strings.
- Simple, dependency-free, and easy to integrate.

## Installation

1. Clone the repository:
```bash
git clone https://github.com/bokshi-gh/http-parser.git
cd http-parser
```

2. Compile and Run:
```bash
gcc -o main -Iinclude/ src/main.c src/parser.c
./main
```

## Usage

Example usage is provided in **`src/main.c`**. Simply check/run `src/main.c` to see the use case.
