#include "DLinkList.h"
#include <stdio.h>
#include <stdlib.h>

// 初始化双链表
Status InitDList(DLinkList *L)
{
    *L = (DLinkList)malloc(sizeof(DNode));
    if (!*L)
        return OVERFLOW;
    (*L)->prior = NULL;
    (*L)->next = NULL;
    return OK;
}
// 销毁双链表L
Status DestroyDList(DLinkList *L)
{
    DNode *p = *L;
    DNode *q;
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    *L = NULL;
    return OK;
}
// 构建双链表L
Status CreateDList(DLinkList *L)
{
    int n, i;
    ElemType e;
    DNode *s, *r;
    printf("请输入双链表的长度: ");
    scanf("%d", &n);
    *L = (DLinkList)malloc(sizeof(DNode));
    if (!*L)
        return OVERFLOW;
    (*L)->prior = NULL;
    r = *L;
    for (i = 1; i <= n; i++)
    {
        printf("请输入第%d个元素的值: ", i);
        scanf("%d", &e);
        s = (DNode *)malloc(sizeof(DNode));
        if (!s)
            return OVERFLOW;
        s->data = e;
        s->prior = r;
        r->next = s;
        r = s;
    }
    r->next = NULL;
    return OK;
}
// 获取双链表L中的第i个元素
Status GetDElem(DLinkList L, int i, ElemType *e)
{
    DNode *p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    *e = p->data;
    return OK;
}
// 获取双链表L的长度
int DListLength(DLinkList L)
{
    DNode *p = L->next;
    int length = 0;
    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}
// 查找线性表中值为e的元素
Status LocateDElem(DLinkList L, ElemType e, int *i)
{
    DNode *p = L->next;
    int j = 1;
    while (p)
    {
        if (p->data == e)
        {
            *i = j;
            return OK;
        }
        p = p->next;
        j++;
    }
    return ERROR;
}
// 删除双链表L中的第i个元素
Status DeleteDElem(DLinkList *L, int i)
{
    DNode *p = (*L)->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    p->prior->next = p->next;
    if (p->next)
        p->next->prior = p->prior;
    free(p);
    return OK;
}
// 插入元素e到双链表L的第i个位置
Status InsertDElem(DLinkList *L, int i, ElemType e)
{
    DNode *p = *L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
        return ERROR;
    DNode *s = (DNode *)malloc(sizeof(DNode));
    if (!s)
        return OVERFLOW;
    s->data = e;
    s->next = p->next;
    s->prior = p;
    if (p->next)
        p->next->prior = s;
    p->next = s;
    return OK;
}
// 将双链表中的元素从小到大排序
Status SortDList(DLinkList *L)
{
    int len = DListLength(*L);
    if (len < 2)
        return OK;
    DNode *p, *q;
    ElemType temp;
    for (int i = 1; i < len; i++)
    {
        p = (*L)->next;
        for (int j = 1; j <= len - i; j++)
        {
            q = p->next;
            if (p->data > q->data)
            {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            p = q;
        }
    }
    return OK;
}