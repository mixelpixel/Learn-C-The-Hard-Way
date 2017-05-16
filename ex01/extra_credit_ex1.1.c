#include <stdio.h>
// K&R style C, not declaring function type:
main(void)
{
    puts("\nHello, world!");

    return 0;
}

/*
Extra Credit
1. Open the ex1 file in your text editor and change or delete random parts.
   Try running it and see what happens.
2. Print out 5 more lines of text or something more complex than hello world.
3. Run man 3 puts and read about this function and many others.
*/

/* TYPE SPECIFIER MISSING
$  make extra_credit_ex1.1
cc     extra_credit_ex1.1.c   -o extra_credit_ex1.1
extra_credit_ex1.1.c:3:1: warning: type specifier missing, defaults to 'int' [-Wimplicit-int]
main(void)
^
1 warning generated.
*/
