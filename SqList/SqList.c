#include "SqList.h"
#include <stdio.h>
#include <stdlib.h>

// 顺序线性表初始化
Status InitList(SqList *L, int LIST_SIZE)
{
    L->data = (ElementType *)malloc(LIST_SIZE * sizeof(ElementType));
    if (!L->data)
        exit(OVERFLOW);
    L->length = 0;
    L->capacity = LIST_SIZE;
    return OK;
}

// 销毁顺序线性表
Status DestroyList(SqList *L)
{
    if (L->data)
    {
        free(L->data);
        L->data = NULL;
    }
    L->length = 0;
    L->capacity = 0;
    return OK;
}

// 返回线性表长度
int ListLength(SqList *L)
{
    return L->length;
}

// 在第i个位置插入元素value
Status InsertList(SqList *L, int i, ElementType e)
{
    if (i < 1 || i > L->length + 1)
        return ERROR;
    // 判断是否需要扩容
    if (L->length >= L->capacity)
    {
        ElementType *newData = (ElementType *)realloc(L->data, (L->capacity + 10) * sizeof(ElementType));
        if (!newData)
            exit(OVERFLOW);
        L->data = newData;
        L->capacity += 5;
    }
    for (int j = L->length; j > i - 1; j--)
    {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length++;
    return OK;
}

// 使用*e返回顺序线性表第i个元素的值
Status GetElem(SqList L, int i, ElementType *e)
{
    if (i < 1 || i > L.length)
        return ERROR;
    *e = L.data[i - 1];
    return OK;
}

// 删除第i个元素
Status DeleteList(SqList *L, int i)
{
    // 边界检查
    if (i < 1 || i > L->length)
        return ERROR;
    for (int j = i - 1; j < L->length - 1; j++)
    {
        L->data[j] = L->data[j + 1];
    }
    L->length--;
    return OK;
}

// 将线性表清空
Status ClearList(SqList *L)
{
    L->length = 0;
    return OK;
}

// 判空
Status IsEmpty(SqList *L)
{
    return L->length == 0 ? TRUE : FALSE;
}

// 查找与给定值e相等的元素，返回其索引(在线性表中的位置)，若不存在则返回-1
int LocateElem(SqList L, ElementType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            return i + 1; // 返回的是位置，所以要加1
    }
    return -1; // 未找到
}