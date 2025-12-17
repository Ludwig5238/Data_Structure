#include <stdio.h>
#include "Stack/LinkStack.h"

int main()
{
    LinkStack S;
    InitLinkStack(&S);
    LinkPush(&S, 10);
    LinkPush(&S, 20);
    LinkPush(&S, 30);
    SElemType e;
    LinkPop(&S, &e);
    printf("Popped element: %d\n", e);
    LinkGetTop(S, &e);
    printf("Top element: %d\n", e);
    LinkStackTraverse(S);
    ClearLinkStack(&S);
    DestroyLinkStack(&S);

    return 0;
}


// 顺序线性表
// 单链表
// 循环链表
// 双向链表
// 双向循环链表
