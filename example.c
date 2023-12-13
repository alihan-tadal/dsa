#include <stdio.h>
#include <stdlib.h>
// #include "list/list.h"
// #include "stack/stack.h"
#include "queue/queue.h"

int main()
{
    Queue *q = create_queue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    print_queue(q);
    printf("Dequeue: %d\n", dequeue(q));
    print_queue(q);
}
