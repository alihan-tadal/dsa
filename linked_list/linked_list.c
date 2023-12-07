#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
    LinkedList ll = ll_create_empty();

    ll_append(&ll, 3);
    ll_append(&ll, 4);
    ll_append(&ll, 5);
    // ll_remove_tail(&ll);
    ll_remove_head(&ll);

    ll_print(&ll);
}

LinkedList ll_create_empty()
{
    LinkedList list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;
    return list;
}

void ll_print(LinkedList *ll)
{
    if (ll->head == NULL && ll->tail == NULL)
    {
        printf("Linked list is empty.");
    }
    else
    {
        Node *n;
        n = ll->head;
        for (int i = 0; i < ll->size; i++)
        {
            printf("%f ", n->data);
            n = n->next;
        }
    }
}

void ll_prepend(LinkedList *ll, ELEMENT_TYPE data)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->next = ll->head;
    ll->head = n;
    ll->size++;
}

void ll_append(LinkedList *ll, ELEMENT_TYPE data)
{
    Node *n = (Node *)malloc(sizeof(Node));
    // check if malloc failed
    if (n == NULL)
    {
        exit(1);
    }
    n->data = data;
    n->next = NULL;

    if (ll->head == NULL && ll->tail == NULL)
    {
        ll->head = n;
        ll->tail = n;
    }
    else
    {
        ll->tail->next = n;
        ll->tail = n;
    }
    ll->size++;
}

void ll_insert(LinkedList *ll, int index, ELEMENT_TYPE data)
{
    if (index < 0 && index > ll->size)
    {
        printf("Invalid index.");
        exit(1);
    }
    if (index == 0)
    {
        ll_prepend(ll, data);
    }
    else if (index == ll->size)
    {
        ll_append(ll, data);
    }
    else
    {
        Node *n = (Node *)malloc(sizeof(Node));
        n->data = data;
        n->next = NULL;
        Node *prev;

        prev = ll->head;
        for (int i = 0; i < index - 1; i++)
        {
            prev = prev->next;
        }
        n->next = prev->next;
        prev->next = n;
        ll->size++;
    }
}

ELEMENT_TYPE ll_remove_head(LinkedList *ll) {
    Node *n = ll->head;
    ELEMENT_TYPE data = ll->head->data;
    ll->head = ll->head->next;
    free(n);
    ll->size--;
}

ELEMENT_TYPE ll_remove_tail(LinkedList *ll)
{
    Node *prev;
    prev = ll->head;
    while (prev->next != ll->tail)
    {
        prev = prev->next;
    }
    ELEMENT_TYPE data = ll->tail->data;
    ll->tail = prev;
    ll->tail->next = NULL;
    ll->size--;
    return data;
}

ELEMENT_TYPE ll_remove(LinkedList *ll, int index)
{
    if (index < 0 && index > ll->size)
    {
        printf("Invalid index.");
        exit(1);
    }
    if (index == 0)
    {
        // return ll_remove_head(ll);
    }
    else if (index == ll->size - 1)
    {
        return ll_remove_tail(ll);
    }
    else
    {
        Node *prev;
        prev = ll->head;
        for (int i = 0; i < index - 1; i++)
        {
            prev = prev->next;
        }
        Node *n = prev->next;
        prev->next = n->next;
        ll->size--;
        ELEMENT_TYPE data = n->data;
        free(n);
        return data;
    }
}
