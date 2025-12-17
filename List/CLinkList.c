#include "CLinkList.h"
#include <stdio.h>
#include <stdlib.h>

// 初始化循环链表
Status InitCList(CLinkList *L)
{
    *L = (CLinkList)malloc(sizeof(CLNode));
    if (!*L)
        return OVERFLOW;
    (*L)->next = *L; // 指向自己，形成循环
    return OK;
}
// 销毁循环链表L
Status DestroyCList(CLinkList *L)
{
    if (!L || !*L)
        return ERROR;
    CLinkList p = (*L)->next;
    CLinkList temp;
    while (p != *L)
    {
        temp = p->next;
        free(p);
        p = temp;
    }
    free(*L);
    *L = NULL;
    return OK;
}
// 构建循环链表L
Status CreateCList(CLinkList *L)
{
    int n, i;
    ElemType e;
    printf("请输入循环链表的长度: ");
    scanf("%d", &n);
    *L = (CLinkList)malloc(sizeof(CLNode));
    if (!*L)
        return OVERFLOW;
    (*L)->next = *L; // 指向自己，形成循环
    CLinkList tail = *L;
    for (i = 0; i < n; i++)
    {
        printf("请输入第%d个元素: ", i + 1);
        scanf("%d", &e);
        CLinkList newNode = (CLinkList)malloc(sizeof(CLNode));
        if (!newNode)
            return OVERFLOW;
        newNode->data = e;
        tail->next = newNode;
        tail = newNode;
    }
    tail->next = *L; // 形成循环
    return OK;
}
// 获取循环链表L中的第i个元素
Status GetCElem(CLinkList L, int i, ElemType *e)
{
    if (i < 1)
        return ERROR;
    CLinkList p = L->next;
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
// 获取循环链表L的长度
int CListLength(CLinkList L)
{
    int length = 0;
    CLinkList p = L->next;
    while (p != L)
    {
        length++;
        p = p->next;
    }
    return length;
}
// 查找循环链表中值为e的元素
Status LocateCElem(CLinkList L, ElemType e, int *i)
{
    CLinkList p = L->next;
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
// 删除循环链表L中的第i个元素
Status DeleteCElem(CLinkList *L, int i)
{
    if (i < 1)
        return ERROR;
    CLinkList p = *L;
    int j = 0;
    while (p->next != *L && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p->next == *L)
        return ERROR;
    CLinkList temp = p->next;
    p->next = temp->next;
    free(temp);
    return OK;
}
// 插入元素e到循环链表L的第i个位置
Status InsertCElem(CLinkList *L, int i, ElemType e)
{
    if (i < 1)
        return ERROR;
    CLinkList p = *L;
    int j = 0;
    while (p->next != *L && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (j != i - 1)
        return ERROR;
    CLinkList newNode = (CLinkList)malloc(sizeof(CLNode));
    if (!newNode)
        return OVERFLOW;
    newNode->data = e;
    newNode->next = p->next;
    p->next = newNode;
    return OK;
}
// 将循环链表中的元素从小到大排序
Status SortCList(CLinkList *L)
{
    if (!L || !*L)
        return ERROR;
    int len = CListLength(*L);
    if (len < 2)
        return OK;
    CLinkList p, q;
    ElemType temp;
    for (int i = 0; i < len - 1; i++)
    {
        p = (*L)->next;
        for (int j = 0; j < len - 1 - i; j++)
        {
            q = p->next;
            if (p->data > q->data)
            {
                // 交换数据
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            p = q;
        }
    }
    return OK;
}