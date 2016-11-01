#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)
{
    time_t        now;
    time_t        today;
    struct tm    tms;
    char        buf[8];

    (void) memset((void *) &tms, 0, sizeof(struct tm));
    now = time(NULL);

    (void) gmtime_r(&now, &tms);
    (void) strftime(buf, sizeof(buf), "%y%m%d", &tms);

    (void) fprintf(stdout, "now\t[%ld]\n", now);
    (void) fprintf(stdout, "buf\t[%s]\n", buf);

    (void) memset((void *) &tms, 0, sizeof(struct tm));

    (void) strptime(buf, "%y%m%d", &tms);
    today = mktime(&tms);

    (void) fprintf(stdout, "today\t[%ld]\n", today);

    return (0);
}
