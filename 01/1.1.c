#include <stdio.h> // <--------------- no warnings with $ make 1.1
                   // ---------------- or $ CFLAGS="-Wall" make 1.1
int main(int argc, char *argv[]) //--- but warnings with $ CFLAGS="-WCL4" make 1.1
{                                //--- for unused parameters
    puts("Hello world.");

    return 0;
}

// This does the same thing, note the #include needs
// to be on its own separate line
// #include <stdio.h>
// int main(int argc, char *argv[]){puts("Hello world.");return 0;}

// int main(void) avoids unused parameter warning with $ CFLAGS="-WCL4" make 1.1
// #include <stdio.h>
//
// int main(void)     // <------------- also no warnings with $ make 1.1
// {                  // <------------- or $ CFLAGS="-WCL4" make 1.1
//     puts("Hello world.");
//
//     return 0;
// }
