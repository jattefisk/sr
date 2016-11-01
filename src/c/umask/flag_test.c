#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
    FILE *fp = NULL;

    if (fp = fopen("file1.out", "w")) {
        fprintf(fp, "006\n");
        fclose(fp);
    }

    umask(S_IRUSR|S_IWUSR);
    if (fp = fopen("file2.out", "w")) {
        fprintf(fp, "(S_IRUSR|S_IWUSR)\n");
        fclose(fp);
    }

    umask(S_IRUSR|S_IWUSR|S_IWGRP);
    if (fp = fopen("file3.out", "w")) {
        fprintf(fp, "(S_IRUSR|S_IWUSR|S_IWGRP)\n");
        fclose(fp);
    }

    umask(S_IROTH|S_IWOTH);
    if (fp = fopen("file4.out", "w")) {
        fprintf(fp, "(S_IROTH|S_IWOTH)\n");
        fclose(fp);
    }

    return (0);
}

