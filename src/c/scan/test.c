#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char    buf[4][256];
    int    rv;
    int    i;
    int    i1, i2, i3, i4, i5;

    snprintf(buf[0], sizeof(buf[0]), "ob\tturn 1 550\t510\t0\n");
    snprintf(buf[1], sizeof(buf[1]), "#ob\tturn 2 550\t510\t0\n");
    snprintf(buf[2], sizeof(buf[2]), "ob\tturn 3 (030) 550\t510\t0\n");
    snprintf(buf[3], sizeof(buf[3]), "ob\tturn 4 (400) 550\t510\t0\n");

    for (i = 0; i < 4; i++) {
        if (strchr(buf[i], '(')) {
            rv = sscanf(buf[i], "ob\tturn%d (%d)%d%d%d", &i1, &i2, &i3, &i4, &i5);
        } else {
            rv = sscanf(buf[i], "ob\tturn%d %d%d%d", &i1, &i2, &i3, &i4);
        }

        fprintf(stdout, "\n%s->sscanf(", buf[i]);

        switch (rv) {
        case 5:
            fprintf(stdout, "i5[%d], ", i5);
        case 4:
            fprintf(stdout, "i4[%d], ", i4);
        case 3:
            fprintf(stdout, "i3[%d], ", i3);
        case 2:
            fprintf(stdout, "i2[%d], ", i2);
        case 1:
            fprintf(stdout, "i1[%d]", i1);
            break;
        default:
            fprintf(stdout, "NO MATCHES");
        }

        fprintf(stdout, ")\n");
    }

/*
    snprintf(buf, sizeof(buf), "#ob\tturn 2 550\t510\t0\n");
    if ((rv = sscanf(buf, "ob\tturn%d %d%d%d", &i1, &i2, &i3, &i4)) == 4) {
        fprintf(stdout, "%s->sscanf(i1[%d], i2[%d], i3[%d], i4[%d]\n",
            buf, i1, i2, i3, i4);
    } else {
        fprintf(stdout, "%s->matched fields[%d]\n", buf, rv);
    }
*/

    return (0);
}

