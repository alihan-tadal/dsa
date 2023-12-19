#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

struct Node *new_node(int data);
void insert(struct Node **root, int data);
void print_tree(struct Node *root);
void print_tree_inorder(struct Node *root);
void print_tree_preorder(struct Node *root);
void print_tree_postorder(struct Node *root);
void print_tree_levelorder(struct Node *root);
void print_tree_level(struct Node *root, int level);
int tree_height(struct Node *root);
int tree_size(struct Node *root);
int tree_size_recursive(struct Node *root);

#endif // BINARY_TREE_H
