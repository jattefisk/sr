include ../Makefile.def

OBJ=gen.o redirect.o

TARGETS=gen redirect

all: $(TARGETS)

redirect: redirect.o
    $(CC) $(CFLAGS) -o $@ $?

#gen.o: gen.c
#    $(CC) $(CFLAGS) -D_GNU_SOURCE -o $@ $?

gen: gen.o
    $(CC) $(CFLAGS) -o $@ -lm $?

clean: .PHONY
    rm -f $(TARGETS) $(OBJ)
    rm -f redirect.out

.PHONY:

