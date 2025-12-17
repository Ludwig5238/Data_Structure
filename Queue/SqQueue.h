#ifndef SQ_QUEUE_H
#define SQ_QUEUE_H

#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1

typedef int Status;
typedef int QElemType;

// 顺序队列定义
#define MAXQSIZE 10 // 最大队列长度
typedef struct
{
    QElemType data[MAXQSIZE];
    int front; // 队头指针
    int rear;  // 队尾指针
} SqQueue;

// 顺序队列基本操作
// 初始化队列
Status InitQueue(SqQueue *Q);
// 销毁队列
Status DestroyQueue(SqQueue *Q);
// 清空队列
Status ClearQueue(SqQueue *Q);
// 判断队列是否为空
Status QueueEmpty(SqQueue Q);
// 求队列长度
int QueueLength(SqQueue Q);
// 获取队头元素
Status GetHead(SqQueue Q, QElemType *e);
// 入队
Status EnQueue(SqQueue *Q, QElemType e);
// 出队
Status DeQueue(SqQueue *Q, QElemType *e);
// 遍历队列
Status QueueTraverse(SqQueue Q, void (*visit)(QElemType));

#endif // QUEUE_H