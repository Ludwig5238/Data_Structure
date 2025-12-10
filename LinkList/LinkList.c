#include "LinkList.h"
#include <stdlib.h>
// 初始化带头节点的单链表L
Status InitList(LinkList L)
{
    L = (LinkList)malloc(sizeof(LNode));
    if (!L)
        return OVERFLOW;
    L->next = NULL;
    return OK;
}

// 销毁单链表L
Status DestroyList(LinkList L)
{
    LinkList p, q;
    p = L->next;
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    free(L);
    return OK;
}

// 在单链表L中查找第i个元素，若找到，返回该元素结算的指针
Status GetElem(LinkList L, int i, ElemType *e)
{
    LinkList p;
    int cursor = 1;
    p = L->next; // 第一个结点
    while (p && cursor < i)
    {
        p = p->next;
        cursor++;
    }
    if (!p || cursor > i)
        return ERROR;
    *e = p->data;
    return OK;
}

// 向单链表L的第i个位置插入数据e
Status ListInsert(LinkList L, int i, ElemType e)
{
    LinkList p, s;
    int cursor = 1;
    p = L; // 从头结点开始
    while (p && cursor < i)
    {
        p = p->next;
        cursor++;
    }
    if (!p || cursor > i)
        return ERROR;
    s = (LinkList)malloc(sizeof(LNode));
    if (!s)
        return OVERFLOW;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

// 删除单链表L的第i个元素，并用e返回其值
Status ListDelete(LinkList L, int i, ElemType *e)
{
    LinkList p, q;
    int cursor = 1;
    p = L; // 从头结点开始
    while (p->next && cursor < i)
    {
        p = p->next;
        cursor++;
    }
    if (!(p->next) || cursor > i)
        return ERROR;
    q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return OK;
}
