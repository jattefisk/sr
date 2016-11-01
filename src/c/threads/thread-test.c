#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#define    MAX_THREADS 5

typedef struct thread_arg_s {
    char        *ab;
    pthread_t    *id;
} thread_arg_t;

void *printIt(void *);

int
main(int argc, char **argv)
{
    char    a;
    char    b;
    char    *ab;

    int    found = 0;
    int    i = 0;

    pthread_t    tids[MAX_THREADS];
    thread_arg_t    *targs[MAX_THREADS];

    srand(time(NULL));

    for (i = 0; i < MAX_THREADS; i++) {
        tids[i] = 0;
        targs[i] = (thread_arg_t *) calloc(1, sizeof(thread_arg_t));
        targs[i]->id = &tids[i];
    }

    for (a = 'A'; a <= 'F'; a++) {
        for (b = 'A'; b <= 'F'; b++) {

            ab = (char *) calloc(3, sizeof(char));
            ab[0] = a;
            ab[1] = b;
            ab[2] = '\0';

            fprintf(stderr, "main: %s\n", ab);

            found = 0;
            while (!found) {
                for (i = 0; i < MAX_THREADS; i++) {
                    if (tids[i]) {
                        continue;
                    }

                    found = 1;
                    free(targs[i]->ab);
                    targs[i]->ab = ab;
                    pthread_create(&tids[i], NULL,
                        printIt, (void *) targs[i]);
                    break;
                }
            }
        }
    }

    pthread_exit(NULL);
}

void *
printIt(void *arg)
{
    thread_arg_t    *t_arg = (thread_arg_t *) arg;
    char        *ab = (char *) t_arg->ab;
    pthread_t    *t_id = (pthread_t *) t_arg->id;

    pthread_detach(pthread_self());
    sleep(rand() % MAX_THREADS);
    fprintf(stderr, "thread: ab[%s]\n", ab);
    *t_id = 0;

    pthread_exit(NULL);
}
