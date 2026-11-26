# libft

*This project has been created as part of the 42 curriculum by mousaidi.*

## Description

This is my first C library. The goal is to understand how the standard C functions work by recoding them from scratch, and to build a personal library that can be reused in later projects.

The library is compiled into a static archive "libft.a" and is made of 3 parts:
• Libc functions: reimplementation of standard functions, with the same behavior as the originals and an ft_ prefix.
• Additional functions: utility functions that are not in libc.
• Linked list functions: functions to manipulate linked lists, built around the t_list structure.

## Instructions

### Compilation

```sh
make			# builds libft.a at the root of the repository
make clean		# removes the object files
make fclean		# removes the object files and libft.a
make re			# fclean, then rebuild everything
```

### Usage

Include the header in your sources file and link against the library:

```c
#include "libft.h"

int	main(void)
{
	ft_putstr_fd("libft finished YAY!!", 1);
	return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c -L. -lft -o main
```

## Resources

### References
• man 3 pages for each reimplemented function.
• [cppreference - C standard library]() for the behavior of standard functions.
• [GNU Make manual]().
• [The 42 Norm]()styling checking.

### Use of AI
AI (Claude and Gemini) was used as a learning and verification aid.
• Used to look for references to learn Makefile, how to write a README.md, and Behavior of standard functions.
• Diagnose setup problems with the runnning environment (cc).
• To review my code.