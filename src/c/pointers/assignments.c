#include <stdio.h>
#include <stdlib.h>

static void setInt(int *, int);
static void setIntFromText(int *, char *);

int main(int argc, char **argv)
{
    int    x = 0;
    int    y = 0;

    fprintf(stdout, "x[%d], y[%d]\n", x, y);

    x = 2;
    setInt(&y, x);

    fprintf(stdout, "x[%d], y[%d]\n", x, y);

    setIntFromText(&y, "3");

    fprintf(stdout, "x[%d], y[%d]\n", x, y);

    return (0);
}

static void setIntFromText(int *dest, char *value)
{
    *dest = atoi(value);
}

static void setInt(int *dest, int value)
{
    *dest = value;
}
