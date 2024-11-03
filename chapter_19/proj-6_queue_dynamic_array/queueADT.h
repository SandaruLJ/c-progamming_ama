#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef struct queue_type *Queue;

Queue q_create(int);
void q_destroy(Queue);
void q_make_empty(Queue);
bool q_is_empty(Queue);
bool q_is_full(Queue);
int q_first(Queue);
int q_last(Queue);
void q_insert(Queue, int);
int q_remove(Queue);

#endif

