#include <stdio.h>

int main(int argc, char **argv)
{
    unsigned char c = 0;

    fprintf(stdout, "%%c\t0x%%x\t%%hd\n");
    fprintf(stdout, "--\t----\t---\n");
    for (c = 0; c != 255; c++) {
        fprintf(stdout, "[%c]\t[0x%x]\t[%hd]\n", c, c, c);
    }
    fprintf(stdout, "[%c]\t[0x%x]\t[%hd]\n", c, c, c);

/*
    fprintf(stdout, "%%c\t%%x\t%%hd\n");
    c = 0x0;
    fprintf(stdout, "[%c]\t[%x]\t[%hd]\n", c, c, c);
    c = 0x1;
    fprintf(stdout, "[%c]\t[%x]\t[%hd]\n", c, c, c);
    c = 0x2;
    fprintf(stdout, "[%c]\t[%x]\t[%hd]\n", c, c, c);
    c = 0x3;
    fprintf(stdout, "[%c]\t[%x]\t[%hd]\n", c, c, c);

    fprintf(stdout, "c[%ld] 0x0[%ld]\n", c, 0x0);
    c = 0x1;
    fprintf(stdout, "c[%ld] 0x1[%ld]\n", c, 0x1);
    c = 0x2;
    fprintf(stdout, "c[%ld] 0x2[%ld]\n", c, 0x2);
    c = 0x3;
    fprintf(stdout, "c[%ld] 0x3[%ld]\n", c, 0x3);

    if (c & 0x1) {
        fprintf(stdout, "c[%ld] & 0x1\n", c);
    }
    if (c & 0x2) {
        fprintf(stdout, "c[%ld] & 0x2\n", c);
    }
*/

    return (0);
}
