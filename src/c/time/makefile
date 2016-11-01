ARCH=-m32

CFLAGS=-g $(ARCH)

TARGETS=test formats tz today
OBJS=test.o formats.o tz.o today.o

work:    $(TARGETS)

tz:    tz.o
    $(CC) $(CFLAGS) -o $@ $?

time-test: test.o
    cc -o $@ $?

today: today.o
    $(CC) $(CFLAGS) $? -o $@

formats: formats.o
    $(CC) $(CFLAGS) $? -o $@

run:    time-test
    ./$?

clean:
    rm -f $(TARGETS) $(OBJS)
    rm -f time-test

