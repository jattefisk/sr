include ../Makefile.def

TARGETS=divide

OBJS=    divide.o

all: $(TARGETS)

divide: divide.o
    $(CC) $(CFLAGS) $? -o $@

clean: .PHONY
    rm -f $(TARGETS) $(OBJS)

.PHONY:

