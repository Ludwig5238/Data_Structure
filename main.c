#include <stdio.h>
#include "SqList/SqList.h"
const int List_Capacity = 10;
int main()
{
    SqList list;
    if (InitList(&list, List_Capacity) == OK)
    {
        printf("List initialized successfully.\n");
    }
    else
    {
        printf("Failed to initialize the list.\n");
        return 1;
    }
    for (int i = 1; i <= List_Capacity; i++)
    {
        InsertList(&list, i, i );
    }
    ElementType value;
    if (GetElem(&list, 3, &value) == OK)
    {
        printf("%d\n", value);
    }
    else
    {
        printf("Failed to get the element.\n");
    }
    DeleteList(&list, 5);
    printf("List contents after insertion:\n");
    for (int i = 0; i < list.length; i++)
    {
        printf("%d ", list.data[i]);
    }
    printf("\n");

    // Perform operations on the list

    if (DestroyList(&list) == OK)
    {
        printf("List destroyed successfully.\n");
    }
    else
    {
        printf("Failed to destroy the list.\n");
    }

    return 0;
}