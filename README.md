See [subject](https://github.com/cariestevez/get_next_line/blob/main/get_next_line.en.subject.pdf)

# ↪︎ get_next_line
Function capable of reading a line of text from a file descriptor, one line at a time, regardless of the size of the lines or the content. This function handles different edge cases, such as varying buffer sizes, multiple file descriptors, and incomplete lines.

## Project Overview:
- Functionality: It reads a line from a file descriptor and returns it as a string. Able to handle multiple consecutive calls, returning the next line each time until the end of the file (EOF) is reached.
- Buffer Management: The function uses a buffer to store the data read from the file descriptor. It handles cases where a line is longer than the buffer size or where a line is split across multiple reads.
- Memory Management: Proper memory allocation and management are crucial to ensure that the function does not leak memory or access invalid memory. The function dynamically allocates and frees memory as needed while maintaining efficient performance.
## Bonus:
- Multi-File Handling: It manages multiple file descriptors simultaneously, allowing it to read from different files or inputs without mixing the data.

## Key Concepts:
- File Descriptors: Understanding how to work with file descriptors in Unix/Linux, including standard input/output and file I/O.
- Dynamic Memory Allocation: Efficiently managing memory for variable-length strings and buffers.
- Edge Case Handling: Addressing various edge cases, such as empty lines, files ending without a newline character, and handling of large files.

## Technologies:
- Programming Language: C
- Operating System: Unix/Linux
- File I/O: Low-level file handling using read(), open(), and close() system calls.

It could be considered a reinterpretation of the original C functions fgets or getline.


