#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc < 3) {
        fprintf(stderr, "USAGE: %s <str1> <str2>\n", argv[0]);
        return (1);
    }

    fprintf(stdout, "strcmp(\"%s\", \"%s\") = %d\n", argv[1], argv[2],
        strcmp(argv[1], argv[2]));

    return (0);
}
