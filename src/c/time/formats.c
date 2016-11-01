#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)
{
    char    *fmt_s = "%y-%m-%d";
    char    *fmt_l = "%y-%m-%d %H:%M";
    char    output_s[32];
    char    output_l[32];
    char    day[4];
    time_t    now;
    time_t    st_t;
    time_t    en_t;
    struct tm    *tms = NULL;
    struct tm    *tms_st = NULL;
    struct tm    *tms_en = NULL;

    tms = (struct tm *) calloc(1, sizeof(struct tm));
    tms_st = (struct tm *) calloc(1, sizeof(struct tm));
    tms_en = (struct tm *) calloc(1, sizeof(struct tm));
    memset((void *) tms_st, 0, sizeof(struct tm));
    memset((void *) tms_en, 0, sizeof(struct tm));

    now = time(NULL);
    tms = localtime(&now);

    strftime(output_s, 32, fmt_s, tms);
    strftime(output_l, 32, fmt_l, tms);

    fprintf(stderr, "now[%lu], output_s[%s], output_l[%s]\n",
        now, output_s, output_l);

    strptime(output_s, fmt_s, tms_st);
    st_t = mktime(tms_st);
    strftime(output_s, 32, fmt_s, tms_st);
    strftime(output_l, 32, fmt_l, tms_st);

    fprintf(stderr, "st_t[%lu], output_s[%s], output_l[%s]\n",
        st_t, output_s, output_l);

    strcpy(output_l, output_s);
    strcat(output_l, " 23:59");

    strptime(output_l, fmt_l, tms_en);
    en_t = mktime(tms_en);
    strftime(output_s, 32, fmt_s, tms_en);
    strftime(output_l, 32, fmt_l, tms_en);

    fprintf(stderr, "en_t[%lu], output_s[%s], output_l[%s]\n",
        en_t, output_s, output_l);

    fprintf(stderr, "en_t - st_t = %lu\n", (en_t - st_t));
    fprintf(stderr, "60 * 60 * 24 = %d\n", (60 * 60 * 24));

//    snprintf(day, 3, &output_s[6]);
//    fprintf(stderr, "day[%s], day[%d]\n", day, atoi(day));


    return (0);
}

