#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

#ifndef    DEFAULT_MAX
#define    DEFAULT_MAX    1000
#endif

#ifndef    DEFAULT_PID_F
#define    DEFAULT_PID_F    "sheep.pid"
#endif

#define    ACT_STOP    0x01
#define    ACT_START    0x02
#define    ACT_RESTART    0x04

static int running = 0;
static int tries = 0;

static int stopSheep(char *);

static void printSheep(FILE *, int);
static void printOffset(FILE *, int);
static void usage(FILE *, char *);
static int writePid(char *, int);

static void init_signals();
static void sighup();
static void sigint();

static void init_signals()
{
    signal(SIGINT, sigint);
    signal(SIGHUP, sighup);
}

static void sigint()
{
    signal(SIGINT, sigint);
    running = 0;
}

static void sighup()
{
    signal(SIGHUP, sighup);

    if (tries) {
        fprintf(stderr, "okay, okay... good night\n");
        running = 0;
    } else {
        fprintf(stderr, "someone tried to hangup\n");
    }

    tries++;
}

static void usage(FILE *fp, char *prog)
{
    fprintf(fp, "USAGE:\n");
    fprintf(fp, " %s --start|--restart [--count max] [--file filename]\n", prog);
    fprintf(fp, " %s --stop [--file filename]\n", prog);
    fprintf(fp, " %s --help\n", prog);
    fprintf(fp, "OPTIONS:\n");
    fprintf(fp, " --start\t\tstart the program (default)\n");
    fprintf(fp, " --stop\t\t\tstop the program\n");
    fprintf(fp, " --restart\t\tstop the current running programa and start again with new values\n");
    fprintf(fp, " --count max\t\tmaximum number to count to before resetting the counter\n");
    fprintf(fp, " --file filename\tname of file to read/write pid\n");
    fprintf(fp, " --help\t\t\tthis help menu\n");
}

static void printOffset(FILE *fp, int o)
{
    int i;

    for (i = 0; i < (o * 3); i++) {
        fprintf(fp, " ");
    }
}

static void printSheep(FILE *fp, int i)
{
    if (!fp) {
        fp = stdout;
    }

    printOffset(fp, (i % 10));
    fprintf(fp, "         _          \n");
    printOffset(fp, (i % 10));
    fprintf(fp, "    .-:'  `; `-._   \n");
    printOffset(fp, (i % 10));
    fprintf(fp, "   (_,           )  \n");
    printOffset(fp, (i % 10));
    fprintf(fp, " ,'o\"(            )>\n");
    printOffset(fp, (i % 10));
    fprintf(fp, "(__,-'   %3d      ) \n", (i % 1000));
    printOffset(fp, (i % 10));
    fprintf(fp, "   (             )  \n");
    printOffset(fp, (i % 10));
    fprintf(fp, "    `-'._.--._.-'   \n");
    printOffset(fp, (i % 10));
    fprintf(fp, "       |||  |||     \n");
}

int writePid(char *fname, int ok)
{
    FILE *fp = NULL;

    if (!fname) {
        fp = stdout;
    } else if (!(fp = fopen(fname, "w"))) {
        fprintf(stderr, "Failed to open pid file[%s]: %s\n", fname, strerror(errno));

        if (ok) {
            fp = stdout;
        } else {
            return (errno);
        }
    }

    fprintf(fp, "%d", getpid());

    if (fp != stdout) {
        fclose(fp);
    }

    return (0);
}

static int stopSheep(char *fname)
{
    int    pid = 0;
    int    i = 0;
    char    buf[8];
    FILE    *fp = NULL;

    if (!fname) {
        fprintf(stderr, "No pid file specified\n");
        return (-1);
    } else if (!(fp = fopen(fname, "r"))) {
        fprintf(stderr, "Cannot open pid file[%s] for reading: %s\n", fname, strerror(errno));
        return (errno);
    }

    if (fgets(buf, sizeof(buf), fp)) {
        if ((i = sscanf(buf, "%d", &pid) == 1)) {
            kill(pid, SIGINT);
        }
    }

    fclose(fp);
    remove(fname);

    return (0);
}

int main(int argc, char **argv)
{
    pid_t    pid;
    int    i;
    int    rc = 0;
    int    count = DEFAULT_MAX;
    FILE    *fp = NULL;
    char    *pid_file = DEFAULT_PID_F;
    int    action = 0;

    for (i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--stop")) {
            if (!action) {
                action = ACT_STOP;
            }
        } else if (!strcmp(argv[i], "--start")) {
            if (!action) {
                action = ACT_START;
            }
        } else if (!strcmp(argv[i], "--restart")) {
            if (!action) {
                action = ACT_RESTART;
            }
        } else if (!strcmp(argv[i], "--count")) {
            count = atoi(argv[++i]);
        } else if (!strcmp(argv[i], "--help")) {
            usage(stdout, argv[0]);
            return (0);
        } else if (!strcmp(argv[i], "--file")) {
            pid_file = argv[++i];
        }
    }

    switch (action) {
        case ACT_STOP:
            if (stopSheep(pid_file)) {
                fprintf(stderr, "WARNING: failed to stop sheep\n");
                return (1);
            } else {
                return (0);
            }

            break;
        case ACT_START:
        case ACT_RESTART:
            break;
    }

    pid = fork();

    if (pid > 0) {
        return (0);
    } else if (pid < 0) {
        fprintf(stderr, "ERROR: [%s]\n", strerror(errno));
        return (-1);
    }

    (void) setsid();

    if ((rc = writePid(pid_file, 0))) {
        return (rc);
    }

    init_signals();

    running = 1;

    i = 1;
    do {
        printSheep(stdout, i++);
        sleep(1);

        if (i > count) {
            i = 1;
        }
    } while (running);

    return (0);
}

