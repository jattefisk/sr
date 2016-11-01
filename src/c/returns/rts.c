#include <stdlib.h>
#include <stdio.h>

typedef struct rtsS {
    char c;
    int i;
} rtsT;

typedef struct outerS {
    rtsT    data[5];
} outerT;

rtsT createRts(int, char);

int main(int argc, char **argv)
{
    int i;
//    rtsT rts;
    outerT    ot;

    for (i = 0; i < 5; i++) {
        ot.data[i] = createRts((70 + i), (char) (70 + i));

    }

    for (i = 0; i < 5; i++) {
        fprintf(stderr, "%p[%d][%c]\n", ot.data[i], ot.data[i].i,
            ot.data[i].c);
    }

    return (0);

}

rtsT createRts(int i, char c)
{
    rtsT rv;

    rv.i = i;
    rv.c = c;

    return (rv);
}
