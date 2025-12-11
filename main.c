#include <stdio.h>
#include "LinkList/LinkList.h"

int main()
{
    LinkList L;
    if (InitList(&L) == OK)
        printf("单链表初始化成功！\n");
    else
        printf("单链表初始化失败！\n");

    if (CreateList(&L) == OK)
    {
        printf("单链表创建成功！\n");
        ElemType e;
        int length = ListLength(L);
        for (int i = 1; i <= length; i++)
        {
            if (GetElem(L, i, &e) == OK)
                printf("单链表的第 %d 个元素是: %d\n", i, e);
            else
                printf("获取第 %d 个元素失败！\n", i);
        }
    }
    else
        printf("单链表创建失败！\n");

    if (SortList(&L) == OK)
        printf("单链表排序成功！\n");
    else
        printf("单链表排序失败！\n");
    // 遍历链表并打印元素
    printf("排序后的单链表元素为:\n");
    ElemType e;
    int length = ListLength(L);
    for (int i = 1; i <= length; i++)
    {
        if (GetElem(L, i, &e) == OK)
            printf("%d ", e);
        else
            printf("获取第 %d 个元素失败！\n", i);
    }
    printf("\n");
    ElemType searchElem = 50; // 假设要查找的元素值
    int index;
    if (LocateElem(L, searchElem, &index) == OK)
        printf("元素 %d 在单链表中的位置是: %d\n", searchElem, index);
    else
        printf("元素 %d 不在单链表中！\n", searchElem);

    if (DestroyList(&L) == OK)
        printf("单链表销毁成功！\n");
    else
        printf("单链表销毁失败！\n");

    return 0;
}

// 顺序线性表
// 单链表
// 循环链表
// 双向链表
// 双向循环链表
