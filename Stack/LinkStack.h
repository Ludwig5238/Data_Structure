#ifndef LINKSTACK_H
#define LINKSTACK_H

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int Status;
typedef int SElemType;

// 链栈的存储结构
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStack;

// 链栈的基本操作
// 初始化链栈
Status InitLinkStack(LinkStack *S);
// 入栈
Status LinkPush(LinkStack *S, SElemType e);
// 出栈
Status LinkPop(LinkStack *S, SElemType *e);
// 判栈空
Status LinkStackEmpty(LinkStack S);
// 取栈顶
Status LinkGetTop(LinkStack S, SElemType *e);
// 清空栈
Status ClearLinkStack(LinkStack *S);
// 销毁栈
Status DestroyLinkStack(LinkStack *S);
// 栈长度
int LinkStackLength(LinkStack S);
// 遍历栈
Status LinkStackTraverse(LinkStack S);

#endif // LINKSTACK_H