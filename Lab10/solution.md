## Exercise 1 - OpenMP Hello World
piazza @354:

When we use make, it seems that when using some versions, the linker cannot link OpenMP libraries correctly.

If you encounter the same problem, use following command directly:

gcc -fopenmp -Wall -Wextra -std=gnu99 hello.c -o hello

And using ./hello to see the result(the same to matmul.c & dotp.c)

If your make work without this error, also correct a little mistake in Makefile:

EXECUTABLES = hello v_add dotp
change to 
EXECUTABLES = hello matmul dotp

Sorry for the mistake.

## Exercise 2 - Matrix Multiplication


## Exercise 3 - Dot Product
