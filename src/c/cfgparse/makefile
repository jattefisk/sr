include ../Makefile.def

TARGETS=parse

OBJS=parse.o

all: $(TARGETS)

parse: parse.c
    $(CC) $(CFLAGS) $? -o $@

clean:
    rm -f $(TARGETS)
    rm -f $(OBJS)

.PHONY:

