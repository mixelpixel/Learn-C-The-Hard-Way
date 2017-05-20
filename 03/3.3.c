/*
Extra Credit
Find as many other ways to break ex3.c as you can.
--> Run man 3 printf and read about the other '%' format characters you can use.
--> These should look familiar if you used them in other languages
--> (printf is where they come from).
Add ex3 to your Makefile's all list. Use this to make clean all and build all your exercises so far.
Add ex3 to your Makefile's clean list as well. Now use make clean will remove it when you need to.
*/

// from `$ man 3 printf`
#include <math.h>
#include <stdio.h>

// To print pi to forty-eight decimal places:
int main(void)
{
  fprintf(stdout, "pi = %.48f\n", 4 * atan(1.0));

  return 0;
}
