/**
 *    \file passing.c
 *
 *    Prototype to see about passing pointers by reference
 *    with regards to allocation/deallocation of memory.
 *
 *    \date        03-Feb-2010
 *    \author        Jonathan France
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * \brief Generic list structure.
 */
typedef struct listS {
    char        *text;    ///< text field
    int        id;    ///< int field
    struct listS    *next;    ///< next in the list
} listT;


void printList(listT *);
listT *copyList(listT *);
void freeList(listT *);
void copyAndFree(listT **);


/**
 *    \brief Starting point.
 *
 *    \param    argc    program argument count
 *    \param    argv    program arguments
 *    \return        exit status
 */
int main(int argc, char **argv)
{
    int i = 0;
    listT *First = NULL;
    listT *Second = NULL;
    listT *Third = NULL;

    for (i = 1; i < argc; i++) {
        fprintf(stdout, "Received command line argument[%s]\n",
            argv[i]);
    }
    Third = (listT *) calloc(1, sizeof(listT));

    if (!Third) {
        return (1);
    }
    free(Third->text);
    Third->text = strdup("Third node");
    Third->id = 3;
    free(Third->next);
    Third->next = NULL;

    Second = (listT *) calloc(1, sizeof(listT));
    if (!Second) {
        free(Third->text);
        free(Third->next);
        free(Third);
        return (1);
    }
    free(Second->text);
    Second->text = strdup("Second node");
    Second->id = 2;
    free(Second->next);
    Second->next = Third;

    First = (listT *) calloc(1, sizeof(listT));
    if (!First) {
        free(Third->text);
        free(Third->next);
        free(Second->text);
        free(Second->next);
        free(Second);
        return (1);
    }
    free(First->text);
    First->text = strdup("First node");
    First->id = 1;
    free(First->next);
    First->next = Second;

    printList(First);
    fprintf(stderr, "\n");
    copyAndFree(&First);
    printList(First);

    free(Third->text);
    free(Third->next);
    free(Second->text);
    free(Second->next);
    free(First->text);
    free(First->next);
    free(First);

    return (0);
}


/**
 *    \brief Print the list.
 *
 *    Recursively travsere a list, printing out the memory
 *    addresses of each node in order fromfirst to last.
 *
 *    \param    head    starting node to print
 */
void printList(listT *head)
{
    while (head) {
        fprintf(stderr, "%s\t[%p], text[%p]\n",
            head->text, head, head->text);

        head = head->next;
    }
}


void copyAndFree(listT **head)
{
    listT *node = NULL;

    node = *head;
    *head = copyList(node);
    freeList(node);
}


void freeList(listT *node)
{
    if (node) {
        freeList(node->next);
        free(node->text);
        free(node);
    }
}


listT *copyList(listT *head)
{
    listT *node = NULL;

    if (head) {
        node = (listT *) calloc(1, sizeof(listT));

        if (head->text) {
            free(node->text);
            node->text = strdup(head->text);
        }
        node->id = head->id;
        free(node->next);
        node->next = copyList(head->next);
    }

    return (node);
}
