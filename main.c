#include <stdio.h>
#include "SqList/SqList.h"
void SqListdemo();
int main()
{
    SqListdemo();
    return 0;
}

// 线性表测试程序
void SqListdemo()
{
    int List_Capacity = 10;
    SqList list;
    InitList(&list, List_Capacity);
    for (int i = 1; i <= 10; i++)
    {
        InsertList(&list, i, i + i);
    }
    printf("List Length: %d\n", ListLength(&list));
    printf("%d\n", list.capacity);
    DeleteList(&list, 5);
    for (int i = 1; i <= list.length; i++)
    {
        ElementType value;
        GetElem(list, i, &value);
        printf("Element %d: %d\n", i, value);
    }
    int pos = LocateElem(list, 12);
    if (pos != -1)
    {
        printf("Element 12 found at position: %d\n", pos);
    }
    else
    {
        printf("Element 12 not found.\n");
    }
    DestroyList(&list);
}