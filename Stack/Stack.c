#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>
// Stack implementation goes here
// main.c --- IGNORE ---
// 初始化栈
Status InitStack(SqStack *S)
{
    S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S->base)
        return ERROR; // 存储分配失败
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}
// 入栈
Status Push(SqStack *S, SElemType e)
{
    if (S->top - S->base >= S->stacksize)
    { // 栈满，追加存储空间
        S->base = (SElemType *)realloc(S->base, (S->stacksize + STACK_INIT_SIZE) * sizeof(SElemType));
        if (!S->base)
            return ERROR; // 存储分配失败
        S->top = S->base + S->stacksize;
        S->stacksize += STACK_INIT_SIZE;
    }
    *(S->top++) = e; // 将新元素e入栈
    return OK;
}
// 出栈, e为出栈元素
Status Pop(SqStack *S, SElemType *e)
{
    if (S->top == S->base)
        return ERROR; // 栈空
    // --S->top 和 S->top-- 的区别：
    // --S->top 是先将 S->top 指针向下移动一个位置，然后再访问该位置的元素。
    // S->top-- 是先访问当前 S->top 指针所指向的元素，然后再将 S->top 指针向下移动一个位置。
    *e = *(--S->top); // 将栈顶元素赋值给e
    return OK;
}
// 判栈空
Status StackEmpty(SqStack S)
{
    if (S.top == S.base)
        return TRUE;
    else
        return FALSE;
}
// 取栈顶
Status GetTop(SqStack S, SElemType *e)
{
    if (S.top == S.base)
        return ERROR; // 栈空
    // s.top 指向栈顶元素的下一个位置，所以栈顶元素是 *(s.top - 1)
    *e = *(S.top - 1); // 将栈顶元素赋值给e
    return OK;
}
// 清空栈
Status ClearStack(SqStack *S)
{
    S->top = S->base; // 只需将栈顶指针回退到栈底
    return OK;
}
// 销毁栈
Status DestroyStack(SqStack *S)
{
    if (S->base)
    {
        free(S->base);
        S->base = NULL;
        S->top = NULL;
        S->stacksize = 0;
    }
    return OK;
}
// 栈长度
int StackLength(SqStack S)
{
    return S.top - S.base;
}
// 遍历栈
Status StackTraverse(SqStack S)
{
    SElemType *p;
    p = S.base;
    printf("Stack elements: ");
    while (p < S.top)
    {
        printf("%d ", *p);
        p++;
    }
    printf("\n");
    return OK;
}
