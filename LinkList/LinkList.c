#include "LinkList.h"
#include <stdlib.h>

// 初始化单链表
Status InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(LNode));
    if (!*L)
        return OVERFLOW;
    (*L)->next = NULL;
    return OK;
}

// 删除单链表L中的第i个元素
Status DeleteElem(LinkList *L, int i){
    if (i < 1 || i > ListLength(*L))
        return ERROR; // i不合法

    LNode *p = *L, *q;
    int j = 0;
    while (p && j < i - 1) // 找到第i-1个结点
    {
        p = p->next;
        j++;
    }
    if (!p || !p->next)
        return ERROR; // 第i个元素不存在

    q = p->next; // q指向第i个结点
    p->next = q->next; // 删除第i个结点
    free(q); // 释放内存
    return OK;
}
// 插入元素e到单链表L的第i个位置
Status InsertElem(LinkList *L, int i, ElemType e){
    if (i < 1 || i > ListLength(*L) + 1)
        return ERROR; // i不合法

    LNode *p = *L, *s;
    int j = 0;
    while (p && j < i - 1) // 找到第i-1个结点
    {
        p = p->next;
        j++;
    }
    s = (LNode *)malloc(sizeof(LNode));
    if (!s)
        return OVERFLOW; // 内存分配失败

    s->data = e; // 设置新结点的数据
    s->next = p->next; // 新结点指向第i个结点
    p->next = s; // 第i-1个结点指向新结点
    return OK;
}

// 销毁单链表L
Status DestroyList(LinkList *L)
{
    LNode *p, *q;
    p = (*L)->next; // 跳过头结点
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    free(*L); // 释放头结点
    *L = NULL;
    return OK;
}

// 构建单链表L
Status CreateList(LinkList *L)
{
    int n = 10;
    int i;
    LNode *s, *r;
    r = *L; // r指向头结点
    for (i = 0; i < n; i++)
    {
        s = (LNode *)malloc(sizeof(LNode));
        if (!s)
            return OVERFLOW;
        // 生成随机数据
        s->data = rand() % 100 + 1;
        s->next = NULL;
        r->next = s; // 将新结点连接到链表末尾
        r = s;       // r指向新的最后一个结点
    }
    return OK;
}

// 获取单链表L中的第i个元素
Status GetElem(LinkList L, int i, ElemType *e)
{
    int j = 1;
    LNode *p = L->next; // 第一个结点
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR; // 第i个元素不存在
    *e = p->data;
    return OK;
}

// 获取单链表L的长度
int ListLength(LinkList L)
{
    int length = 0;
    LNode *p = L->next; // 跳过头结点
    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}

// 查找线性表中值为e的元素
Status LocateElem(LinkList L, ElemType e, int *i)
{
    int j = 1;
    LNode *p = L->next; // 跳过头结点
    while (p)
    {
        if (p->data == e)
        {
            *i = j; // 找到元素，返回位置
            return OK;
        }
        p = p->next;
        j++;
    }
    *i = 0; // 未找到元素
    return ERROR;
}

// 将单链表中的元素从小到大排序
Status SortList(LinkList *L)
{
    if (*L == NULL || (*L)->next == NULL)
        return OK; // 空链表或只有一个元素，无需排序

    LNode *p, *q, *prev;
    int temp;
    for (p = (*L)->next; p != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->data > q->data) // 如果前一个元素大于后一个元素
            {
                // 交换数据
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
    return OK;
}