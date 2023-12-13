#include <stdio.h>
#include <stdlib.h>
// #include "list/list.h"
// #include "stack/stack.h"
// #include "queue/queue.h"
#include "dequeue/dequeue.h"

int main()
{
    Dequeue *dq = create_dequeue();
    push_front(dq, 1);
    push_front(dq, 2);
    push_front(dq, 3);
    push_back(dq, 10);
    print_dequeue(dq);
}
