include ../Makefile.def

TARGETS=proc-stat
OBJS=proc-stat.o

all: $(TARGETS)

proc-stat: proc-stat.o
    $(CC) $(CFLAGS) $? -o $@

clean: .PHONY
    rm -f $(TARGETS) $(OBJS)

.PHONY:

