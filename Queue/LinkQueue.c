#include "LinkQueue.h"
#include <stdlib.h>
#include <stdio.h>

// 初始化队列
Status InitQueue(LinkQueue *Q)
{
    // 创建头结点
    Q->front = (QueuePtr)malloc(sizeof(QNode));
    if (!Q->front)
        return ERROR; // 内存分配失败

    Q->front->next = NULL;
    Q->rear = Q->front;
    return OK;
}

// 销毁队列
Status DestroyQueue(LinkQueue *Q)
{
    // 清空队列中的所有元素
    ClearQueue(Q);

    // 释放头结点
    if (Q->front)
    {
        free(Q->front);
        Q->front = NULL;
        Q->rear = NULL;
    }
    return OK;
}

// 清空队列
Status ClearQueue(LinkQueue *Q)
{
    QueuePtr p, q;

    if (!Q->front)
        return ERROR;

    p = Q->front->next; // p指向第一个元素结点
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }

    Q->front->next = NULL;
    Q->rear = Q->front;
    return OK;
}

// 判断队列是否为空
Status QueueEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}

// 求队列长度
int QueueLength(LinkQueue Q)
{
    int length = 0;
    QueuePtr p = Q.front->next; // 跳过头结点

    while (p)
    {
        length++;
        p = p->next;
    }

    return length;
}

// 获取队头元素
Status GetHead(LinkQueue Q, QElemType *e)
{
    if (QueueEmpty(Q))
        return ERROR; // 队列空

    *e = Q.front->next->data;
    return OK;
}

// 入队
Status EnQueue(LinkQueue *Q, QElemType e)
{
    QueuePtr p;

    if (!Q->front)
        return ERROR;

    p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)
        return ERROR; // 内存分配失败

    p->data = e;
    p->next = NULL;

    Q->rear->next = p;
    Q->rear = p;
    return OK;
}

// 出队
Status DeQueue(LinkQueue *Q, QElemType *e)
{
    QueuePtr p;

    if (QueueEmpty(*Q))
        return ERROR; // 队列空

    p = Q->front->next; // p指向要出队的结点
    *e = p->data;

    Q->front->next = p->next;

    // 如果出队的是最后一个元素，需要更新rear指针
    if (Q->rear == p)
        Q->rear = Q->front;

    free(p);
    return OK;
}

// 遍历队列
Status QueueTraverse(LinkQueue Q)
{
    QueuePtr p = Q.front->next; // 跳过头结点

    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    return OK;
}
