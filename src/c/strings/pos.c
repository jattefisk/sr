#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char    *a1 = "ABCD";
    char    *a2 = "AB/CD";
    char    *a3 = "ABC/DEF/GHI";
    char    *a4 = "";
    size_t    t;

    t = strcspn(a1, "/");
    fprintf(stderr, "a1[%s], t[%d], len[%d]\n", a1, t, strlen(a1));
    t = strcspn(a2, "/");
    fprintf(stderr, "a2[%s], t[%d], len[%d]\n", a2, t, strlen(a2));
    t = strcspn(a3, "/");
    fprintf(stderr, "a3[%s], t[%d], len[%d]\n", a3, t, strlen(a3));
    t = strcspn(a4, "/");
    fprintf(stderr, "a4[%s], t[%d], len[%d]\n", a4, t, strlen(a4));

    return (0);
}
