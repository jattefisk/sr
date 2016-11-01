#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct tokenS {
    char        *key;
    char        *value;
    struct tokenS    *next;
} tokenT;


int main(int argc, char **argv)
{
    int    i = 0;
    char    *fn = NULL;
    char    *line = NULL;
    char    buf[1024];
    FILE    *fp = NULL;

    for (i = 1; i <argc; i++) {
        if (!strcmp("--file", argv[i])) {
            fn = strdup(argv[++i]);
        } else {
            fprintf(stderr, "ERROR: unknown argument[%s]\n", argv[i]);
            return (1);
        }
    }

    if (!fn) {
        fprintf(stderr, "ERROR: filename required\n");
        return (2);
    }

    i = 1;

    fp = fopen(fn, "r");

    while ((line = fgets(buf, sizeof(buf), fp)) != NULL) {
        fprintf(stdout, "[%d] %s", i++, line);
    }

    fclose(fp);
}

