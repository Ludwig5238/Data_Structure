#ifndef STACK_H
#define STACK_H

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

#define STACK_INIT_SIZE 10 // 存储空间初始分配量

typedef int Status;    // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int SElemType; // SElemType类型根据实际情况而定，这里假设为int
// 顺序栈的存储结构
typedef struct
{
    SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
    SElemType *top;  // 栈顶指针
    int stacksize;   // 当前已分配的存储空间，以元素为单位
} SqStack;

// 栈的基本操作
// 初始化栈
Status InitStack(SqStack *S);
// 入栈
Status Push(SqStack *S, SElemType e);
// 出栈
Status Pop(SqStack *S, SElemType *e);
// 判栈空
Status StackEmpty(SqStack S);
// 取栈顶
Status GetTop(SqStack S, SElemType *e);
// 清空栈
Status ClearStack(SqStack *S);
// 销毁栈
Status DestroyStack(SqStack *S);
// 栈长度
int StackLength(SqStack S);
// 遍历栈,element is int
Status StackTraverse(SqStack S);

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


#endif // STACK_H