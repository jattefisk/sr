#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

int main(int argc, char **argv)
{
    time_t        now;
    struct tm    *tms;
    char        *fmt = "%Y-%d-%m %H:%M:%S";
    char        buf[64];

    now = time(NULL);
    tms = localtime(&now);
    strftime(buf, sizeof(buf), fmt, tms);
    fprintf(stderr, "BEFORE: time_t[%lu] time[%s] gmtoff[%lu] tz[%s]\n",
         now, buf, tms->tm_gmtoff, tms->tm_zone);

    now -= 3600;
    tms = localtime(&now);
    strftime(buf, sizeof(buf), fmt, tms);
    fprintf(stderr, "-3600:  time_t[%lu] time[%s] gmtoff[%lu] tz[%s]\n",
         now, buf, tms->tm_gmtoff, tms->tm_zone);

    setenv("TZ", "UTC+00:00", 1);

    now = time(NULL);
    tms = localtime(&now);
    strftime(buf, sizeof(buf), fmt, tms);
    fprintf(stderr, "AFTER:  time_t[%lu] time[%s] gmtoff[%lu] tz[%s]\n",
         now, buf, tms->tm_gmtoff, tms->tm_zone);


}
