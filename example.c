#include <stdio.h>
#include <stdlib.h>
#include "list/list.h"
#include "linked_list/linked_list.h"

int main()
{
    // DynamicArray arr = create_array(7);
    LinkedList linked_list = ll_create_empty();
    for (int i = 0; i < 7; i++)
    {
        // arr.data[i] = i;
        ll_append(&linked_list, i);
    }
    ll_print(&linked_list);
}
