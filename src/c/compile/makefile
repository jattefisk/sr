include ../Makefile.def

TARGETS=    \
    test     \
    test-t

OBJS=    \
    test.o    \
    test-t.o

all: $(TARGETS)

test: test.o
    $(CC) $(CFLAGS) $? -o $@

test-t:
    $(CC) -c $(CFLAGS) -DT1 test.c -o test-t.o
    $(CC) $(CFLAGS) test-t.o -o $@

clean: .PHONY
    rm -f $(OBJS) $(TARGETS)

.PHONY:
