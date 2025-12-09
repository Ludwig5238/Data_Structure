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
Status InitList(SqList *list, int capacity);
// 在第i个位置插入元素value
Status InsertList(SqList *list, int i, ElementType value);
// 删除第i个元素
Status DeleteList(SqList *list, int i);
// 将线性表清空
Status ClearList(SqList *list);
// 判空
Status IsEmpty(SqList *list);
// 返回线性表长度
int ListLength(SqList *list);
// 查找与给定值value相等的元素，返回其索引，若不存在则返回-1
int LocateElem(SqList *list, ElementType value);
// 使用*value返回第index个元素的值
Status GetElem(SqList *list, int index, ElementType *value);
// 销毁顺序线性表
Status DestroyList(SqList *list);

#endif // SQLIST_H