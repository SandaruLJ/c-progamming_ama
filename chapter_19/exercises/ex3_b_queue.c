#include <stdio.h>
#include <stdlib.h>
#include "ex1_queue.h"

struct node
{
    int data;
    struct node *next;
} *front, *back = NULL;

static void terminate(char *msg)
{
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}

void q_insert(int i)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in q_insert(): failed to allocate memory");

    new_node->data = i;
    new_node->next = NULL;

    if (back != NULL)
        back->next = new_node;
    back = new_node;

    if (front == NULL)
        front = new_node;
}

int q_remove()
{
    if (front == NULL)
        terminate("Error in q_remove(): queue is empty");

    int val = front->data;

    struct node *old_front = front;
    front = front->next;
    free(old_front);

    // Prevent dangling pointer
    if (front == NULL)
        back = NULL;

    return val;
}

int q_first()
{
    if (front == NULL)
        terminate("Error in q_first(): queue is empty");

    return front->data;
}

int q_last()
{
    if (back == NULL)
        terminate("Error in q_last(): queue is empty");

    return back->data;
}

bool q_is_empty()
{
    return front == NULL;
}

