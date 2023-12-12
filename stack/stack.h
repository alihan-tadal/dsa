#ifndef STACK_H
#define STACK_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
    int size;
} Stack;

// make declarations
Stack createStack();
void push(Stack *stack, int data);
int pop(Stack *stack);
int peek(Stack *stack);
int isEmpty(Stack *stack);
void deleteStack(Stack *stack);


#endif