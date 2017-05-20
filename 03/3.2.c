/*
How To Break It
Try a few of these ways to break this program, which may or may not cause it to crash on your computer:

1. Take the age variable out of the first printf call then recompile.
   You should get a couple of warnings.
2. Run this new program and it will either crash, or print out a really crazy age.
3. Put the printf back the way it was, and then don't set age to an initial value by
changing that line to int age; then rebuild and run again.

Extra Credit
Find as many other ways to break ex3.c as you can.
Run man 3 printf and read about the other '%' format characters you can use. These should look familiar if you used them in other languages (printf is where they come from).
Add ex3 to your Makefile's all list. Use this to make clean all and build all your exercises so far.
Add ex3 to your Makefile's clean list as well. Now use make clean will remove it when you need to.
*/

// #############################################################################
#include <stdio.h>

int main(void)
{
  int age = 10;
  int height = 72;
//                            ", age" REMOVED results in vvvvvvvvvv
  printf("I am %d years old.\n");           // <--- I am 1538202312 years old.
  printf("I am %d inches tall.\n", height); // <--- I am 72 inches tall.

  return 0;
}

// $  make
// cc -WCL4 -g    3.2.c   -o 3.2
// 3.2.c:25:17: warning: more '%' conversions than data arguments [-Wformat]
//   printf("I am %d years old.\n");
//                ~^
// 3.2.c:22:7: warning: unused variable 'age' [-Wunused-variable]
//   int age = 10;
//       ^
// 2 warnings generated.


// #############################################################################
// #include <stdio.h>
//
// int main(void)
// {
//   int age;                                  // <--- no value assigned
//   int height = 72;
//
//   printf("I am %d years old.\n", age);      // <--- I am 287047734 years old.
//   printf("I am %d inches tall.\n", height); // <--- I am 72 inches tall.
//
//   return 0;
// }

// $  make
// cc -WCL4 -g    3.2.c   -o 3.2
// 3.2.c:38:34: warning: variable 'age' is uninitialized when used here [-Wuninitialized]
//   printf("I am %d years old.\n", age);
//                                  ^~~
// 3.2.c:35:10: note: initialize the variable 'age' to silence this warning
//   int age;                                      // <--- no value assigned
//          ^
//           = 0
// 1 warning generated.

// #############################################################################
// #include <stdio.h>
//
// int main(int argc, char *argv[])
// {
//   int age = 10;
//   int height = 72;
// //                               vvvv          <--- Why/how does this work?
//   printf("I am %d years old.\n", argv);     // <--- I am 1382623944 years old.
//   printf("I am %d inches tall.\n", height); // <--- I am 72 inches tall.
//
//   return 0;
// }

// $  make
// cc -WCL4 -g    3.2.c   -o 3.2
// 3.2.c:76:34: warning: format specifies type 'int' but the argument has type 'char **' [-Wformat]
//   printf("I am %d years old.\n", argv); //       <-----
//                ~~                ^~~~
// 3.2.c:73:7: warning: unused variable 'age' [-Wunused-variable]
//   int age = 10;
//       ^
// 3.2.c:71:14: warning: unused parameter 'argc' [-Wunused-parameter]
// int main(int argc, char *argv[])
//              ^
// 3 warnings generated.


// #############################################################################
// #include <stdio.h>
//
// int main(int argc, char *argv[])
// {
//   int age = 10;
//   int height = 72;
//
//   printf("I am %d years old.\n", argv);     // <--- I am 1601002184 years old.
//   printf("I am %d inches tall.\n", argc);   // <--- I am 1 inches tall.
//
//   return 0;
// }

// $  make
// cc -WCL4 -g    3.2.c   -o 3.2
// 3.2.c:104:34: warning: format specifies type 'int' but the argument has type 'char **' [-Wformat]
//   printf("I am %d years old.\n", argv);
//                ~~                ^~~~
// 3.2.c:101:7: warning: unused variable 'age' [-Wunused-variable]
//   int age = 10;
//       ^
// 3.2.c:102:7: warning: unused variable 'height' [-Wunused-variable]
//   int height = 72;
//       ^
// 3 warnings generated.
