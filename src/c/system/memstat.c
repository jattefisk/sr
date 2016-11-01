#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    time_t    t;
    char    buf1[40];
    char    buf2[40];
    char    fp1[32];
    char    fp2[32];
    char    name1[40];
    char    name2[40];
    FILE     *fp = NULL;

    if (argc < 2) {
        sprintf(fp1, "/proc/%s/statm", argv[1]);
    }

    if (argc < 3) {
        sprintf(fp2, "/proc/%s/statm", argv[2]);
    }

    while (1) {


}

