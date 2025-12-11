#include "LinkList.h"
#include <stdlib.h>

Status InitList(LinkList *L)
{
    // 分配头节点
    *L = (LinkList)malloc(sizeof(LNode));
    if (*L == NULL)
    {
        return OVERFLOW; // 内存分配失败
    }
    (*L)->next = NULL; // 头节点的next置为空
    return OK;
}