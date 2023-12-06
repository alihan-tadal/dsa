#ifndef LIST_H
#define LIST_H

#define ELEMENT_TYPE float // Change this according to your needs

typedef struct DynamicArray
{
    ELEMENT_TYPE *data;
    int size;
    int capacity;
} DynamicArray;

// Function prototypes
DynamicArray create_array(int capacity);
void print_array(DynamicArray *arr, int size);
void fill_random(DynamicArray *arr, int min, int max);
void describe_array(DynamicArray *arr);
int is_empty(DynamicArray *arr);
int is_full(DynamicArray *arr);
void resize(DynamicArray *arr, int new_capacity);
void push_back(DynamicArray *arr, float value);
void insert(DynamicArray *arr, int index, float value);
ELEMENT_TYPE remove_at(DynamicArray *arr, int index);
void clear(DynamicArray *arr);
void destroy(DynamicArray *arr);

#endif // DYNAMIC_ARRAY_H
