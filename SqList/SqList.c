#include "SqList.h"
#include <stdio.h>
#include <stdlib.h>

// 顺序线性表初始化
Status InitList(SqList *list, int capacity)
{
    list->data = (ElementType *)malloc(capacity * sizeof(ElementType));
    if (!list->data)
    {
        return ERROR;
    }
    list->length = 0;
    list->capacity = capacity;
    return OK;
}
// 在线性表第i个位置插入元素value
Status InsertList(SqList *list, int i, ElementType value)
{
    if (i < 1 || i > list->length + 1)
    {
        return ERROR;
    }
    if (list->length >= list->capacity)
    {
        ElementType *newData = (ElementType *)realloc(list->data, (list->capacity * 2) * sizeof(ElementType));
        if (!newData)
        {
            return ERROR;
        }
        list->data = newData;
        list->capacity *= 2;
    }
    for (int index = list->length; index > i-1; index--)
    {
        list->data[index] = list->data[index - 1];
    }
    list->data[i - 1] = value;
    list->length++;
    return OK;
}
// 删除第i个元素
Status DeleteList(SqList *list, int i)
{
    if (i < 1 || i > list->length)
    {
        return ERROR;
    }
    for (int index = i - 1; index < list->length - 1; index++)
    {
        list->data[index] = list->data[index + 1];
    }
    list->length--;
    return OK;
}
// 将线性表清空
Status ClearList(SqList *list)
{
    list->length = 0;
    return OK;
}
// 判空
Status IsEmpty(SqList *list)
{
    return list->length == 0 ? TRUE : FALSE;
}
// 返回线性表长度
int ListLength(SqList *list)
{
    return list->length;
}
// 查找与给定值value相等的元素，返回其索引，若不存在则返回-1
int LocateElem(SqList *list, ElementType value)
{
    for (int i = 0; i < list->length; i++)
    {
        if (list->data[i] == value)
        {
            return i + 1;
        }
    }
    return -1;
}
// 使用*value返回第index个元素的值
Status GetElem(SqList *list, int index, ElementType *value)
{
    if (index < 1 || index > list->length)
    {
        return ERROR;
    }
    *value = list->data[index - 1];
    return OK;
}

// 销毁顺序线性表
Status DestroyList(SqList *list)
{
    free(list->data);
    list->data = NULL;
    list->length = 0;
    list->capacity = 0;
    return OK;
}
