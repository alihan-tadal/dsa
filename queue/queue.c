#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

Queue *create_queue()
{
    Queue *queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void enqueue(Queue *q, int value)
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    if (q->head == NULL)
    {
        q->head = node;
        q->tail = node;
    }
    else
    {
        q->tail->next = node;
        q->tail = node;
    }
    q->size++;
}

int dequeue(Queue *q)
{
    if (q->head == NULL)
    {
        printf("Queue is empty.");
        return -1;
    }
    Node *node = q->head;
    int value = node->value;
    q->head = node->next;
    free(node);
    q->size--;
    return value;
}

int peek(Queue *q)
{
    if (q->head == NULL)
    {
        printf("Queue is empty.");
        return -1;
    }
    {
        return q->head->value;
    }
}

int is_empty(Queue *q)
{
    return q->head == NULL;
}

void print_queue(Queue *q) {
    if (q->head == NULL)
    {
        printf("Queue is empty.");
    }
    Node *node = q->head;
    while (node != NULL)
    {
        printf("%d ", node->value);
        node = node->next;
    }
}

void delete_queue(Queue *q)
{
    Node *node = q->head;
    while (node != NULL)
    {
        Node *temp = node;
        node = node->next;
        free(temp);
    }
    free(q);
}