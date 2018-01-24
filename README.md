# "Learn C The Hard Way" by Zed A. Shaw
Zed A. Shaw's C Programming Tutorial, "[Learn C The Hard Way](https://learncodethehardway.org/c/)"

▶︎ Click ▶︎ on ▶︎ the ▶︎ triangles ▶︎ to ▶︎ display ▶︎ extra ▶︎ notes. ▶︎

# Exercise 0: [The Setup](https://github.com/zedshaw/learn-c-the-hard-way-lectures/blob/master/ex0/lecture.md)

<details><summary>My Setup While Working Through the Course, Notes & To Do...</summary><p>

### I am working with:
1. macOS Sierra version 10.12.5 (16F73), Kernel Version: Darwin 16.6.0 _through_ macOS High Sierra version 10.13.2 (17C205) Kernel Version: Darwin 17.3.0, and
2. Terminal.app version 2.7.2 (388.1) through 2.8,
3. Xcode Version 9.0.1 (9A1004),
4. `$  cc --version` ---> `Apple LLVM version 9.0.0 (clang-900.0.38)`
5. As of 6/8/2017 [valgrind](http://valgrind.org/) is still inoperable with macOS Sierra, <strike>so I am continuing using Ubuntu 16.04.2 LTS on either a persistent USB boot stick, or, as a guest OS in Virtual Box v5.1.22 r115126 (Qt5.6.2), GNOME Terminal 3.18.3 "A terminal emulator for the GNOME desktop. Using VTE version 0.42.5 +GNUTLS.</strike>
  - **UPDATE** 6/15/2017 valgrind 3.13.0 runs on macOS Sierra! I installed w/Homebrew. Seems to work on macOS High Sierra...
  ```
  $  valgrind --version
  valgrind-3.13.0
  ```
6. `$  diff -v` ---> `diff (GNU diffutils) 2.8.1`
7. `$  lldb -v` ---> `lldb-900.0.50.1, Swift-4.0`
8. `$  splint -help version` ---> `Splint 3.1.2 --- 21 Sep 2017`

### [Zed Shaw's GitHub repository](https://github.com/zedshaw/learn-c-the-hard-way-lectures)

NOTE:
1. When including quotes from the tutorial I will try and append "_(ZAS)_"
2. Additional reference: https://github.com/mwilliams/lcthw-book
3. https://www.safaribooksonline.com/library/view/learn-c-the/9780134434452/
4. Additional C resource: https://www.cprogramming.com/

TODO:
1. add this to an appropriate section: https://www.go4expert.com/articles/solution-using-scanf-fgets-c-t27148/

</p></details>


***


# Exercise 1: [Dust Off That Compiler](https://github.com/zedshaw/learn-c-the-hard-way-lectures/blob/master/ex1/lecture.md)

<details><summary>Notes to myself:</summary><p>

- [Difference between `puts` and `printf`](http://stackoverflow.com/a/2454491/5225057)
  1. `puts` automatically appends a newline.
  2. `printf` uses "%s" style **print f**ormatting.

- Odd, in the command line I can use `$ printf $ "ab\bcd"` to display "acd" but `puts` returns "command not found." Not sure why since `man puts` displays the manual. There's also `fputs`.
- Why the 3 in `man 3 puts`? Answer: https://en.wikipedia.org/wiki/Man_page#Manual_sections (see also `man man` for the `-a` option to display all manual sections).

</p></details>

<details><summary>Changes since LCTHW published</summary><p>

- Some things have changed since this was written, e.g. `make` reports the same warning without CFLAGS declaration:

  ```bash
  $  make 1.0
  cc     1.0.c   -o 1.0
  ex1.c:3:5: warning: implicit declaration of function 'puts' is invalid in C99 [-Wimplicit-function-declaration]
      puts("Hello world.");
      ^
  1 warning generated.
  ```

- CFLAGS declared:

  ```bash
  $  CFLAGS="-Wall" make 1.0
  cc -Wall    1.0.c   -o ex1.0
  ex1.c:3:5: warning: implicit declaration of function 'puts' is invalid in C99 [-Wimplicit-function-declaration]
      puts("Hello world.");
      ^
  1 warning generated.
  ```

[See 1.1.c for a warning free example compiling with or without CFLAGS='-Wall'](01/1.1.c)

</p></details>

<details><summary>Notes re: CFLAGS</summary><p>

- Of note, the `CFLAGS='-WCL4'` compile warns about the unused parameters:

```bash
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

- I "discovered" this flag option because I accidentally wrote `CFLAGS="-WALL"` (all caps) and got the message "`warning: unknown warning option '-WALL'; did you mean '-WCL4'? [-Wunknown-warning-option]`" and tried it. This flag option also warns about the unused parameters. Not sure what other conditions it covers. Also not sure if `$ man make` is where I should be looking to ascertain what these flags are doing, but I think I am invoking the `-W` `-C` `-L` flags with `make`, but not sure what the `4` is for.
- NOTE: `-WCL4` seems to only be a thing in MacOS, not Ubuntu. No idea why.
- Explicitly stating there are no parameters in main with "void" avoids this warning, e.g.

```c
int main(void)
{
    puts("Look, no warning msg!");
    return 0;
}
```

- ...and apparently so does leaving the parameters list void, e.g.

```c
int main()
{
    puts("Look, no warning msg!");
    return 0;
}
```

- [See 1.2.c for a warning free example using "void" and compiling with CFLAGS='-WCL4'](01/1.2.c)

</p></details>

[Exercise 1 √](01/)


***


# Exercise 2: [Make Is Your Python Now](https://github.com/zedshaw/learn-c-the-hard-way-lectures/blob/master/ex2/lecture.md)

<details><summary>Notes re: `make`, `cc`, `-Wall` & `-WCL4`:</summary><p>

- Hmm... reading `$ man make` didn't help me to understand the `-"Wall"` or `"-WCL4"`, but this helped some:
  > "In this example I did `CFLAGS="-Wall" make ex1` so that it would *add the command line option `-Wall` to the `cc` command that `make` normally runs*" _(ZAS)_

- So I read `$ man cc` but am still not sure about what is going on here: is `-Wall` like `-W` and `-all`? is `-WCL4` like `-W` `-C` `-L` and `-4` ("`-04`"?)? Per the extra credit, I'll do a little more research...
- I also found this useful: `CFLAGS='-Wall'`
  > "is a way to pass "modifiers" to the make command. If you're not familiar with how the Unix shell works, you can create these "environment variables" which will get picked up by programs you run. Sometimes you do this with a command like export `CFLAGS="-Wall"` depending on the shell you use. *You can however also just put them before the command you want to run, and that environment variable will be set only while that command runs.*" _(ZAS)_

</p></details>

<details><summary>Notes re: `make`, `vim` & `vi`:</summary><p>

- `make` is very particular about tabs not being spaces and end of line. In my ~/.vimrc settings file I had "set expandtab" as an option to turn tabs into spaces. I commented this out & now the "Makefile" exercise works :). Basically the same as to be expected:

```bash
$  make clean
rm -f ex1
$  make ex1
cc -Wall -g    ex1.c   -o ex1
ex1.c:3:5: warning: implicit declaration of function 'puts' is invalid in C99 [-Wimplicit-function-declaration]
    puts("Hello world.");
    ^
1 warning generated.
```

- For vim: ESC, `:set list`, REUTRN will enable display for end of line as `$` and TABs as `I^`
- For vim: ESC, `:set nolist`, RETURN will disbale the "list display"
- For vi, I've set the .exrc file accordingly.
- Additional resources: https://www.gnu.org/software/make/
- What is a .dSYM directory for? When I run the command make using Makefile, I end up, for example, with the directory ex1.dSYM containing the ex1 binary within /Contents/Resources/DWARF/ including an info.plist in the /Contents/ directory. Ah-ha: [Debug SYMbols](https://stackoverflow.com/a/585298/5225057)

</p></details>

[Exercise 2 √](02/)


***


# Exercise 3: [Formatted Printing](https://github.com/zedshaw/learn-c-the-hard-way-lectures/blob/master/ex3/lecture.md)
[Exercise 3 √](03/)


***


# Exercise 4: [Using a Debugger](https://github.com/zedshaw/learn-c-the-hard-way-lectures/blob/master/ex4/lecture.md)

<details><summary>valgrind install attempt notes</summary><p>

## [Introducing Valgrind](https://github.com/mwilliams/lcthw-book/blob/master/learn-c-the-hard-waych5.txt)
### Installing [Valgrind](http://valgrind.org/) -  v3.12.0 NOT SUPPORTED ENOUGH FOR macOS Sierra.

- **UPDATE** valgrind v.3.13.0 supported on macOS Sierra and seems to work okay on macOS High Sierra

- [Valgrind on macOS Sierra?](https://stackoverflow.com/questions/40650338/valgrind-on-macos-sierra)
- http://valgrind.org/docs/download_docs.html
- https://bugs.kde.org/show_bug.cgi?id=365327
- https://stackoverflow.com/a/43431715/5225057
- http://valgrind.org/downloads/current.html#current
  - *md5: 6eb03c0c10ea917013a7622e483d61bb*

- WTAF?

```bash
$  curl -O http://valgrind.org/downloads/valgrind-3.12.0.tar.bz2
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100 12.1M  100 12.1M    0     0  1213k      0  0:00:10  0:00:10 --:--:-- 1372k
$  md5 valgrind-3.12.0.tar.bz2
MD5 (valgrind-3.12.0.tar.bz2) = 6eb03c0c10ea917013a7622e483d61bb
$  tar -xjvf valgrind-3.12.0.tar.bz2
$  cd valgrind-3.12.0
$  open FAQ.txt
$  ./configure
...
     Maximum build arch: amd64
     Primary build arch: amd64
   Secondary build arch: x86
               Build OS: darwin
   Primary build target: AMD64_DARWIN
 Secondary build target: X86_DARWIN
       Platform variant: vanilla
  Primary -DVGPV string: -DVGPV_amd64_darwin_vanilla=1
     Default supp files: exp-sgcheck.supp xfree-3.supp xfree-4.supp darwin10-drd.supp darwin16.supp

$  make
...
ld: symbol(s) not found for architecture x86_64
make[3]: *** [memcheck-amd64-darwin] Error 1
make[2]: *** [all-recursive] Error 1
make[1]: *** [all-recursive] Error 1
make: *** [all] Error 2
$  sudo make install
Password:
...
Undefined symbols for architecture x86_64:
  "___bzero", referenced from:
      _hijack_thread_state in libcoregrind-amd64-darwin.a(libcoregrind_amd64_darwin_a-syswrap-amd64-darwin.o)
      _RRegUniverse__init in libvex-amd64-darwin.a(libvex_amd64_darwin_a-host_generic_regs.o)
ld: symbol(s) not found for architecture x86_64
make[3]: *** [memcheck-amd64-darwin] Error 1
make[2]: *** [install-recursive] Error 1
make[1]: *** [install-recursive] Error 1
make: *** [install] Error 2
$  valgrind ls -l
valgrind: tool 'memcheck' not installed (/usr/local/lib/valgrind/memcheck-amd64-darwin) (No such file or directory)
```

- [possible fix?](http://valgrind.10908.n7.nabble.com/Unable-to-compile-on-Mac-OS-X-10-11-td57237.html)
- Change: "coregrind/m_main.c" from:
  - `#if defined(VGO_darwin) && DARWIN_VERS == DARWIN_10_10` to:
  - `#if defined(VGO_darwin)`
```bash
$  brew install valgrind
valgrind: This formula either does not compile or function as expected on macOS
versions newer than El Capitan due to an upstream incompatibility.
Error: An unsatisfied requirement failed this build.
```

# OOF-AH!
- See: [pt1](04/Valgrind_Notes/Valgrind_pt1.md) & [pt2](04/Valgrind_Notes/Valgrind_pt2.md)

- Oddly, and after all this, I decided to install Ubuntu 16.04.2 LTS on a Virtual Box and go through the same process of installation (note: `md5sum` instead of `md5`) but after a successful `make install` the `valgrind` command was not recognized. WTF? So, I simply resorted to `sudo apt install valgrind` and it works fine on Ubuntu... :\
- Aaand the performance blows on the VirtualBox, so I made a persistent USB stick... it's USB2.0 tho, so I might have to get a usb 3.0 cuz it's not that much better :\
- Tracking this for using MacOS Sierra with valgrind: https://apple.stackexchange.com/questions/285329/valgrind-for-macos-sierra-on-i7-macbook-air

</p></details>

<details><summary>Click here for some fun info on Valgrind</summary><p>

- https://dot.kde.org/2006/02/21/interview-valgrind-author-julian-seward

> 1.1. How do you pronounce "Valgrind"?
> The "Val" as in the word "value". The "grind" is pronounced with a short 'i' -- ie. "grinned" (rhymes with "tinned") rather than "grined" (rhymes with "find").
>
> Don't feel bad: almost everyone gets it wrong at first.
> ***
>
> 1.2. Where does the name "Valgrind" come from?
> From Nordic mythology. Originally (before release) the project was named Heimdall, after the watchman of the Nordic gods. He could "see a hundred miles by day or night, hear the grass growing, see the wool growing on a sheep's back", etc. This would have been a great name, but it was already taken by a security package "Heimdal".
>
> Keeping with the Nordic theme, Valgrind was chosen. Valgrind is the name  of the main entrance to Valhalla (the Hall of the Chosen Slain in Asgard). Over this entrance there resides a wolf and over it there is the head of a boar and on it perches a huge eagle, whose eyes can see to the far regions of the nine worlds. Only those judged worthy by the guardians are allowed to pass through Valgrind. All others are refused entrance.
>
> It's not short for "value grinder", although that's not a bad guess.

</p></details>

<details><summary>GDB, LLDB, Address Sanitizer, LLVM, Splint</summary><p>

- [GDB](https://www.gnu.org/software/gdb/): GNU Debugger (Linux)
- [LLDB](https://lldb.llvm.org/): Low Level DeBugger (OSX)
- [Address Sanitizer](https://clang.llvm.org/docs/AddressSanitizer.html)
- [LLVM](https://llvm.org/): no longer an acronym for Low Level Virtual Machine, it's a bunch of tools!
- [Splint](http://lclint.cs.virginia.edu/)
- [Splint homebrew](http://brewformulas.org/Splint)

</p></details>

[Exercise 4 √](04/)


***


# Exercise 5: [Memorizing C Operators](https://github.com/zedshaw/learn-c-the-hard-way-lectures/blob/master/ex5/lecture.md)

<details><summary>The Structure Of A C Program</summary><p>

- [The Structure Of A C Program](https://github.com/mwilliams/lcthw-book/blob/master/learn-c-the-hard-waych6.txt)
- see [ex01's extra credit #4](01/extra_credit/4.c) for a breakdown of the components.

</p></details>

<details><summary>C Operators</summary><p>

### Arithmetic Operators
- `+` Add
- `-` Subtract
- `*` Multiply
- `/` Divide
- `%` Modulus
- `++` Increment
- `--` Decrement

### Relational Operators
- `==` Equal
- `!=` Not Equal
- `>` Greater than
- `<` Less than
- `>=` Greater than euqal
- `<=` Less than equal

### Logical Operators
- `&&` Logical and
- `||` Logical or
- `!` Logical not
- `? :` Logical ternary

### Bitwise Operators
- `&` Bitwise and
- `|` Bitwise or
- `^` Bitwise xor
- `~` Bitwise ones compliment
- `<<` Bitwise shift left
- `>>` Bitwise shift right

### Assignment Operators
- `=` Assign equal
- `+=` Assign plus-equal
- `-=` Assign minus-equal
- `*=` Assign multiply-equal
- `/=` Assign divide-equal
- `&=` Assign modulus-equal
- `<<=` Assign shift-left-equal
- `>>=` Assign shift-right-equal
- `&=` Assign and-equal
- `|=` Assign or-equal
- `^=` Assign xor-equal

### Data Operators
- `sizeof()` Get the size of
- `[]` Array subscript
- `&` The address of
- `*` The value of
- `->` Structure dereference
- `.` Structure reference

### Miscellaneous Operators
- `,` Comma
- `( )` Parentheses
- `{ }` Curly Braces
- `:` Colon
- `//` Single line comment start
- `/*` Multi-line comment start
- `*/` Multi-line comment end

</p></details>

[Exercise 5 √](05/)


***


# Exercise 6: [Types Of Variables](https://github.com/zedshaw/learn-c-the-hard-way-lectures/blob/master/ex6/lecture.md)
[Exercise 6](06/)
  - `char initial = 'A';` requires SINGLE quotes, double quotes results in an integer assignment


***


# Exercise 7: [More Variables, Some Math](https://github.com/zedshaw/learn-c-the-hard-way-lectures/blob/master/ex7/lecture.md)
[Exercise 7](07/)


***


# Exercise 8: [Sizes and Arrays](https://github.com/zedshaw/learn-c-the-hard-way-lectures/blob/master/ex8/lecture.md)
[Exercise 8](08/)


***


# Exercise 9: [Arrays And Strings](https://github.com/zedshaw/learn-c-the-hard-way-lectures/blob/master/ex9/lecture.md)
[Exercise 9](09/)


***


# Exercise 10: [Arrays Of Strings, Looping](https://github.com/zedshaw/learn-c-the-hard-way-lectures/blob/master/ex10/lecture.md)
[Exercise 10](10/)


***


# Exercise 11: [While-Loop And Boolean Expressions](https://github.com/zedshaw/learn-c-the-hard-way-lectures/blob/master/ex11/lecture.md)
[Exercise 11](11/)


***


# Exercise 12: [If, Else-If, Else](https://github.com/zedshaw/learn-c-the-hard-way-lectures/blob/master/ex12/lecture.md)
[Exercise 12](12/)


***


# Exercise 13: [Switch Statement](https://github.com/zedshaw/learn-c-the-hard-way-lectures/blob/master/ex13/lecture.md)
[Exercise 13](13/)


***


# Exercise 14: [Writing And Using Functions](https://github.com/zedshaw/learn-c-the-hard-way-lectures/blob/master/ex14/lecture.md)
[Exercise 14](14/)


***


# Exercise 15: [Pointers Dreaded Pointers](https://github.com/zedshaw/learn-c-the-hard-way-lectures/blob/master/ex15/lecture.md)
[Exercise 15](15/)


***


# Exercise 16: [Structs And Pointers To Them](https://github.com/zedshaw/learn-c-the-hard-way-lectures/blob/master/ex16/lecture.md)
[Exercise 16](16/)


***


# Exercise 17: [Heap And Stack Memory Allocation](https://github.com/zedshaw/learn-c-the-hard-way-lectures/blob/master/ex17/lecture.md)
[Exercise 17](17/)


***


# Exercise 18: [Pointers To Functions](https://github.com/zedshaw/learn-c-the-hard-way-lectures/blob/master/ex18/lecture.md)
[Exercise 18](18/)


***


# Exercise 19: [A Simple Object System](https://github.com/zedshaw/learn-c-the-hard-way-lectures/blob/master/ex19/lecture.md)
[Exercise 19](19/)


***


# Exercise 20: [Zed's Awesome Debug Macros](https://github.com/zedshaw/learn-c-the-hard-way-lectures/blob/master/ex20/lecture.md)
[Exercise 20](20/)


***


cont...
