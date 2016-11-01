#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

typedef struct threadArgS {
    int    i;
    char    *s;
    struct threadArgS    *next;
} threadArgT;

static void *crash_it(void *);

int
main(int argc, char **argv)
{
    pthread_t    tid;
    threadArgT    *ta;

    ta = (threadArgT *) calloc(1, sizeof(threadArgT));

    ta->i = 1;
    ta->s = "one";
    ta->next = NULL;

    pthread_create(&tid, NULL, crash_it, (void *) ta);

    while (1) {
        fprintf(stderr, "main printing...\n");

        sleep (2);
    }

    pthread_exit(NULL);
}


static void *
crash_it(void *t_args)
{
    threadArgT    *ta = (threadArgT *) t_args;

    pthread_detach(pthread_self());

    fprintf(stderr, "%s[%d]\n", ta->s, ta->i);
    fprintf(stderr, "next: %s[%d]", ta->next->s, ta->next->i);

    pthread_exit(NULL);
}

