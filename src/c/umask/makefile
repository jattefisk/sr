ARCH=-m32

CFLAGS=-g $(ARCH)

OBJS=    flag_test.o

EXES=    flag_test

bin:    $(EXES)

run:    bin
    flag_test
    @ls -l

clean:
    -rm -f $(OBJS) $(EXES)
    -rm -f file1.out file2.out file3.out file4.out

flag_test.o:    flag_test.c

