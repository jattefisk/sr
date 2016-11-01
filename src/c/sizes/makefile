include ../Makefile.def

TARGETS=sizes values
OBJS=sizes.o values.o

all: $(TARGETS)

sizes: sizes.o
    $(CC) $(CFLAGS) $? -o $@

values: values.o
    $(CC) $(CFLAGS) $? -o $@

clean: .PHONY
    rm -f $(OBJS) $(TARGETS)

.PHONY:

