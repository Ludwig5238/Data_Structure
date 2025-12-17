#ifndef DC_LINK_LIST_H
#define DC_LINK_LIST_H

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef char Status;
typedef int ElemType;
// 双向循环双链表结点定义
typedef struct DCNode
{
    ElemType data;
    struct DCNode *prior;
    struct DCNode *next;
} DCNode, *DCLinkList;
// 双向循环双链表的基本操作
// 初始化双向循环双链表
Status InitDCList(DCLinkList *L);
// 销毁双向循环双链表L
Status DestroyDCList(DCLinkList *L);
// 构建双向循环双链表L
Status CreateDCList(DCLinkList *L);
// 获取双向循环双链表L中的第i个元素
Status GetDCElem(DCLinkList L, int i, ElemType *e);
// 获取双向循环双链表L的长度
int DCListLength(DCLinkList L);
// 查找线性表中值为e的元素
Status LocateDCElem(DCLinkList L, ElemType e, int *i);
// 删除双向循环双链表L中的第i个元素
Status DeleteDCElem(DCLinkList *L, int i);
// 插入元素e到双向循环双链表L的第i个位置
Status InsertDCElem(DCLinkList *L, int i, ElemType e);
// 将双向循环双链表中的元素从小到大排序
Status SortDCList(DCLinkList *L);



#endif