#include "LinkString.h"
#include <stdio.h>
#include <stdlib.h>

// 初始化
Status InitLinkString(LinkString *T)
{
    T->head = (LinkList)malloc(sizeof(LNode));
    if (!T->head)
    {
        return ERROR;
    }
    T->head->next = NULL;
    T->length = 0;
    return OK;
}
// 赋值
Status LinkStrAssign(LinkString *T, const char *chars)
{
    LinkList p, q;
    int i = 0;
    T->head->next = NULL;
    T->length = 0;
    p = T->head;
    while (chars[i] != '\0')
    {
        q = (LinkList)malloc(sizeof(LNode));
        if (!q)
        {
            return ERROR;
        }
        q->data = chars[i];
        p->next = q;
        p = q;
        i++;
        T->length++;
    }
    p->next = NULL;
    return OK;
}
// 求串长度
int LinkStrLength(const LinkString T)
{
    return T.length;
}
// 串连接
Status LinkConcat(LinkString *T, const LinkString S1, const LinkString S2)
{
    LinkList p, q, r;
    T->head = (LinkList)malloc(sizeof(LNode));
    if (!T->head)
    {
        return ERROR;
    }
    T->head->next = NULL;
    T->length = 0;
    p = T->head;

    // 连接S1
    q = S1.head->next;
    while (q)
    {
        r = (LinkList)malloc(sizeof(LNode));
        if (!r)
        {
            return ERROR;
        }
        r->data = q->data;
        p->next = r;
        p = r;
        q = q->next;
        T->length++;
    }

    // 连接S2
    q = S2.head->next;
    while (q)
    {
        r = (LinkList)malloc(sizeof(LNode));
        if (!r)
        {
            return ERROR;
        }
        r->data = q->data;
        p->next = r;
        p = r;
        q = q->next;
        T->length++;
    }
    p->next = NULL;
    return OK;
}
// 求子串
Status LinkSubString(LinkString *Sub, const LinkString S, int pos, int len)
{
    if (pos < 1 || pos > S.length || len < 0 || pos + len - 1 > S.length)
    {
        return ERROR;
    }
    LinkList p = S.head->next;
    LinkList q, r;
    int i;

    // 定位到起始位置
    for (i = 1; i < pos; i++)
    {
        p = p->next;
    }

    // 提取子串
    Sub->head = (LinkList)malloc(sizeof(LNode));
    if (!Sub->head)
    {
        return ERROR;
    }
    Sub->head->next = NULL;
    Sub->length = 0;
    q = Sub->head;

    for (i = 0; i < len; i++)
    {
        r = (LinkList)malloc(sizeof(LNode));
        if (!r)
        {
            return ERROR;
        }
        r->data = p->data;
        q->next = r;
        q = r;
        p = p->next;
        Sub->length++;
    }
    q->next = NULL;
    return OK;
}
// 串比较
int LinkStrCompare(const LinkString S, const LinkString T)
{
    LinkList p = S.head->next;
    LinkList q = T.head->next;
    while (p && q)
    {
        if (p->data != q->data)
        {
            return p->data - q->data;
        }
        p = p->next;
        q = q->next;
    }
    return S.length - T.length;
}
// 清空串
Status LinkClearString(LinkString *S)
{
    LinkList p = S->head->next;
    LinkList q;
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    S->head->next = NULL;
    S->length = 0;
    return OK;
}
// 输出串
Status LinkPrintString(const LinkString S)
{
    LinkList p = S.head->next;
    while (p)
    {
        putchar(p->data);
        p = p->next;
    }
    putchar('\n');
    return OK;
}
// 求子串在主串中的位置
int LinkIndex(const LinkString S, const LinkString T, int pos)
{
    if (pos < 1 || pos > S.length)
    {
        return 0;
    }
    LinkList p = S.head->next;
    LinkList q = T.head->next;
    int i, j;

    // 定位到主串的起始位置
    for (i = 1; i < pos; i++)
    {
        p = p->next;
    }

    for (; p != NULL; p = p->next)
    {
        LinkList ps = p;
        q = T.head->next;
        j = 0;
        while (ps != NULL && q != NULL && ps->data == q->data)
        {
            ps = ps->next;
            q = q->next;
            j++;
        }
        if (j == T.length)
        {
            return i; // 返回位置从1开始
        }
        i++;
    }
    return 0; // 未找到
}
// KMP算法求子串在主串中的位置
int LinkKMP_Index(const LinkString S, const LinkString T, int pos)
{
    if (pos < 1 || pos > S.length)
    {
        return 0;
    }
    int *next = (int *)malloc(T.length * sizeof(int));
    if (!next)
    {
        return 0;
    }
    LinkCompute_KMP_Next(T, next);
    LinkList p = S.head->next;
    LinkList q = T.head->next;
    int i = 1; // 主串位置
    int j = 0; // 子串位置

    // 定位到主串的起始位置
    for (int k = 1; k < pos; k++)
    {
        p = p->next;
        i++;
    }

    while (p != NULL && j < T.length)
    {
        if (j == -1 || p->data == q->data)
        {
            p = p->next;
            q = q->next;
            i++;
            j++;
        }
        else
        {
            j = next[j];
            q = T.head->next;
            for (int m = 0; m < j; m++)
            {
                q = q->next;
            }
        }
    }
    free(next);
    if (j == T.length)
    {
        return i - T.length; // 返回位置从1开始
    }
    return 0; // 未找到
}
// 计算KMP算法中的next数组
void LinkCompute_KMP_Next(const LinkString T, int *next)
{
    int i = 0;
    int j = -1;
    next[0] = -1;
    LinkList p = T.head->next;

    while (i < T.length - 1)
    {
        if (j == -1 || p->data == T.head->next->data)
        {
            i++;
            j++;
            p = p->next;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}
