# Learn-C-The-Hard-Way
Zed A. Shaw's C Programming Tutorial, an old version of "(Learn C The Hard Way)[https://web.archive.org/web/20140722163343/http://c.learncodethehardway.org:80/book/]"  

1. I am working with Terminal.app version 2.7.2 (388.1) on macOS Sierra version 10.12.4 (16E195).  
2. When including quotes from the tutorial I will try and append "(ZAS)"  

# Exercise 1: Dust Off That Compiler

<details><summary> Notes to myself:</summary>Difference between `puts` and `printf`: [puts prints appends newline, printf allows http://stackoverflow.com/a/2454491/5225057)  
Odd, in the command line I can use `$ printf $ "ab\bcd"` to displat "acd" but `puts` returns "command not found." Not sure why since `man puts` displays the manual. There's also fputs. ...why the 3 in `man 3 puts`?  
</details><br>  

Some things have changed since this was written, e.g.  
```
$  make ex1
cc     ex1.c   -o ex1
ex1.c:3:5: warning: implicit declaration of function 'puts' is invalid in C99 [-Wimplicit-function-declaration]
    puts("Hello world.");
    ^
1 warning generated.
```
```
$  CFLAGS="-Wall" make ex1
cc -Wall    ex1.c   -o ex1
ex1.c:3:5: warning: implicit declaration of function 'puts' is invalid in C99 [-Wimplicit-function-declaration]
    puts("Hello world.");
    ^
1 warning generated.
```
NOTE:  
```
$  CFLAGS='-WCL4' make ex1
cc -WCL4    ex1.c   -o ex1
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

[See ex1.1.c for a warning free example compiling with CFLAGS='-Wall'](ex1/ex1.1.c)

<details><summary>Notes to myself:</summary>I accidentally wrote CFLAGS="-WALL" and got the message "did you mean '-WCL4'?" and tried it. This flag option warns about the unused parameters. Not sure if "man make" is where I should be looking to ascertain what these flags are doing, but I think I am invoking the -W -C -L flags with make, but not sure what the 4 is for.  
</details><br>  

[See ex1.2.c for a warning free example using "void" and compiling with CFLAGS='-WCL4'](ex1/ex1.2.c)


# Exercise 2: Make Is Your Python Now
<details><summary>Notes to myself:</summary>Hmm... reading `man cc` didn't help me to understand the -"Wall" or "WLC4" ("-04"?), but this did "In this example I did CFLAGS="-Wall" make ex1 so that it would add the command line option -Wall to the cc command that make normally runs"(ZAS)

I also found this useful: CFLAGS='-Wall' "is a way to pass "modifiers" to the make command. If you're not familiar with how the Unix shell works, you can create these "environment variables" which will get picked up by programs you run. Sometimes you do this with a command like export CFLAGS="-Wall" depending on the shell you use. <b>You can however also just put them before the command you want to run, and that environment variable will be set only while that command runs.<b>"</details><br>  
