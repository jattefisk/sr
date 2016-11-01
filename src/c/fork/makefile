ARCH=-m32

CFLAGS=-g $(ARCH)

TARGETS=sheep
OBJS=sheep.o

work:    $(TARGETS)

sheep:    sheep.o
    $(CC) $(CFLAGS) -o $@ $?

clean:
    rm -f $(TARGETS) $(OBJS)

