#ifndef LINKLIST_H
#define LINKLIST_H

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef char Status;

typedef int ElemType;

// 单链表结点定义
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

// 初始化单链表L
Status InitList(LinkList L);

// 销毁单链表L
Status DestroyList(LinkList L);

// 向单链表L的第i个位置插入数据e
Status ListInsert(LinkList L, int i, ElemType e);

// 在单链表L中查找第i个元素，若找到，返回该元素结算的指针
Status GetElem(LinkList L, int i, ElemType *e);

// 删除单链表L的第i个元素，并用e返回其值
Status ListDelete(LinkList L, int i, ElemType *e);

#endif