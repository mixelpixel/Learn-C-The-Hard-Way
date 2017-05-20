#include <stdio.h> // <------------- no warnings with `make 1.1.c`
                   // -------------- or `CFLAGS="-Wall" make 1.1`
int main(int argc, char *argv[])
{
    puts("Hello world.");

    return 0;
}

// This does the same thing, note the #include needs
// to be on its own separate line
// #include <stdio.h>
// int main(int argc, char *argv[]){puts("Hello world.");return 0;}

// #include <stdio.h>
//
// int main(void)     // <------------- also no warnings with `make 1.1.c`
// {                  // -------------- because no parameters.
//     puts("Hello world.");
//
//     return 0;
// }
