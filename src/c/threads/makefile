include ../Makefile.def

TARGETS=thread-test threadLocking t-segfault
CFLAGS += -pthread

OBJS=thread-test.o threadLocking.o t-segfault.o

all: $(TARGETS)

threadLocking: threadLocking.o
    $(CC) $(CFLAGS) $? -o $@

thread-test: thread-test.o
    $(CC) $(CFLAGS) $? -o $@

t-segfault: t-segfault.o
    $(CC) $(CFLAGS) $? -o $@

clean: .PHONY
    rm -f $(OBJS) $(TARGETS)
    rm -f threadLocking.txt

.PHONY:
