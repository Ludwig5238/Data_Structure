#ifndef SQLIST_H
#define SQLIST_H

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef char Status;

typedef int ElementType;

// 顺序线性表数据结构定义
typedef struct
{
    ElementType *data; // 存储空间基址
    int length;        // 当前长度
    int capacity;      // 当前分配的存储容量
} SqList;

// 顺序线性表初始化
Status InitList(SqList *L, int LIST_SIZE);
// 在第i个位置插入元素value
Status InsertList(SqList *L, int i, ElementType e);
// 删除第i个元素
Status DeleteList(SqList *L, int i);
// 将线性表清空
Status ClearList(SqList *L);
// 判空
Status IsEmpty(SqList *L);
// 返回线性表长度
int ListLength(SqList *L);
// 查找与给定值value相等的元素，返回其索引，若不存在则返回-1
int LocateElem(SqList L, ElementType e);
// 使用*value返回第index个元素的值
Status GetElem(SqList L, int i, ElementType *e);
// 销毁顺序线性表
Status DestroyList(SqList *L);

#endif // SQLIST_H