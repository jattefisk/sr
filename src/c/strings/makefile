include ../Makefile.def

TARGETS=null-strings    \
    concat        \
    escape        \
    findChar    \
    lengths        \
    numbers        \
    pos        \
    misc        \
    sizes        \
    sizes2        \
    values
OBJS=    null-strings.o    \
    concat.o    \
    escape.o    \
    findChar.o    \
    lengths.o    \
    misc.o        \
    numbers.o    \
    pos.o        \
    sizes.o        \
    sizes2.o    \
    values.o

all: $(TARGETS)

null-strings: null-strings.o
    $(CC) $(CFLAGS) $? -o $@

misc: misc.o
    $(CC) $(CFLAGS) $? -o $@

numbers: numbers.o
    $(CC) $(CFLAGS) $? -o $@

concat: concat.o
    $(CC) $(CFLAGS) $? -o $@

escape: escape.o
    $(CC) $(CFLAGS) $? -o $@

findChar: findChar.o
    $(CC) $(CFLAGS) $? -o $@

sizes: sizes.o
    $(CC) $(CFLAGS) $? -o $@

sizes2: sizes2.o
    $(CC) $(CFLAGS) $? -o $@

pos: pos.o
    $(CC) $(CFLAGS) $? -o $@

values: values.o
    $(CC) $(CFLAGS) $? -o $@

clean: .PHONY
    rm -f $(TARGETS) $(OBJS)

.PHONY:

