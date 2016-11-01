ARCH=-m32
CC=cc
CFLAGS=-g $(ARCH)

OBJS=times.o myConnect.o

EXES=    myConnect

objs: $(OBJS)

run: $(OBJS)
    $(CC) $(CFLAGS) -lmysqlclient $? -o $@

myConnect: myConnect.o
    $(CC) $(CFLAGS) -lmysqlclient $? -o $@

clean:
    rm -f $(OBJS) run
    -rm -f $(EXES)

myConnect.o:    myConnect.c

