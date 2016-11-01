#include <stdlib.h>
#include <stdio.h>

static void math_test1(FILE *, int, int);
static void math_test2(FILE *, int, int);

int main(int argc, char **argv)
{
#if 0
    int a = 4;
    int b = 2;
    int x = 0;
    int z = 0;

    x = a / b;

    fprintf(stderr, "%d / %d = %d\n", a, b, x);

    x = z / a;

    fprintf(stderr, "%d / %d = %d\n", z, a, x);

    x = a / z;

    fprintf(stderr, "%d / %d = %d\n", a, z, x);
#endif

    math_test1(stdout, 10, 5);
    math_test2(stdout, 10, 5);
    math_test1(stdout, 5, 10);
    math_test2(stdout, 5, 10);
    math_test1(stdout, 5, 11);
    math_test2(stdout, 5, 11);
    math_test1(stdout, 11, 5);
    math_test2(stdout, 11, 5);

    return (0);
}

static void math_test1(FILE *fp, int i, int j)
{
    int    result = 0;

    result = i / j;

    fprintf(fp, "i[%d] / j[%d] = result[%d]\n", i, j, result);
}

static void math_test2(FILE *fp, int i, int j)
{
    int    result = 0;

    result = i % j;

    fprintf(fp, "i[%d] % j[%d] = result[%d]\n", i, j, result);
}


