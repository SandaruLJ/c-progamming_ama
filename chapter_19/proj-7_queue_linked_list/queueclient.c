#include <stdio.h>
#include "queueADT.h"

int main(void)
{
    Queue q1, q2;
    int n;

    q1 = q_create();
    q2 = q_create();

    q_insert(q1, 1);
    q_insert(q1, 2);

    n = q_remove(q1);
    printf("Removed %d from q1\n", n);
    q_insert(q2, n);
    n = q_remove(q1);
    printf("Removed %d from q1\n", n);
    q_insert(q2, n);

    q_destroy(q1);

    while (!q_is_empty(q2))
        printf("Removed %d from q2\n", q_remove(q2));

    q_insert(q2, 4);
    q_make_empty(q2);
    if (q_is_empty(q2))
        printf("q2 is empty\n");
    else
        printf("q2 is not empty\n");

    q_destroy(q2);

    return 0;
}

