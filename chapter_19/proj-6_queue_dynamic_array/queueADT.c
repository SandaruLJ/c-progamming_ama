#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct queue_type
{
    int *data;
    int front, back, maxlen, len;
};

static void terminate(const char *msg)
{
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}

Queue q_create(int len)
{
    int *data = malloc(sizeof (int) * len);
    if (data == NULL)
        terminate("Error in q_create: queue could not be created");

    Queue q = malloc(sizeof (struct queue_type));
    if (q == NULL)
    {
        free(data);
        terminate("Error in q_create: queue could not be created.");
    }

    q->data = data;
    q->maxlen = len;
    q->front = q->back = q->len = 0;

    return q;
}

void q_destroy(Queue q)
{
    free(q->data);
    free(q);
}

void q_make_empty(Queue q)
{
    q->front = q->back = q->len = 0;
}

bool q_is_empty(Queue q)
{
    return q->len == 0;
}

bool q_is_full(Queue q)
{
    return q->len == q->maxlen;
}

int q_first(Queue q)
{
    return q->data[q->front];
}

int q_last(Queue q)
{
    return q->data[q->back];
}

void q_insert(Queue q, int i)
{
    if (q_is_full(q))
        terminate("Error in q_insert: queue is full.");

    q->data[q->back] = i;

    if (++q->back == q->maxlen)
        q->back = 0;

    q->len++;
}

int q_remove(Queue q)
{
    if (q_is_empty(q))
        terminate("Error in q_remove: queue is empty.");

    int i = q->data[q->front];

    if (++q->front == q->maxlen)
        q->front = 0;

    q->len--;
    return i;
}

