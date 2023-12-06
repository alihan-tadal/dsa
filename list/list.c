#include <stdio.h>
#include <stdlib.h>
#include "list.h"

float float_rand(float min, float max)
{
    float scale = rand() / (float)RAND_MAX;
    return min + scale * (max - min);
}

void fill_random(DynamicArray *arr, int min, int max)
{
    for (int i = 0; i < arr->capacity; i++)
    {
        arr->data[i] = float_rand(min, max);
        arr->size++;
    }
}

DynamicArray create_array(int capacity)
{
    DynamicArray arr;
    arr.size = 0;
    arr.capacity = capacity;
    arr.data = malloc(capacity * sizeof(*arr.data));
    return arr;
}

void print_array(DynamicArray *arr, int size)
{
    for (int i = 0; i < arr->size; i++)
    {
        printf("%f\n", arr->data[i]);
    }
}

void describe_array(DynamicArray *arr)
{
    printf("Size: %d\n", arr->size);
    printf("Capacity: %d\n", arr->capacity);
}

int is_empty(DynamicArray *arr)
{
    return arr->size == 0;
}

int is_full(DynamicArray *arr)
{
    return arr->size == arr->capacity;
}

void resize(DynamicArray *arr, int new_capacity)
{
    ELEMENT_TYPE *new_data = realloc(arr->data, new_capacity * sizeof(*arr->data));
    if (arr->data == NULL)
    {
        printf("Error: Could not resize array.\n");
        exit(1);
    }
    arr->data = new_data;
    arr->capacity = new_capacity;
}

void push_back(DynamicArray *arr, float value)
{
    if (arr->capacity > arr->size)
    {
        arr->data[arr->size] = value;
    }
    else if (arr->capacity == arr->size)
    {
        printf("Array is full. Resizing...\n");
        resize(arr, arr->capacity * 2);
        arr->data[arr->size] = value;
    }
    arr->size++;
}

void insert(DynamicArray *arr, int index, float value)
{
    if (index < 0 || index > arr->size)
    {
        printf("Error: Index out of bounds.\n");
        exit(1);
    }
    if (is_full(arr))
    {
        printf("Array is full. Cannot insert.\n");
        exit(1);
    }

    for (int i = arr->size; i > index; i--)
    {
        arr->data[i] = arr->data[i - 1];
    }

    arr->data[index] = value;
    arr->size++;
}

ELEMENT_TYPE remove_at(DynamicArray *arr, int index)
{
    // a simple bound check
    if (index < 0 || index >= arr->size) {
        printf("Error: Index out of bounds.\n");
        exit(1);
    }
    ELEMENT_TYPE x = arr->data[index];
    
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i+1];
    }

    arr->size--;
    return x;

}

void clear(DynamicArray *arr)
{
    for (int i = 0; i < arr->size; i++) {
        arr->data[i] = 0;
    }
    arr->size = 0;
}

void destroy(DynamicArray *arr)
{
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}
