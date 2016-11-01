#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ptrs(char **str1, char **str2);
void ptrs1(char *, char);

int main(int argc, char **argv)
{
    char *str1;
    char *str2;

//    ptrs(&str1, &str2);
    ptrs1("hostname", ':');
    ptrs1("hostname:port", ':');

    return (0);
}

void ptrs1(char *str, char c) {
    char    buf[80];
    char    *s = NULL;

    strcpy(buf, str);

    if (s = strchr(buf, c)) {
        fprintf(stdout, "buf[%s]\ns[%s]\n", buf, s);

        *s = '\0';
        s++;
        fprintf(stdout, "->replace char[%c] with null\n", c);

        fprintf(stdout, "buf[%s]\ns[%s]\n", buf, s);
    } else {
        fprintf(stdout, "replace char[%c] not found in str[%s]\n",
            c, str);
    }
}

void ptrs(char **str1, char **str2)
{
    *str1 = "test";
    *str2 = NULL;

    fprintf(stderr, "str1[%s]\n", *str1);
    fprintf(stderr, "str2[%s]\n", *str2);
}
