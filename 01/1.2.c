#include <stdio.h>
// no warning messages when compiling: $ CFLAGS='-WCL4' make 1.2
int main(void)
{
    puts("Hello world.");

    return 0;
}

// #include <stdio.h>
//
// int main(int argc, char *argv[]) // <--  "unused parameters" warnings with
// {                                // <--- $ CFLAGS='-WCL4' make 1.2
//     puts("Hello world.");
//
//     return 0;
// }
