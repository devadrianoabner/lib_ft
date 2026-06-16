*This project has been created as part of the 42 curriculum by adrianda*

## Description

Libft is a custom C library (`libft.a`) that reimplements a core set of standard C library (`libc`) functions and adds extra utility functions for string handling, memory management, and (optionally) singly-linked lists. It serves as the personal toolbox used as a starting point for most subsequent projects in the 42 curriculum.

Building it solo was a steep learning curve. To manage the complexity, I split the required functions into four "quadrants" and worked through them iteratively over 21 days (May 26 – June 15, 2026), fitting sessions in around other commitments. Beyond the code itself, peer-to-peer discussion — comparing edge cases, debugging strategies, and norm issues with classmates — turned out to be the single most valuable resource throughout the project.

## Instructions

### Build

From the project root:

| Command | Effect |
| --- | --- |
| `make` | Compiles the sources and creates `libft.a` |
| `make clean` | Removes the object files (`.o`) |
| `make fclean` | Removes the object files and `libft.a` |
| `make re` | Runs `fclean`, then `make` |

### Use in another project

1. Copy (or add as a git submodule) the `libft` folder into your project.
2. Include the header:

   ```c
   #include "libft.h"
   ```

3. Compile, pointing the linker at the library:

   ```bash
   gcc your_file.c -L. -lft -o your_program
   ```

   (adjust the `-L` path if `libft.a` and `libft.h` live in a different directory than `your_file.c`)

## Technical Choices

On top of the mandatory 42 Norm, this library follows a few self-imposed rules:

- **No global variables** — every function is self-contained, which avoids hidden shared state and keeps the code naturally thread-safe.
- **`static` helper functions** — internal helpers (e.g. counting words, computing a word's length) are declared `static`, so they stay private to their file and don't pollute the library's public API.
- **Strict compilation flags** — every source file compiles cleanly with `-Wall -Wextra -Werror`, with zero warnings.
- **`ar`-based archiving** — `libft.a` is built with `ar rcs`, without relying on `libtool` or other build abstractions.
- **Defensive memory management** — every `malloc` return value is checked. Functions that perform several allocations (like `ft_split`) free everything they have already allocated if a later allocation fails, following an `ft_free_all`-style cleanup pattern.

## Library Overview

### Part 1 — Libc function clones

| Function | Description |
| --- | --- |
| `ft_isalpha` | Checks whether a character is a letter (`a`-`z`, `A`-`Z`) |
| `ft_isdigit` | Checks whether a character is a digit (`0`-`9`) |
| `ft_isalnum` | Checks whether a character is a letter or a digit |
| `ft_isascii` | Checks whether a character is in the 0–127 ASCII range |
| `ft_isprint` | Checks whether a character is printable (including space) |
| `ft_strlen` | Returns the length of a string |
| `ft_memset` | Fills a memory area with a given byte |
| `ft_bzero` | Fills a memory area with zeros |
| `ft_memcpy` | Copies a memory area |
| `ft_memmove` | Copies a memory area, safely handling overlap |
| `ft_strlcpy` | Size-bounded string copy |
| `ft_strlcat` | Size-bounded string concatenation |
| `ft_toupper` | Converts a lowercase letter to uppercase |
| `ft_tolower` | Converts an uppercase letter to lowercase |
| `ft_strchr` | Finds the first occurrence of a character in a string |
| `ft_strrchr` | Finds the last occurrence of a character in a string |
| `ft_strncmp` | Compares two strings up to `n` characters |
| `ft_memchr` | Finds the first occurrence of a byte in a memory area |
| `ft_memcmp` | Compares two memory areas |
| `ft_strnstr` | Finds the first occurrence of a substring within a length limit |
| `ft_atoi` | Converts a string to an `int` |
| `ft_calloc` | Allocates and zero-initialises memory |
| `ft_strdup` | Duplicates a string, returning a newly allocated copy |

### Part 2 — Additional functions

| Function | Description |
| --- | --- |
| `ft_substr` | Allocates a substring extracted from a string |
| `ft_strjoin` | Allocates a new string that concatenates two strings |
| `ft_strtrim` | Allocates a copy of a string with leading/trailing characters from a set removed |
| `ft_split` | Allocates and returns an array of strings, splitting the input on a delimiter |
| `ft_itoa` | Allocates a string representation of an `int` |
| `ft_strmapi` | Applies a function to each character of a string (with its index), returning a new string |
| `ft_striteri` | Applies a function to each character of a string in place, with its index |
| `ft_putchar_fd` | Writes a character to a file descriptor |
| `ft_putstr_fd` | Writes a string to a file descriptor |
| `ft_putendl_fd` | Writes a string followed by `\n` to a file descriptor |
| `ft_putnbr_fd` | Writes an `int` to a file descriptor |

### Part 3 singly-linked lists


| Element | Description |
| :-: | :-: |
| `t_list` | Linked-list node: holds `void *content` and a `next` pointer |
| `ft_lstnew` | Allocates a new list node |
| `ft_lstadd_front` | Inserts a node at the start of a list |
| `ft_lstsize` | Returns the number of nodes in a list |
| `ft_lstlast` | Returns the last node of a list |
| `ft_lstadd_back` | Inserts a node at the end of a list |
| `ft_lstdelone` | Frees a single node, applying a destructor to its content |
| `ft_lstclear` | Frees an entire list, node by node |
| `ft_lstiter` | Applies a function to the content of each node |
| `ft_lstmap` | Builds a new list by applying a function to each node's content |

## Resources

### References

- [Linux man pages, section 3](https://man7.org/linux/man-pages/) — reference behaviour for the libc functions being reimplemented (`man strlcpy`, `man memmove`, `man strtok`, etc.)
- 42's Norm documentation (`norminette`) — the coding-style rules enforced throughout the project

### AI usage

- **Debugging `ft_split`** — shared the `ft_make_split` implementation for review. Claude pointed out that the loop mixed the index used to walk the input string (`s[i]`) with the index used to write into the result array (`str[i]`); once `s` was advanced past the first word these two indices diverged, causing a heap-buffer-overflow. The fix (checking `*s` instead of `s[i]`) was verified by compiling with AddressSanitizer.

