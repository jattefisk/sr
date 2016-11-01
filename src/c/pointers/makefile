include ../Makefile.def

TARGETS=passing    \
    assignments

OBJS=passing.o    \
    assignments.o

all: $(TARGETS)

assignments: assignments.o
    $(CC) $(CFLAGS) -o $@ $?

passing: passing.o
    $(CC) $(CFLAGS) -o $@ $?

clean: .PHONY
    rm -rf $(TARGETS) $(OBJS)

.PHONY:

