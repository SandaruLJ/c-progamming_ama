#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct node
{
    int data;
    struct node *next;
};

struct queue_type
{
    struct node *front, *back;
};

static void terminate(const char *msg)
{
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}

Queue q_create(void)
{
    Queue q = malloc(sizeof (struct queue_type));
    if (q == NULL)
        terminate("Error in q_create: queue could not be created.");

    q->front = q->back = NULL;

    return q;
}

void q_destroy(Queue q)
{
    q_make_empty(q);
    free(q);
}

void q_make_empty(Queue q)
{
    while (!q_is_empty(q))
        q_remove(q);
}

bool q_is_empty(Queue q)
{
    return q->front == NULL;
}

bool q_is_full(Queue q)
{
    return false;
}

int q_first(Queue q)
{
    if (q->front == NULL)
        terminate("Error in q_first: queue is empty.");
    return q->front->data;
}

int q_last(Queue q)
{
    if (q->back == NULL)
        terminate("Error in q_first: queue is empty.");
    return q->back->data;
}

void q_insert(Queue q, int i)
{
    struct node *new_node = malloc(sizeof (struct node));
    if (new_node == NULL)
        terminate("Error in q_insert: could not allocate memory.");

    new_node->data = i;
    new_node->next = NULL;
    
    if (q->back != NULL)
        q->back->next = new_node;
    q->back = new_node;

    if (q->front == NULL)
        q->front = new_node;
}

int q_remove(Queue q)
{
    if (q_is_empty(q))
        terminate("Error in q_remove: queue is empty.");

    struct node *old_front = q->front;

    int i = old_front->data;
    q->front = old_front->next;

    free(old_front);

    if (q->front == NULL)
        q->back = NULL;  // avoid dangling pointer situation

    return i;
}

