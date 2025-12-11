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

// 初始化带头节点的单链表L
Status InitList(LinkList *L);



#endif