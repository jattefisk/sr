#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char     *s = NULL;
    int    i = 0;

    s = "hi";
    fprintf(stderr, "Length of [%s] is [%d]\n", s, strlen(s));

/* strlen(NULL) = segmentation fault */
#if 0
    s = NULL;
    fprintf(stderr, "Length of [%s] is [%d]\n", s, strlen(s));
#endif

    s = "bye";
    fprintf(stderr, "Length of [%s] is [%d]\n", s, strlen(s));

    s = "01";
    for (i = 0; i <= strlen(s); i++) {
        fprintf(stderr, "c%d[%c] ", i, s[i]);
    }
    fprintf(stderr, "\n");

    return (0);
}
