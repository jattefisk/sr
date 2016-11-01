#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv)
{
    char    msg[80];

    fprintf(stdout, "sizeof(char) bytes[%d]\n", sizeof(char));
    fprintf(stdout, "sizeof(double) bytes[%d]\n", sizeof(double));
    fprintf(stdout, "sizeof(float) bytes[%d]\n", sizeof(float));
    fprintf(stdout, "sizeof(int) bytes[%d]\n", sizeof(int));
    fprintf(stdout, "sizeof(long) bytes[%d]\n", sizeof(long));
    fprintf(stdout, "sizeof(long double) bytes[%d]\n", sizeof(long double));
    fprintf(stdout, "sizeof(short) bytes[%d]\n", sizeof(short));

    fprintf(stdout, "sizeof(char[80]) bytes[%d]\n", sizeof(msg));

    return (0);
}
