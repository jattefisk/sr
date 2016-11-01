#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <errno.h>

static char    *logfile;
pthread_mutex_t    write_log_lock;

typedef struct threadArgS {
    int    i;
} threadArgT;

static void *writeLog(void *);

int main(int argc, char **argv)
{
    int i = 0;
    int rc = 0;
    char    buf[10];
    pthread_t    thread;
    threadArgT    *ta;
    logfile = "./threadLocking.txt";

    srand(time(NULL));

    if (rc = pthread_mutex_init(&write_log_lock, NULL)) {
        fprintf(stderr, "failed to aquire mutex lock[%d]\n", rc);
        return (rc);
    }

    for (i = 0; i < 100; i++) {
        ta = (threadArgT *) calloc(1, sizeof(threadArgT));
        ta->i = i;

        pthread_create(&thread, NULL, writeLog, (void *) ta);
    }

#if 0
    while (rc = pthread_mutex_destroy(&write_log_lock)) {
        switch (rc) {
        case EBUSY:
            fprintf(stdout, "waiting for mutex lock to clear\n");
            break;
        case EINVAL:
            goto pmd_out;
            break;
        default:
            fprintf(stdout, "unknown exit code for pthread_mutex_destroy[%d]\n", rc);
        }
    }
pmd_out:
#endif

    pthread_exit(NULL);
}

static void *writeLog(void *args)
{
    FILE        *fp = NULL;
    threadArgT    *ta = (threadArgT *) args;

    pthread_detach(pthread_self());

    sleep(rand() % 2);

    while (pthread_mutex_trylock(&write_log_lock)) {
        fprintf(stderr, "[%ld] waiting for write lock\n", pthread_self());
    }

    fp = fopen(logfile, "a");
    if (!fp) {
        goto wl_thr_cleanup;
    }

    fprintf(fp, "[%ld] [%d]\n", pthread_self(), ta->i);

    fflush(fp);
    fclose(fp);

wl_thr_cleanup:
    pthread_mutex_unlock(&write_log_lock);
    pthread_exit(NULL);
}
