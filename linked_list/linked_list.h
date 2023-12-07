#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define ELEMENT_TYPE float

typedef struct Node {
    ELEMENT_TYPE data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

LinkedList ll_create_empty();
void ll_print(LinkedList *ll);
void ll_prepend(LinkedList *ll, ELEMENT_TYPE data);
void ll_append(LinkedList *ll, ELEMENT_TYPE data);
void ll_insert(LinkedList *ll, int index, ELEMENT_TYPE data);
ELEMENT_TYPE ll_remove_head(LinkedList *ll);
ELEMENT_TYPE ll_remove_tail(LinkedList *ll);
ELEMENT_TYPE ll_remove(LinkedList *ll, int index);
void ll_remove_all(LinkedList *ll);
int ll_size(LinkedList *ll);
ELEMENT_TYPE ll_get(LinkedList *ll, int index);
void ll_set(LinkedList *ll, int index, ELEMENT_TYPE data);
int ll_index_of(LinkedList *ll, ELEMENT_TYPE data);
int ll_contains(LinkedList *ll, ELEMENT_TYPE data);
int ll_is_empty(LinkedList *ll);
void ll_reverse(LinkedList *ll);
void ll_sort(LinkedList *ll);
void ll_remove_duplicates(LinkedList *ll);



#endif // LINKED_LIST_H

