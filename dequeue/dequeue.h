#ifndef DEQUEUE_H
#define DEQUEUE_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Dequeue {
    Node* head;
    Node* tail;
    int size;
} Dequeue;

// declare functions
Dequeue* create_dequeue();
void push_front(Dequeue* dequeue, int data);
void push_back(Dequeue* dequeue, int data);
int pop_front(Dequeue* dequeue);
int pop_back(Dequeue* dequeue);
int peek_front(Dequeue* dequeue);
int peek_back(Dequeue* dequeue);
int is_empty(Dequeue* dequeue);
void print_dequeue(Dequeue* dequeue);
void free_dequeue(Dequeue* dequeue);

#endif