#include <stdio.h>

/*
 * This program has errors on purpose:
   1. I've failed to initialize the height variable.
   2. I've forgot to give the first printf the age variable.
   Use Valgrind to analyze the errors:
   `$ valgrind ./ex04`
 */

 int main(int argc, char *argv[])
 {
   int age = 43;
   int height;

   printf("I am %d years old.\n");
   printf("I am %d inches tall\n", height);

   return 0;
 }
