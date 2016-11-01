#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct S {
    char *msg;
} T;

int main(int argc, char **argv)
{
    char *s1 = NULL;
    char *s2 = NULL;
    T    t;

    if (argc < 2) {
        fprintf(stderr, "USAGE: %s str2 str2\n", argv[0]);
        return (1);
    }

    s1 = strcpy((char *) malloc(strlen(argv[1]) + 1), argv[1]);
    s2 = strcpy((char *) malloc(strlen(argv[2]) + 1), argv[2]);

    fprintf(stdout, "argv[1]\t%s\ns1\t%s\nargv[2]\t%s\ns2\t%s\n", argv[1], s1, argv[2], s2);

    t.msg = (char *) malloc((strlen(s1) + strlen(s2) + 2));

    sprintf(t.msg, "%s %s", s1, s2);

    fprintf(stdout, "%s\n", t.msg);

    return (0);
}
