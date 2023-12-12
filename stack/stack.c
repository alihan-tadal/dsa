#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack createStack() {
    Stack stack;
    stack.size = 0;
    stack.top = NULL;
    return stack;
}

void push(Stack *stack, int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

int pop(Stack *stack) {
    if (stack->size == 0) {
        printf("Stack is empty\n");
        return -1;
    }

    Node *node = stack->top;
    stack->top = node->next;
    free(node);
    stack->size--;
    return node->data;
}


int peek(Stack *stack) {
    if (stack->size == 0) {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element: %d\n", stack->top->data);
    return stack->top->data;
}

int isEmpty(Stack *stack) {
    if (stack->size == 0) {
        printf("Stack is empty\n");
        return 1;
    } else {
        printf("Stack is not empty\n");
        return 0;
    }
}

void deleteStack(Stack *stack) {
    Node *node = stack->top;
    while (node != NULL) {
        Node *temp = node;
        node = node->next;
        free(temp);
    }
    stack->size = 0;
    stack->top = NULL;
}