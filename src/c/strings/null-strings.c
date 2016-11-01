#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char    buf[1024];
    char    *s = NULL;

    sprintf(buf, "null string[%s]\n", s);
    fprintf(stderr, "%s", buf);

    s = "NULL";
    sprintf(buf, "null string[%s]\n", s);
    fprintf(stderr, "%s", buf);

    s = "";
    strcpy(buf, s);
    fprintf(stderr, "strcpy(NULL)\n");

    snprintf(buf, sizeof(s), "%s", s);
    fprintf(stderr, "snprintf(buf, sizeof(s), \"%s\"\n");

    return (0);
}

