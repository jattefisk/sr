#include <stdio.h>
#include <stdlib.h>

void helper();

int main(int argc, char **argv)
{
    FILE *fp = NULL;

    fp = fopen("redirect.out", "w");

    fprintf(stderr, "Writing to stderr\n");
    fprintf(fp, "Writing to fp\n");

    stderr = fp;

    fprintf(stderr, "Writing to stderr after assigning to fp\n");
    fprintf(fp, "Writing to fp after assigning stderr to fp\n");

    helper();

    return (0);
}

void helper()
{
    fprintf(stderr, "helper writing to stderr\n");
}

