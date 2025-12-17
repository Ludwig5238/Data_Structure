#include "DCLinkList.h"
#include <stdio.h>
#include <stdlib.h>

// 初始化双向循环双链表
Status InitDCList(DCLinkList *L)
{
    *L = (DCLinkList)malloc(sizeof(DCNode));
    if (!*L)
        return OVERFLOW;
    (*L)->next = *L;
    (*L)->prior = *L;
    return OK;
}
// 销毁双向循环双链表L
Status DestroyDCList(DCLinkList *L)
{
    if (!L || !*L)
        return ERROR;
    DCNode *p = (*L)->next;
    DCNode *q;
    while (p != *L)
    {
        q = p->next;
        free(p);
        p = q;
    }
    free(*L);
    *L = NULL;
    return OK;
}
// 构建双向循环双链表L
Status CreateDCList(DCLinkList *L)
{
    int n, i;
    ElemType e;
    printf("请输入要创建的双向循环双链表的元素个数: ");
    scanf("%d", &n);
    InitDCList(L);
    DCNode *tail = *L;
    for (i = 0; i < n; i++)
    {
        printf("请输入第%d个元素的值: ", i + 1);
        scanf("%d", &e);
        DCNode *newNode = (DCNode *)malloc(sizeof(DCNode));
        if (!newNode)
            return OVERFLOW;
        newNode->data = e;
        newNode->next = *L;
        newNode->prior = tail;
        tail->next = newNode;
        (*L)->prior = newNode;
        tail = newNode;
    }
    return OK;
}
// 获取双向循环双链表L中的第i个元素
Status GetDCElem(DCLinkList L, int i, ElemType *e)
{
    if (!L || i < 1)
        return ERROR;
    DCNode *p = L->next;
    int j = 1;
    while (p != L && j < i)
    {
        p = p->next;
        j++;
    }
    if (p == L)
        return ERROR;
    *e = p->data;
    return OK;
}
// 获取双向循环双链表L的长度
int DCListLength(DCLinkList L)
{
    if (!L)
        return 0;
    DCNode *p = L->next;
    int length = 0;
    while (p != L)
    {
        length++;
        p = p->next;
    }
    return length;
}
// 查找线性表中值为e的元素
Status LocateDCElem(DCLinkList L, ElemType e, int *i)
{
    if (!L)
        return ERROR;
    DCNode *p = L->next;
    int index = 1;
    while (p != L)
    {
        if (p->data == e)
        {
            *i = index;
            return OK;
        }
        p = p->next;
        index++;
    }
    return ERROR;
}
// 删除双向循环双链表L中的第i个元素
Status DeleteDCElem(DCLinkList *L, int i)
{
    if (!L || !*L || i < 1)
        return ERROR;
    DCNode *p = (*L)->next;
    int j = 1;
    while (p != *L && j < i)
    {
        p = p->next;
        j++;
    }
    if (p == *L)
        return ERROR;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
}
// 插入元素e到双向循环双链表L的第i个位置
Status InsertDCElem(DCLinkList *L, int i, ElemType e)
{
    if (!L || !*L || i < 1)
        return ERROR;
    DCNode *p = *L;
    int j = 0;
    while (p->next != *L && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (j != i - 1)
        return ERROR;
    DCNode *newNode = (DCNode *)malloc(sizeof(DCNode));
    if (!newNode)
        return OVERFLOW;
    newNode->data = e;
    newNode->next = p->next;
    newNode->prior = p;
    p->next->prior = newNode;
    p->next = newNode;
    return OK;
}
// 将双向循环双链表中的元素从小到大排序
Status SortDCList(DCLinkList *L)
{
    if (!L || !*L)
        return ERROR;
    int len = DCListLength(*L);
    if (len < 2)
        return OK;
    DCNode *i, *j;
    ElemType temp;
    for (i = (*L)->next; i->next != *L; i = i->next)
    {
        for (j = i->next; j != *L; j = j->next)
        {
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return OK;
}