#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char    buf[64];

    strcpy(buf, "Escaped space: [\s]");
    fprintf(stderr, "%s\n", buf);
    strcpy(buf, "Escaped space: [\\s]");
    fprintf(stderr, "%s\n", buf);
    strcpy(buf, "Escaped space: [\\\\s]");
    fprintf(stderr, "%s\n", buf);

    return (0);
}

