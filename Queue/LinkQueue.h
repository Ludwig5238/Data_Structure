#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1

typedef int Status;
typedef int QElemType;

// 链队列的存储结构
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

// 链队列类型定义
typedef struct
{
    QueuePtr front; // 队头指针
    QueuePtr rear;  // 队尾指针
} LinkQueue;

// 链队列基本操作
// 初始化队列
Status InitQueue(LinkQueue *Q);
// 销毁队列
Status DestroyQueue(LinkQueue *Q);
// 清空队列
Status ClearQueue(LinkQueue *Q);
// 判断队列是否为空
Status QueueEmpty(LinkQueue Q);
// 求队列长度
int QueueLength(LinkQueue Q);
// 获取队头元素
Status GetHead(LinkQueue Q, QElemType *e);
// 入队
Status EnQueue(LinkQueue *Q, QElemType e);
// 出队
Status DeQueue(LinkQueue *Q, QElemType *e);
// 遍历队列
Status QueueTraverse(LinkQueue Q, void (*visit)(QElemType));

#endif // LINKQUEUE_H
