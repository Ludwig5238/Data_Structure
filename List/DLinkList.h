#ifndef DLINKLIST_H
#define DLINKLIST_H

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef char Status;

typedef int ElemType;
// 双链表结点定义
typedef struct DNode
{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
} DNode, *DLinkList;
// 双链表的基本操作
// 初始化双链表
Status InitDList(DLinkList *L);
// 销毁双链表L
Status DestroyDList(DLinkList *L);
// 构建双链表L
Status CreateDList(DLinkList *L);
// 获取双链表L中的第i个元素
Status GetDElem(DLinkList L, int i, ElemType *e);
// 获取双链表L的长度
int DListLength(DLinkList L);
// 查找线性表中值为e的元素
Status LocateDElem(DLinkList L, ElemType e, int *i);
// 删除双链表L中的第i个元素
Status DeleteDElem(DLinkList *L, int i);
// 插入元素e到双链表L的第i个位置
Status InsertDElem(DLinkList *L, int i, ElemType e);
// 将双链表中的元素从小到大排序
Status SortDList(DLinkList *L);


#endif