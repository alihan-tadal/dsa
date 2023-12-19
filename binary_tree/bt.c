#include <stdlib.h>
#include <stdio.h>

// User defined header files
#include "bt.h"


int main() {
    struct Node *head = new_node(1);
    printf("ok");
}


struct Node *new_node(int data) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}

void insert(struct Node **root, int data) {
    if (*root == NULL) {
        *root = new_node(data);
    }

    if (data < (*root)->data) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}
