#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    long    l;

    l = strtol("1", NULL, 10);
    fprintf(stderr, "strtol(1)[%ld]\n", l);

    l = atol("2");
    fprintf(stderr, "atol(2)[%ld]\n", l);

    l = atol(NULL);
    fprintf(stderr, "atol(NULL)[%ld]\n", l);

    l = strtol(NULL, NULL, 10);
    fprintf(stderr, "strtol(NULL)[%ld]\n", l);

    return (0);
}
