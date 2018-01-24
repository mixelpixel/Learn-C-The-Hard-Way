# TABS ONLY FOR MAKEFILES
# -Wall for "all" "W"arnings (but isn't really "all" of them...)
# -g for debugging

CFLAGS=-Wall -g
# CFLAGS=-WCL4 -g

# # more info on "all" http://stackoverflow.com/a/2515000/5225057
# # "all" let's you specify "all" the files (dependencies) you want compiled
# # so you can just invoke `$ make` instead of `$ make all` or
# # `$ make <filename> <filename> <filename> <filename> ...`
# # We can also put other shell commands in the "all" dependency list.
# # Lastly, the `.c` file extension is IMPLIED
# all: 2.0 2.1 2.2
	# echo "this is amazing"

# # works the same with multiple "all"s, e.g.
# all: 2.0
# all: 2.1

# # We can also run the "clean" command below prior to compiling
# all: clean ex02

all: ex02

# # after clean, any shell commands will be executed
# clean:
# 	rm -f ex02
# 	rm -rf *.dSYM
# 	ls -alh
# 	pwd
# 	say you are amazing, patrick

# ? deletes a set character, ?? for two pad
# the -r (recursive) option is for the .dSYM directories
# clean:
# 	rm -rf 2? 2?? *.dSYM

clean:
	rm -f ex02
	rm -rf *.dSYM
