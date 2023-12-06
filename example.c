#include <stdio.h>
#include <stdlib.h>
#include "list/list.h"

int main()
{
    DynamicArray arr = create_array(7);
    for (int i = 0; i < 6; i++)
    {
        push_back(&arr, i);
    }
    print_array(&arr, arr.size);
    describe_array(&arr);
    insert(&arr, 3, 31); // see 0, 1, 2, 31, 3, 4, 5
    print_array(&arr, arr.size);
    describe_array(&arr);
    remove_at(&arr, 3); // see 0, 1, 2, 3, 4, 5
    print_array(&arr, arr.size);
    return 0;
}
