# Learn-C-The-Hard-Way
Zed A. Shaw's C Programming Tutorial, an old version of "(Learn C The Hard Way)[https://web.archive.org/web/20140722163343/http://c.learncodethehardway.org:80/book/]"  

1. I am working with Terminal.app version 2.7.2 (388.1) on macOS Sierra version 10.12.5 (16F73), Kernel Version: Darwin 16.6.0.  
2. When including quotes from the tutorial I will try and append "(ZAS)"  

# Exercise 1: Dust Off That Compiler

<details><summary> Notes to myself:</summary>Difference between `puts` and `printf`: [puts prints appends newline, printf allows http://stackoverflow.com/a/2454491/5225057)  
Odd, in the command line I can use `$ printf $ "ab\bcd"` to displat "acd" but `puts` returns "command not found." Not sure why since `man puts` displays the manual. There's also fputs. ...why the 3 in `man 3 puts`? Answer: https://en.wikipedia.org/wiki/Man_page#Manual_sections  
</details><br>  

Some things have changed since this was written, e.g. `make` reports the same warning without CFLAGS declaration:  
```
$  make 1.0
cc     1.0.c   -o 1.0
ex1.c:3:5: warning: implicit declaration of function 'puts' is invalid in C99 [-Wimplicit-function-declaration]
    puts("Hello world.");
    ^
1 warning generated.
```
```
$  CFLAGS="-Wall" make 1.0
cc -Wall    1.0.c   -o ex1.0
ex1.c:3:5: warning: implicit declaration of function 'puts' is invalid in C99 [-Wimplicit-function-declaration]
    puts("Hello world.");
    ^
1 warning generated.
```

[See 1.1.c for a warning free example compiling with or without CFLAGS='-Wall'](01/1.1.c)

<details><summary>Notes to myself:</summary>  

Of note, the `CFLAGS='-WCL4'` compile warns about the unused parameters:  

```
$  CFLAGS='-WCL4' make 1.0
cc -WCL4    1.0.c   -o 1.0
ex1.c:3:5: warning: implicit declaration of function 'puts' is invalid in C99 [-Wimplicit-function-declaration]
    puts("Hello world.");
    ^
ex1.c:1:14: warning: unused parameter 'argc' [-Wunused-parameter]
int main(int argc, char *argv[])
             ^
ex1.c:1:26: warning: unused parameter 'argv' [-Wunused-parameter]
int main(int argc, char *argv[])
                         ^
3 warnings generated.
```

I "discovered" this flag option because I accidentally wrote `CFLAGS="-WALL"` (all caps) and got the message "`did you mean '-WCL4'?`" and tried it. This flag option also warns about the unused parameters. Not sure what other conditions it covers. Also not sure if `$ man make` is where I should be looking to ascertain what these flags are doing, but I think I am invoking the `-W` `-C` `-L` flags with `make`, but not sure what the `4` is for.  

Explicitly stating there are no parameters in main with "void" avoids this warning, e.g.
```
int main(void)
{
    puts("Look, no warning msg!");
    return 0;
}
```
...and apparently so does leaving the parameters list void, e.g.
```
int main()
{
    puts("Look, no warning msg!");
    return 0;
}
```

</details><br>  

[See 1.2.c for a warning free example using "void" and compiling with CFLAGS='-WCL4'](01/1.2.c)


# Exercise 2: Make Is Your Python Now
<details><summary>Notes to myself:</summary>  

Hmm... reading `$ man make` didn't help me to understand the `-"Wall"` or `"-WLC4"`, but this helped some:  
"In this example I did `CFLAGS="-Wall" make ex1` so that it would <b>add the command line option `-Wall` to the `cc` command that `make` normally runs</b>"(ZAS)  
So I read `$ man cc` but am still not sure about what is going on here: is `-Wall` like `-W` and `-all`? is `-WLC4` like `-W` `-C` `-L` and `-4` ("`-04`"?)? Per the extra credit, I'll do a little more research...  

I also found this useful: `CFLAGS='-Wall'` "is a way to pass "modifiers" to the make command. If you're not familiar with how the Unix shell works, you can create these "environment variables" which will get picked up by programs you run. Sometimes you do this with a command like export `CFLAGS="-Wall"` depending on the shell you use. <b>You can however also just put them before the command you want to run, and that environment variable will be set only while that command runs.</b>"(ZAS)</details><br>  

`make` is very particular about tabs not being spaces and end of line. In my ~/.vimrc settings file I had "set expandtab" as an option to turn tabs into spaces. I commented this out & now the "Makefile" exercise works :). Basically the same as to be expected:  

```
$  make clean
rm -f ex1
$  make ex1
cc -Wall -g    ex1.c   -o ex1
ex1.c:3:5: warning: implicit declaration of function 'puts' is invalid in C99 [-Wimplicit-function-declaration]
    puts("Hello world.");
    ^
1 warning generated.
```  
NOTE for vim: ESC, `:set list`, REUTRN will enable display for end of line as `$` and TABs as `I^`  
NOTE for vim: ESC, `:set nolist`, RETURN will disbale the "list display"  

[Exercise 2 Makefile and extra credit](02/)  
Additional resources: https://www.gnu.org/software/make/  
What is a .dSYM directory for? When I run the command make using Makefile, I end up, for example, with the directory ex1.dSYM containing the ex1 binary within /Contents/Resources/DWARF/ including an info.plist in the /Contents/ directory.  

# Exercise 3: Formatted Printing
[c file, Makefile and Extra Credit](03/)

# Exercise 4: Introducing Valgrind
[c file, Makefile and Extra Credit](04/)
