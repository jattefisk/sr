#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int i;

    for (i = 0; i < 10; i++) {
        if (i % 2) {
            continue;
        }

        fprintf(stdout, "i[%d]\n", i);
    }

    return (0);
}

