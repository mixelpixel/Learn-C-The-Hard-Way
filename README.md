# Learn-C-The-Hard-Way
Zed A. Shaw's C Programming Tutorial, "(Learn C The Hard Way)[https://web.archive.org/web/20140722163343/http://c.learncodethehardway.org:80/book/]"  

I am working with Terminal.app version 2.7.2 (388.1) on macOS Sierra version 10.12.4 (16E195).  

# ex1

Some things have changed since this was written, e.g.  
```
$  make ex1
cc     ex1.c   -o ex1
ex1.c:3:5: warning: implicit declaration of function 'puts' is invalid in C99 [-Wimplicit-function-declaration]
    puts("Hello, world!");
    ^
1 warning generated.
```
```
$  CFLAGS="-WALL" make ex1
cc -WALL    ex1.c   -o ex1
warning: unknown warning option '-WALL'; did you mean '-WCL4'? [-Wunknown-warning-option]
ex1.c:3:5: warning: implicit declaration of function 'puts' is invalid in C99 [-Wimplicit-function-declaration]
    puts("Hello, world!");
    ^
2 warnings generated.
```

