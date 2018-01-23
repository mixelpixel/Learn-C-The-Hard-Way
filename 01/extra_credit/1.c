/*
Extra Credit
1. Open the ex1 file in your text editor and change or delete random parts.
   Try running it and see what happens.
2. Print out 5 more lines of text or something more complex than hello world.
3. Run man 3 puts and read about this function and many others.
4. For each line, write out the symbols you don’t understand and see if you can
   guess what they mean. Write a little chart on paper with your guess so you
   can check it later to see if you got it right.
*/

#include <stdio.h>
// K&R style of C: not declaring function type, i.e. int main(void):
main(void)
{
    puts("\nHello, world!");

    return 0;
}

/* warning: TYPE SPECIFIER MISSING
$  make extra_credit_ex1.1
cc    1.1.c   -o 1.1
1.1.c:3:1: warning: type specifier missing, defaults to 'int' [-Wimplicit-int]
main(void)
^
1 warning generated.

Just a warning, defaults to int and compiles. Ta-da!
*/
