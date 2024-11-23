# Mini-LibC

Mini-LibC is a reimplementation of the standard C library (`libc`) for Linux systems. Designed to replace the system `libc` (such as `glibc`) in basic scenarios, Mini-LibC provides essential string manipulation, memory management, and file I/O functionality directly on top of the Linux syscall interface.

This project is a great opportunity to explore low-level programming, understand the interaction between user applications and the kernel, and build a freestanding library from scratch.

---

## Objectives

- **Understand the C Standard Library**: Learn how core functionality like string manipulation, memory allocation, and file I/O are implemented at the system level.
- **Work with Syscalls**: Accommodate with Linux's syscall interface on the x86_64 architecture.
- **Deep Dive into Memory and Strings**: Implement string and memory management utilities from scratch.
- **Explore Low-Level I/O**: Understand how standard C library functions support low-level input/output operations.

---

## Statement

The goal of Mini-LibC is to build a lightweight implementation of the C standard library with a focus on string handling, memory management, and POSIX file I/O operations. The library is freestanding, meaning no external libraries are used—it relies only on direct system calls.

**Key Features**:
- Reimplementation of essential libc functions.
- Freestanding implementation for x86_64 Linux systems.
- Built using the syscall interface.

**Compatibility**:
- Designed for Linux on x86_64.

---

## Project Structure

The project includes the following directories:

- **`libc/`**: Contains the Mini-LibC implementation. Functions marked with `TODO` are the ones to be implemented.
- **`samples/`**: Demonstrates use cases and tests of the Mini-LibC library.
- **`tests/`**: Includes test cases to validate the correctness of your implementation.

The system call invocation logic is encapsulated in the `syscall()` function defined in `libc/syscall.c`. Architecture-specific calls are handled in `libc/internal/arch/x86_64/syscall_arch.h`.

---

## API and Implementation Tasks

### String Handling (`<string.h>`)
Implement core string and memory manipulation functions:
- **String Functions**: `strcpy()`, `strncpy()`, `strcat()`, `strncat()`, `strlen()`, `strcmp()`, `strncmp()`, `strstr()`, `strrstr()`.
- **Memory Functions**: `memcpy()`, `memset()`, `memmove()`, `memcmp()`.

### Input/Output (`<stdio.h>`, `<unistd.h>`, `<sys/fcntl.h>`, `<sys/stat.h>`)
Provide low-level I/O capabilities:
- **Printing**: `puts()`.
- **File Operations**: `open()`, `close()`, `lseek()`, `stat()`, `fstat()`, `truncate()`, `ftruncate()`.
- **Timing**: `nanosleep()`, `sleep()`.

### Memory Management (`<stdlib.h>`, `<sys/mman.h>`)
Memory allocation and management functions:
- **Dynamic Memory**: `malloc()`, `free()`, `calloc()`, `realloc()`, `realloc_array()`.
- **Memory Mapping**: `mmap()`, `mremap()`, `munmap()`.

### Error Handling (`<errno.h>`)
- Track errors for system calls and functions.
---

## Installation

### Prerequisites
- **Linux x86_64**: Ensure you’re working on a compatible system.
- **GCC/Clang**: A C compiler is required.

### Building Mini-LibC
Clone the repository and build the library:
```bash
git clone https://github.com/teodoraplopeanu/Mini-LibC.git
cd Mini-LibC
make
