#include <stdio.h>
#include <stdlib.h>
#include "list/list.h"
#include "stack/stack.h"

int main()
{
    //create stack
    Stack stack = createStack();
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    printf("Stack size: %d\n", stack.size);
    peek(&stack);
    pop(&stack);
    printf("Stack size: %d\n", stack.size);
    peek(&stack);
    pop(&stack);
    printf("Stack size: %d\n", stack.size);

}
