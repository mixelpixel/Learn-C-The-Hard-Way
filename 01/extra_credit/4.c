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

/*
The octothorpe (#) indicates a kind of function is being invoked.
In this case `include` is used to "import" or "include" additional code.
Followed by the carrots (<, >), the `*.h` file is additional software
which can will be available to the program invoking, or "including" the
additional resource. In this case, the convention for C uses `*.h` to
indicate a _header_ file.
per: https://www.cprogramming.com/tutorial/cpreprocessor.html
The C preprocessr modifies the source code (the program) prior to handing it
over to the compiler. The C Preprocesor uses MACROS, DIRECTIVES & CONSTANTS.
In the case of the `#include` statement it is a DIRECTIVE which "directs" the
preprocessor to grab the text of a file (e.g. "stdio.h") and include it in the
source code which will get compiled, e.g. /usr/include/stdio.h
"Typically, such statements are placed at the top of a program--
hence the name "header file" for files thus included."
*/
#include <stdio.h>

/*
`int` indicates that the return value type of `main` will be an INTEGER. In this
case, the convention is that a return of 0 indicates success, where other
numbers would indicate types of failures.

per: http://en.cppreference.com/w/c/language/main_function &
http://c0x.coding-guidelines.com/5.1.2.2.1.html
`main` is the convention for all programs:
**C99 5.1.2.2.1 *Program startup***

The function called at program startup is named `main`. The implementation declares no
prototype for this function. It shall be defined with a return type of `int` and with no
parameters:

     `int main(void) { ... }`

or with two parameters (referred to here as `argc` and `argv`, though any names may be
used, as they are local to the function in which they are declared):

     int main(int argc, char *argv[]) { ... }

or equivalent; or in some other implementation-defined manner.

`argc` ARGument Count: a non-negative INTEGER, indicating the number of arguments
passed to the program from the environment in which the program is run.

`char` indicates a type: CHARacter. Technically, char is a one byte type that
can hold values from -128 to 127 and it is actually an integer type. C string
library functions are designed to be used with arrays of char, not arrays of int.

`argv` ARGument Vector (or Value). A "vector" is a one-dimensional array, and
argv is a one-dimensional array of STRINGS, e.g. ['hello', ', ', 'world', '!']

`{}` curly braces are used here to denote a code block.

`printf` is PRINT Formatting, i.e. the %d let's a variable of type d (digit? int signed integer)
be formatted within the string.
*/
int main (int argc, char *argv[])
{
	int distance = 100;
	// int distance = 'z'; // <--- will print 122 as the lower case 'z' in ASCII is 122, d === 100 in ascii.

	// this is also a comment.
	printf("You are %d miles away.\n", distance);

	return 0;
}

/*
 1. the equals operator is used as an assignment, an identity declaration, not as a comparison (e.g. == or ===)
 2. most every line ends with a semi-colon (except for logic???)
 3. the return statement is what is returned to stdout when the function is executed. In this case an integer with the value 0 - a convention for indicating success.
 4. "distance" is a variable name, I think they are limited to alphanumerics, maybe underscores, prolly not leading numbers, and as a convention are usually lower case where uppercase are reserved, I think, for macros.
 */
