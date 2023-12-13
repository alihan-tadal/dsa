#include "dequeue.h"
#include <stdlib.h>
#include <stdio.h>

Dequeue* create_dequeue() {
    Dequeue *dequeue = (Dequeue *)malloc(sizeof(Dequeue));
    dequeue->head = NULL;
    dequeue->tail = NULL;
    dequeue->size = 0;
    return dequeue;
}

void push_front(Dequeue *dequeue, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (dequeue->size == 0) {
        dequeue->head = new_node;
        dequeue->tail = new_node;
    }
    else {
        new_node->next = dequeue->head;
        dequeue->head = new_node;
    }
    dequeue->size++;
}

void push_back(Dequeue *dequeue, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (dequeue->size == 0) {
        dequeue->head = new_node;
        dequeue->tail = new_node;
    }
    else {
        dequeue->tail->next = new_node;
        dequeue->tail = new_node;
    }
    dequeue->size++;
}

int pop_front(Dequeue *dequeue) {
    if (dequeue->size == 0) {
        printf("Dequeue is empty!\n");
        return -1;
    }
    Node *temp = dequeue->head;
    int data = dequeue->tail->data;
    while(temp->next != dequeue->tail && temp->next != NULL) {
        temp = temp->next;
    }
    dequeue->tail = temp;
    dequeue->tail->next = NULL;
    dequeue->size--;
    free(temp);
    return data;
}

int peek_front(Dequeue *dq) {
    if (dq->size == 0) {
        printf("Dequeue is empty!\n");
        return -1;
    }
    return dq->head->data;
}

int peek_back(Dequeue *dq) {
    if (dq->size == 0) {
        printf("Dequeue is empty!\n");
        return -1;
    }
    return dq->tail->data;
}

int is_empty(Dequeue *dequeue) {
    return dequeue->size == 0;
}

void print_dequeue(Dequeue *dequeue) {
    if (dequeue->size == 0) {
        printf("Dequeue is empty!\n");
        return;
    }
    Node *temp = dequeue->head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void free_dequeue(Dequeue *dequeue) {
    Node *temp = dequeue->head;
    while(temp != NULL) {
        dequeue->head = dequeue->head->next;
        free(temp);
        temp = dequeue->head;
    }
    free(dequeue);
}