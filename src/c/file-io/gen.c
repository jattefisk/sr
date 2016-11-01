#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

#define _GEN_LAT_ 90
#define _GEN_LON_ 180

void decimalToMinutes(double decimal, char *coordinates, int lat_lon);
double getLatLon(int lat_lon);

/**
 * NOTES:
 *
 * double modf(double, *double);
 *
 */

int main(int argc, char **argv)
{
    char latM[16], lonM[16];
    char desc[32];
    char **f_words, **n_words;
    char c;
    unsigned int f_count, f_length, n_count, n_length;
    long int first_A, first_Z, last_a, last_z;
    double lat, lon;
    int i;
    int entries;
    int D_FLG = 0;
    char *D_ARG = NULL;
    int O_FLG = 0;
    FILE *O_ARG = NULL;
    FILE *fp, *output = NULL;

    while ((c = getopt(argc, argv, "d:f:hn:")) != -1) {
    switch (c) {
        case 'd':
        D_ARG = strdup(optarg);
        D_FLG = 1;
        break;
        case 'f':
        O_ARG = fopen(optarg, "w");
        O_FLG = 1;
        break;
        case 'h':
        (void) fprintf(stdout,
          "./gen\t-n XX [-f file.out] [-d dictionary]\n");
        (void) fprintf(stdout, "\t-d dictionary\tdictionary to use\n");
        (void) fprintf(stdout, "\t-f file.out\tOutput file\n");
        (void) fprintf(stdout, "\t-n XX\tGenerate XX entries\n");
        (void) fprintf(stdout, "./gen\t-h\n");
        (void) fprintf(stdout, "\tThis help message\n");
        exit(0);
        case 'n':
        entries = atoi(optarg);
        break;
    }
    }

    if (!O_ARG) {
    O_ARG = stdout;
    }

    srand(time(NULL));

    if (!D_ARG) {
    D_ARG = strdup("/usr/share/dict/american-english");
    }

    if (!(fp = fopen(D_ARG, "r"))) {
    (void) fprintf(stderr, "Failed to open dictionary %s\n", D_ARG);
    exit(1);
    }

    f_count = 0;
    n_count = 0;

    while (fgets(desc, 30, fp)) {
    if ((desc[0] >= 'A') && (desc[0] <= 'Z')) {
        f_count++;
    } else if ((desc[0] >= 'a') && (desc[0] <= 'z')) {
        n_count++;
    }
    }

    f_length = f_count;
    n_length = n_count;
    f_words = (char **)malloc(sizeof(char *)*f_length);
    n_words = (char **)malloc(sizeof(char *)*n_length);

    rewind(fp);
    f_count = 0;
    n_count = 0;

    while (fgets(desc, 30, fp)) {
    if ((desc[0] >= 'A') && (desc[0] <= 'Z')) {
        f_words[f_count++] = strndup(desc, (strlen(desc) - 1));
    } else if ((desc[0] >= 'a') && (desc[0] <= 'z')) {
        n_words[n_count++] = strndup(desc, (strlen(desc) - 1));
    }
    }

    for (i = 0; i < entries; i++) {
    lat = getLatLon(_GEN_LAT_);
    lon = getLatLon(_GEN_LON_);
    decimalToMinutes(lat, latM, _GEN_LAT_);
    decimalToMinutes(lon, lonM, _GEN_LON_);
    (void) fprintf(O_ARG, "%.6f;%.6f;%s;%s;%s %s %s\n",
      lat, lon, latM, lonM,
      f_words[rand() % f_length],
      n_words[rand() % n_length], n_words[rand() % n_length]);
    }

    if (O_FLG) {
    fclose(O_ARG);
    }

    return (0);
}

void decimalToMinutes(double decimal, char *coordinates, int lat_lon)
{
    double frac, deg, minutes, seconds;
    int r_val;
    char direction;

    switch (lat_lon) {
    case _GEN_LAT_:
        if (decimal < 0) {
        direction = 'S';
        decimal = decimal * -1;
        } else {
        direction = 'N';
        }
        break;
    case _GEN_LON_:
        if (decimal < 0) {
        direction = 'E';
        decimal = decimal * -1;
        } else {
        direction = 'W';
        }
        break;
    default:
        direction = 'D';
    }

    frac = modf(decimal, &deg);
    frac = frac * 60;
    frac = modf(frac, &minutes);
    seconds = frac * 60;

    r_val = sprintf(coordinates, "%.0f %.0f %.4f%c",
      deg, minutes, seconds, direction);
    if (r_val == EOF) {
    (void) fprintf(stderr, "Failed to write to string");
    }
}

double getLatLon(int lat_lon) {
    double decimal = sqrt(rand());
    double trash;

    decimal = modf(decimal, &trash);
    if (rand() % 2) {
    trash = -1;
    } else {
    trash = 1;
    }

    return (trash * ((rand() % lat_lon) + decimal));
}
