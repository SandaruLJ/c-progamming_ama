#include <stdio.h>
#include <stdlib.h>
#include "ex1_queue.h"

#define MAX_SIZE 100

static int queue[MAX_SIZE];
static int front, back, size = 0;

static void terminate(char *msg)
{
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}

void q_insert(int i)
{
    if (size == MAX_SIZE)
        terminate("Error in q_insert(): queue is full");

    queue[back++] = i;
    size++;

    if (back == MAX_SIZE)
        back = 0;
}

int q_remove()
{
    if (size == 0)
        terminate("Error in q_remove(): queue is empty");

    int val = queue[front++];
    size--;

    if (front == MAX_SIZE)
        front = 0;

    return val;
}

int q_first()
{
    return queue[front];
}

int q_last()
{
    return queue[back];
}

bool q_is_empty()
{
    return size == 0;
}

