int main(int argc, char *argv[])
{
		puts("Hello world.");

		return 0;
}

/* This does the same thing:

int main(int argc, char *argv[]){puts("Hello world.");return 0;}

*/

/* The top version uses tabs (settabspace = 2)
But C will compile a single 4 space tab or spaces.
use set: list to display End Of Line and TABS
NOTE that I padded lines with whitespaces */

/* Same program written with spaces instead of TABS:

int main (int argc, char *argv[])
{            
    puts (    "Hello world."    );

    return 0                     ;
}         

*/

