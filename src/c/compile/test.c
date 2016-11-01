#include <stdlib.h>
#include <stdio.h>

#ifdef    T1
#define    STR    "t1"
#else
#define    STR    "undefined"
#endif

int main(int argc, char **argv)
{
    fprintf(stdout, "STR[%s]\n", STR);

    return (0);
}

