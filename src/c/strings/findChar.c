#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char    *s = argv[1];

    fprintf(stderr, "string[%s]\n", s);

    if (strchr(s, '"')) {
        fprintf(stderr, "has double quote\n");
    }

    if (strchr(s, '\'')) {
        fprintf(stderr, "has single quote\n");
    }

    if (!strchr(s, '\'') && !strchr(s, '"')) {
        fprintf(stderr, "no quotes\n");
    }

    return (0);
}
