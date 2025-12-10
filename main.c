#include <stdio.h>
#include "LinkList/LinkList.h"

int main()
{
    // 单链表的创建与基本操作测试
    LinkList L;
    ElemType e;
    InitList(L);
    ListInsert(L, 1, 10);
    ListInsert(L, 2, 20);
    ListInsert(L, 3, 30);
    GetElem(L, 2, &e);
    printf("The 2nd element is: %d\n", e); // 应输出 20
    DestroyList(L);
    return 0;
}
