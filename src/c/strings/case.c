#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int
main(int argc, char **argv)
{
    char    needle[16];
    char    haystack[64];
    char    *remainder;
    char    next[16];
    int    i;

    do {
        (void) fprintf(stdout, "Haystack: ");
        fgets(haystack, sizeof(haystack), stdin);
        for (i = 0; haystack[i]; i++) {
        if (haystack[i] == '\n') {
            haystack[i] = '\0';
            break;
        }
        }

        (void) fprintf(stdout, "Needle: ");
        fgets(needle, sizeof(needle), stdin);
        for (i = 0; needle[i]; i++) {
        if (needle[i] == '\n') {
            needle[i] = '\0';
            break;
        }
        }

        if (remainder = strcasestr(haystack, needle)) {
        (void) fprintf(stdout, "found [%s] in [%s]\n",
          needle, haystack);
        (void) fprintf(stdout, "remainder [%s]\n", remainder);
        } else {
        (void) fprintf(stdout, "no needles here\n");
        }

        (void) fprintf(stdout, "Continue? ");
        fgets(next, sizeof(next), stdin);
    } while (tolower(next[0]) != 'n');

    return (0);
}
