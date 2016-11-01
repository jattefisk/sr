#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char    *s = NULL;
    char    *t = NULL;
    int    i;
    int    j;
    int    x = 0;

    fprintf(stderr, "strlen(NULL)[%d]\n", strlen(s));
    return (0);

    if (argc > 1) {
        s = argv[1];
    } else {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return (1);
    }

    fprintf(stderr, "s\t\t[%s]\n", s);
    fprintf(stderr, "s size\t\t[%d]\n", sizeof(&s));
    fprintf(stderr, "s length\t[%d]\n", strlen(s));

    if (strchr(s, '\'')) {
        fprintf(stderr, "FOUND A QUOTE\n");
    }

    t = (char *) calloc(((strlen(s) * 2) + 1), sizeof(char));

    fprintf(stderr, "t\t\t[%s]\n", t);
    fprintf(stderr, "t size\t\t[%d]\n", sizeof(&t));
    fprintf(stderr, "t length\t[%d]\n", strlen(t));

    for (i = 0, j = 0; i < strlen(s); i++, j++) {
        switch (s[i]) {
        case '"':
        case '\'':
        case '\\':
            t[j] = '\\';
            x = 1;
            break;
        }

        if (x) {
            x = 0;
            j++;
        }

        t[j] = s[i];

    }

    t[j] = '\0';

    fprintf(stderr, "t*\t\t[%s]\n", t);
    fprintf(stderr, "t* size\t\t[%d]\n", sizeof(&t));
    fprintf(stderr, "t* length\t[%d]\n", strlen(t));

    for (i = 0; i < strlen(t); i++) {
        fprintf(stderr, "%c", t[i]);
    }

    return (0);
}
