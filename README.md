# Learn-C-The-Hard-Way
Zed A. Shaw's C Programming Tutorial, an old version of "(Learn C The Hard Way)[https://web.archive.org/web/20140722163343/http://c.learncodethehardway.org:80/book/]"  

I am working with Terminal.app version 2.7.2 (388.1) on macOS Sierra version 10.12.4 (16E195).  

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
$  CFLAGS="-WALL" make ex1
cc -WALL    ex1.c   -o ex1
warning: unknown warning option '-WALL'; did you mean '-WCL4'? [-Wunknown-warning-option]
ex1.c:3:5: warning: implicit declaration of function 'puts' is invalid in C99 [-Wimplicit-function-declaration]
    puts("Hello world.");
    ^
2 warnings generated.
```
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
[See ex1.2.c for a warning free example](ex1/ex1.2.c)

# Exercise 2: Make Is Your Python Now
