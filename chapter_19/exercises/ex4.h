#include <stdbool.h>

typedef struct stack_type *Stack;
typedef int Item;

Stack stack_create();
void stack_destroy(Stack);
void stack_push(Stack, Item);
Item stack_pop(Stack);
void stack_make_empty(Stack);
bool stack_is_full(Stack);
bool stack_is_empty(Stack);

