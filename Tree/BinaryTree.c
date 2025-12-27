#include "BinaryTree.h"
#include <stdlib.h>
#include <stdio.h>
#include "../Stack/LinkStack.h"
#include "../Queue/LinkQueue.h"
// 重点：二叉树遍历
// 二叉树的操作
int InitBiTree(BiTree *T)
{
    *T = NULL;
    return OK;
}
int DestroyBiTree(BiTree *T)
{
    if (*T)
    {
        DestroyBiTree(&(*T)->lchild);
        DestroyBiTree(&(*T)->rchild);
        free(*T);
        *T = NULL;
    }
    return OK;
}
int CreateBiTreeFromString(BiTree *T, const char *input)
{
    static int index = 0; // 使用static变量记录当前处理的位置
    TElemType ch = input[index++];
    if (ch == '#')
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!*T)
            return ERROR;
        (*T)->data = ch;
        CreateBiTreeFromString(&(*T)->lchild, input);
        CreateBiTreeFromString(&(*T)->rchild, input);
    }
    return OK;
}
int CreateBiTree(BiTree *T)
{
    TElemType ch;
    printf("Input node value (use '#' for NULL): ");
    scanf(" %c", &ch);
    if (ch == '#')
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!*T)
            return ERROR;
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
    return OK;
}
// 先序遍历
int PreOrderTraverse(BiTree T, int (*Visit)(TElemType))
{
    if (T)
    {
        Visit(T->data);
        PreOrderTraverse(T->lchild, Visit);
        PreOrderTraverse(T->rchild, Visit);
    }
    return OK;
}
// 中序遍历
int InOrderTraverse(BiTree T, int (*Visit)(TElemType))
{
    if (T)
    {
        InOrderTraverse(T->lchild, Visit);
        Visit(T->data);
        InOrderTraverse(T->rchild, Visit);
    }
    return OK;
}
// 后序遍历
int PostOrderTraverse(BiTree T, int (*Visit)(TElemType))
{
    if (T)
    {
        PostOrderTraverse(T->lchild, Visit);
        PostOrderTraverse(T->rchild, Visit);
        Visit(T->data);
    }
    return OK;
}
int BiTreeEmpty(BiTree T)
{
    return T == NULL;
}
int BiTreeDepth(BiTree T)
{
    if (!T)
        return 0;
    else
    {
        int lDepth = BiTreeDepth(T->lchild);
        int rDepth = BiTreeDepth(T->rchild);
        return (lDepth > rDepth ? lDepth : rDepth) + 1;
    }
}
TElemType GetRoot(BiTree T)
{
    if (T)
        return T->data;
    else
        return '\0'; // 或其他表示空的值
}

int Visit(TElemType e)
{
    printf("%c ", e);
    return OK;
}
// 二叉树中序非递归遍历算法
int InOrderTraverseNonRecursion(BiTree T, int (*Visit)(TElemType))
{
    LinkStack S;
    InitLinkStack(&S);
    BiTree p = T;
    while (p || !LinkStackEmpty(S))
    {
        if (p != NULL)
        {
            LinkPush(&S, (SElemType)p);
            p = p->lchild;
        }
        else
        {
            LinkPop(&S, (SElemType *)&p);
            Visit(p->data);
            p = p->rchild;
        }
    }
    DestroyLinkStack(&S);
    return OK;
}
// 二叉树层序遍历算法
int LevelOrderTraverse(BiTree T, int (*Visit)(TElemType))
{
    LinkQueue Q;
    InitQueue(&Q);
    BiTree p;
    if (T)
        EnQueue(&Q, (QElemType)T);
    while (!QueueEmpty(Q))
    {
        DeQueue(&Q, (QElemType *)&p);
        Visit(p->data);
        if (p->lchild)
            EnQueue(&Q, (QElemType)p->lchild);
        if (p->rchild)
            EnQueue(&Q, (QElemType)p->rchild);
    }
    DestroyQueue(&Q);
    return OK;
}