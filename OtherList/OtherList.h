#ifndef OTHERLIST_H
#define OTHERLIST_H

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef char Status;

typedef int ElemType;

// 头指针循环链表结点定义
typedef struct CNode
{
    ElemType data;
    struct CNode *next;
} CNode, *CLinkList;

// 初始化具有尾指针的循环链表
Status InitCTailList(CLinkList *L);

// 初始化循环链表
Status InitCList(CLinkList *L);
// 销毁循环链表L
Status DestroyCList(CLinkList *L);
// 构建循环链表L
Status CreateCList(CLinkList *L);
// 获取循环链表L中的第i个元素
Status GetCElem(CLinkList L, int i, ElemType *e);
// 获取循环链表L的长度
int CListLength(CLinkList L);
// 查找循环链表中值为e的元素
Status LocateCElem(CLinkList L, ElemType e, int *i);
// 删除循环链表L中的第i个元素
Status DeleteCElem(CLinkList *L, int i);
// 插入元素e到循环链表L的第i个位置
Status InsertCElem(CLinkList *L, int i, ElemType e);
// 将循环链表中的元素从小到大排序
Status SortCList(CLinkList *L);

// 创建头指针循环链表
Status CreateCHeadList(CLinkList *L);

// 创建尾指针循环链表
Status CreateCTailList(CLinkList *L);
// 获取尾指针循环链表L中的第i个元素
Status GetCTailElem(CLinkList L, int i, ElemType *e);
// 获取尾指针循环链表L的长度
int CTailListLength(CLinkList L);
// 查找尾指针循环链表中值为e的元素
Status LocateCTailElem(CLinkList L, ElemType e, int *i);
// 删除尾指针循环链表L中的第i个元素
Status DeleteCTailElem(CLinkList *L, int i);
// 插入元素e到尾指针循环链表L的第i个位置
Status InsertCTailElem(CLinkList *L, int i, ElemType e);
// 将尾指针循环链表中的元素从小到大排序
Status SortCTailList(CLinkList *L);

#endif // OTHERLIST_H