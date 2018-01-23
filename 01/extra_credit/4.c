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
*/
#include <stdio.h>

/* This is a comment. */
int main (int argc, char *argv[])
{
	int distance = 100;

	// this is also a comment.
	printf("You are %d miles away.\n", distance);

	return 0;
}
