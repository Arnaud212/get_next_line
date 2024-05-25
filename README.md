# Get Next Line

## Summary

This project involves developing a `get_next_line` function that reads a line from a file descriptor (fd). The goal is to handle line-by-line reading efficiently while adhering to certain memory management and C code constraints.

## Compilation

Your program should be compiled with `-D BUFFER_SIZE=n` to specify the buffer size. Here is an example of compilation:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o get_next_line
```

## Usage

To use the `get_next_line` function, include the header and source files in your project and compile with the `BUFFER_SIZE` flag. Here is an example usage:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while (get_next_line(fd, &line) > 0) {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return 0;
}
```
In this example, the program reads and prints each line from a file named `file.txt`.