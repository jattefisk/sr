#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef    _S2_BUF_SIZE
#define    _S2_BUF_SIZE    64
#endif

static void run1();
static void run2();
static void run3();

int main(int argc, char **argv)
{
    int    run = 0;

    if (argc > 1) {
        run = atoi(argv[1]);
    }

    switch (run) {
    case 1:
        run1();
        break;
    case 2:
        run2();
        break;
    case 3:
        run3();
        break;
    default:
        run1();
        run2();
        run3();
        break;
    }

    return (0);
}

static void run1() {
    char    buf[_S2_BUF_SIZE];
    char    *str = "str";
    int    i;

    buf[0] = '\0';

    fprintf(stdout, "Test case 1:\n");
    for (i = 1; i < 4; i++) {
        fprintf(stdout, "\tPass[%d]: sizeof(buf)[%d], strlen(buf)[%d]\n", i, sizeof(buf), strlen(buf));
        strcat(buf, str);
    }

    fprintf(stdout, "\n");
}

static void run2() {
    char    buf[_S2_BUF_SIZE];
    char    *str = "+1234.6789";
    int    i = 0;

    buf[0] = '\0';

    fprintf(stdout, "Test case 2:\n");
    while ((sizeof(buf) - strlen(buf)) > strlen(str)) {
        strcat(buf, str);
        i++;
    }

    fprintf(stdout, "\tstrcat ran [%d] times\n", i);
    fprintf(stdout, "\tstr[%s]\n", str);
    fprintf(stdout, "\tbuf[%s]\n", buf);

    fprintf(stdout, "\n");
}

static void run3() {
    char    buf[_S2_BUF_SIZE];
    char    *str = NULL;

    str = (char *) calloc(_S2_BUF_SIZE, sizeof(char));

    fprintf(stdout, "Test case 3:\n");

    fprintf(stdout, "\tsizeof(buf)[%d], sizeof(str)[%d], sizeof(&str)[%d]\n", sizeof(buf), sizeof(str), sizeof(&str));

    fprintf(stdout, "\n");
}
