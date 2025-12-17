#include "SqQueue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 初始化队列
Status InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}
// 销毁队列
Status DestroyQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}
// 清空队列
Status ClearQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}
// 判断队列是否为空
Status QueueEmpty(SqQueue Q)
{
    if (Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}
// 求队列长度
int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
// 获取队头元素
Status GetHead(SqQueue Q, QElemType *e)
{
    if (Q.front == Q.rear)
        return ERROR; // 队列空
    *e = Q.data[Q.front];
    return OK;
}
// 入队
Status EnQueue(SqQueue *Q, QElemType e)
{
    // 队列满的判断条件是 (rear + 1) % MAXQSIZE == front,少留一个位置作为约定
    if ((Q->rear + 1) % MAXQSIZE == Q->front)
        return ERROR; // 队列满
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXQSIZE;
    // (Q->rear + 1) % MAXQSIZE的作用是实现循环队列的环绕效果
    // 当rear到达数组末尾时，再加1就回到数组的起始位置
    // 这样可以充分利用数组空间，避免浪费
    // 例如，假设MAXQSIZE为10，当前rear为9
    // 入队后，rear变为(9 + 1) % 10 = 0
    // rear = 5,(Q->rear + 1) % MAXQSIZE=6
    return OK;
}
// 出队
Status DeQueue(SqQueue *Q, QElemType *e)
{
    if (Q->front == Q->rear)
        return ERROR; // 队列空
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXQSIZE;
    return OK;
}
// 遍历队列
Status QueueTraverse(SqQueue Q, void (*visit)(QElemType))
{
    int i = Q.front;
    while (i != Q.rear)
    {
        visit(Q.data[i]);
        i = (i + 1) % MAXQSIZE;
    }
    return OK;
}