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

// 初始化单链表
Status InitList(LinkList *L);
// 销毁单链表L
Status DestroyList(LinkList *L);
// 构建单链表L
Status CreateList(LinkList *L);
// 获取单链表L中的第i个元素
Status GetElem(LinkList L, int i, ElemType *e);
// 获取单链表L的长度
int ListLength(LinkList L);
// 查找线性表中值为e的元素
Status LocateElem(LinkList L, ElemType e, int *i);
// 删除单链表L中的第i个元素
Status DeleteElem(LinkList *L, int i);
// 插入元素e到单链表L的第i个位置
Status InsertElem(LinkList *L, int i, ElemType e);
// 将单链表中的元素从小到大排序
Status SortList(LinkList *L);

#endif