#include <stdlib.h>
#include <stdio.h>

static void process(char *);

int main(int argc, char **argv)
{
    char    buf[80];

    process("01");
    process("01/A.3W:A1234");
    process("12.");
    process("23.a");

    buf[0] = '\0';
    process(buf);
    process(NULL);
}

static void process(char *str)
{
    char    *s = NULL;
    double    d;
    int i;

    d = strtod(str, &s);
    i = (int) strtod(str, &s);

    fprintf(stderr, "str[%s]\td[%.0f]\ti[%.2d]\ts[%s]\n", str, d, i, s);
}

