#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main(int argc, char **argv)
{
    struct tm    *t;
    struct tm    *g;
    time_t        *now;
    time_t        neg;
    FILE        *fp;

#if 0
    now = (time_t *) calloc(1, sizeof(time_t));

    if (time(now) == -1) {
        (void) fprintf(stderr, "Failed to get current time\n");
        return (1);
    }

    fprintf(stdout, "now[%ld]\n", now);

    fprintf(stdout, "set local time...\n");
    t = localtime(now);

    fprintf(stdout, "loc[%.2d:%.2d:%.2d on %.4d-%.2d-%.2d]\n",
        t->tm_hour, t->tm_min, t->tm_sec,
        (t->tm_year + 1900), (t->tm_mon + 1), t->tm_mday);
    fprintf(stdout, "gmtoff[%d]\n", t->tm_gmtoff);

    fprintf(stdout, "\nset gm time...\n");
    g = gmtime(now);
    fprintf(stdout, "gmt[%.2d:%.2d:%.2d on %.4d-%.2d-%.2d]\n",
        g->tm_hour, g->tm_min, g->tm_sec,
        (g->tm_year + 1900), (g->tm_mon + 1), g->tm_mday);
    fprintf(stdout, "gmtoff[%d]\n", g->tm_gmtoff);

    fprintf(stdout, "\nset local time...\n");
    t = localtime(now);

    fprintf(stdout, "loc[%.2d:%.2d:%.2d on %.4d-%.2d-%.2d]\n",
        t->tm_hour, t->tm_min, t->tm_sec,
        (t->tm_year + 1900), (t->tm_mon + 1), t->tm_mday);
    fprintf(stdout, "gmtoff[%d]\n", t->tm_gmtoff);
    fprintf(stdout, "gmt[%.2d:%.2d:%.2d on %.4d-%.2d-%.2d]\n",
        g->tm_hour, g->tm_min, g->tm_sec,
        (g->tm_year + 1900), (g->tm_mon + 1), g->tm_mday);
    fprintf(stdout, "gmtoff[%d]\n", g->tm_gmtoff);

    fprintf(stdout, "\nset local time...\n");
    t = localtime(now);
    fprintf(stdout, "set gm time...\n");
    g = gmtime(now);

    fprintf(stdout, "loc[%.2d:%.2d:%.2d on %.4d-%.2d-%.2d]\n",
        t->tm_hour, t->tm_min, t->tm_sec,
        (t->tm_year + 1900), (t->tm_mon + 1), t->tm_mday);
    fprintf(stdout, "gmtoff[%d]\n", t->tm_gmtoff);
    fprintf(stdout, "gmt[%.2d:%.2d:%.2d on %.4d-%.2d-%.2d]\n",
        g->tm_hour, g->tm_min, g->tm_sec,
        (g->tm_year + 1900), (g->tm_mon + 1), g->tm_mday);
    fprintf(stdout, "gmtoff[%d]\n", g->tm_gmtoff);

#endif
    neg = -1;
    fprintf(stdout, "neg[%ld]\n", neg);
    fprintf(stdout, "set local time...\n");
    t = localtime(&neg);

    fprintf(stdout, "loc[%.2d:%.2d:%.2d on %.4d-%.2d-%.2d]\n",
        t->tm_hour, t->tm_min, t->tm_sec,
        (t->tm_year + 1900), (t->tm_mon + 1), t->tm_mday);
    fprintf(stdout, "gmtoff[%d]\n", t->tm_gmtoff);

    return (0);
}
