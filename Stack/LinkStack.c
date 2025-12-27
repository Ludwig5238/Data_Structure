#include "LinkStack.h"
#include <stdlib.h>
#include <stdio.h>

// 初始化链栈
Status InitLinkStack(LinkStack *S)
{
    *S = NULL;
    return OK;
}
// 入栈
Status LinkPush(LinkStack *S, SElemType e)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (!newNode)
        return ERROR;
    newNode->data = e;
    newNode->next = *S;
    *S = newNode;
    return OK;
}
// 出栈
Status LinkPop(LinkStack *S, SElemType *e)
{
    if (*S == NULL)
        return ERROR;
    StackNode *temp = *S;
    *e = temp->data;
    *S = temp->next;
    free(temp);
    return OK;
}
// 判栈空
Status LinkStackEmpty(LinkStack S)
{
    return S == NULL ? TRUE : FALSE;
}
// 取栈顶
Status LinkGetTop(LinkStack S, SElemType *e)
{
    if (S == NULL)
        return ERROR;
    *e = S->data;
    return OK;
}
// 清空栈
Status ClearLinkStack(LinkStack *S)
{
    StackNode *current = *S;
    StackNode *temp;
    while (current)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    *S = NULL;
    return OK;
}
// 销毁栈
Status DestroyLinkStack(LinkStack *S)
{
    ClearLinkStack(S);
    return OK;
}
// 栈长度
int LinkStackLength(LinkStack S)
{
    int length = 0;
    StackNode *current = S;
    while (current)
    {
        length++;
        current = current->next;
    }
    return length;
}
// 遍历栈
Status LinkStackTraverse(LinkStack S)
{
    StackNode *current = S;
    while (current)
    {
        printf("%p ", current->data);
        current = current->next;
    }
    printf("\n");
    return OK;
}