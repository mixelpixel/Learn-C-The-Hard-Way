# -Wall for "all" "W"arnings (but isn't really "all" of them...)
# -g for debugging
# CFLAGS=-Wall -g
CFLAGS=-WCL4 -g

# more info on "all" http://stackoverflow.com/a/2515000/5225057
all: 2.0 2.1 2.2
# works the same with multiple "all"s, e.g.
# all: 2.0
# all: 2.1

# ? deletes a set character, ?? for two pad
# the -r (recursive) option is for the .dSYM directories
clean:
	rm -rf 2? 2?? *.dSYM
