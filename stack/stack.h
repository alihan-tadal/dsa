#ifndef STACK_H
#define STACK_H

#include "../linked_list/linked_list.h"

typedef struct stack {
    LinkedList *list;
    int size;
} Stack;

Stack stack_create();
void stack_push(Stack *stack, void *data);
void stack_pop(Stack *stack);
void stack_peek(Stack *stack);
int stack_size(Stack *stack);
void stack_print(Stack *stack, void (*print)(void *data));
void stack_destroy(Stack *stack);

#endif // STACK_H
