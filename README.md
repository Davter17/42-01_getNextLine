# get_next_line

A C library that reads a line from a file descriptor, returning it one line at a time.

## Overview

`get_next_line` is a project from the 42 school curriculum. It implements a function that reads from a file descriptor and returns one line at a time, handling multiple file descriptors simultaneously through static variables.

## Project Structure

```
gnl/
├── inc/                    # Header files
│   └── get_next_line.h
├── src/                    # Source files
│   ├── get_next_line.c     # Main implementation
│   └── get_next_line_utils.c   # Helper functions
├── test/                   # Test files
│   └── main.c
└── Makefile
```

## Compilation

```bash
make            # Build the library (libgnl.a)
make test       # Build the test binary
make clean      # Remove object files
make fclean     # Remove library and test binary
make re         # Rebuild everything
```

## Usage

```c
#include "get_next_line.h"

int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)))
{
    printf("%s", line);
    free(line);
}
close(fd);
```

### Test Binary

```bash
make test
./gnl_test
```

The test suite includes:
- **Invalid FD**: Tests with fd = -1
- **Empty File**: Tests reading from empty file
- **No Permission**: Tests reading from file without read permissions
- **Short File**: Tests file without newline at end
- **Normal File**: Tests file with 5 lines
- **Long File**: Tests file with 1000 lines
- **Multi-FD**: Tests alternating reads between two files

## API

### `get_next_line(int fd)`

Reads the next line from the file descriptor `fd`.

- **Parameters**: `fd` - File descriptor to read from
- **Returns**: Line that was read, or `NULL` on EOF or error
- **Notes**: 
  - Must free the returned string after use
  - Supports up to `MAX_FD` (1024) simultaneous file descriptors
  - Buffer size configurable via `BUFFER_SIZE` macro (default: 42)

## Helper Functions

| Function | Description |
|----------|-------------|
| `ft_strchr` | Finds first occurrence of character in string |
| `ft_strjoin_and_replace` | Concatenates two strings, frees the first |
| `ft_substr` | Extracts a substring from a string |
| `ft_strdup` | Duplicates a string |

## Configuration

Define `BUFFER_SIZE` before including the header to change the read buffer size:

```c
#define BUFFER_SIZE 1024
#include "get_next_line.h"
```

## Requirements

- Complies with 42 school Norminette standards
- No memory leaks (verified with valgrind)
- Handles edge cases: invalid fd, EOF, empty files, read errors

## License

42 School Project
