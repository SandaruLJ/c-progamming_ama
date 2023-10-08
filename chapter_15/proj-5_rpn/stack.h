#ifndef STACK_H
#define STACK_H

/* shared variables */
extern char stack[];
extern int top;

/* function prototypes */
void push(char ch);
char pop(void);
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void stack_overflow(void);
void stack_underflow(void);

#endif