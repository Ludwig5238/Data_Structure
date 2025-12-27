#include "SqBiTree.h"
#include <stdio.h>

// 顺序存储二叉树的操作
int InitSqBiTree(SqBiTree *T)
{
    T->n = 0;
    return OK;
}
int DestroySqBiTree(SqBiTree *T)
{
    T->n = 0;
    return OK;
}
int CreateSqBiTree(SqBiTree *T)
{
    TElemType ch;
    int i = 0;
    while (i < MAX_TREE_SIZE)
    {
        scanf(" %c", &ch); // 注意：%c前面加了空格，会自动跳过空白字符
        if (ch == '#')
            T->data[i] = '\0'; // 用空字符表示空结点
        else
            T->data[i] = ch;
        i++;
    }
    T->n = i;
    return OK;
}
// 先序遍历
int PreOrderTraverseSq(SqBiTree T, int (*Visit)(TElemType), int index)
{
    if (index < T.n && T.data[index] != '\0')
    {
        Visit(T.data[index]);
        PreOrderTraverseSq(T, Visit, 2 * index + 1); // 左子结点下标
        PreOrderTraverseSq(T, Visit, 2 * index + 2); // 右子结点下标
    }
    return OK;
}
// 中序遍历
int InOrderTraverseSq(SqBiTree T, int (*Visit)(TElemType), int index)
{
    if (index < T.n && T.data[index] != '\0')
    {
        InOrderTraverseSq(T, Visit, 2 * index + 1); // 左子结点下标
        Visit(T.data[index]);
        InOrderTraverseSq(T, Visit, 2 * index + 2); // 右子结点下标
    }
    return OK;
}
// 后序遍历
int PostOrderTraverseSq(SqBiTree T, int (*Visit)(TElemType), int index)
{
    if (index < T.n && T.data[index] != '\0')
    {
        PostOrderTraverseSq(T, Visit, 2 * index + 1); // 左子结点下标
        PostOrderTraverseSq(T, Visit, 2 * index + 2); // 右子结点下标
        Visit(T.data[index]);
    }
    return OK;
}
int SqBiTreeEmpty(SqBiTree T)
{
    return T.n == 0 ? TRUE : FALSE;
}
int SqBiTreeDepth(SqBiTree T)
{
    int depth = 0;
    int n = T.n;
    while (n > 0)
    {
        depth++;
        n /= 2;
    }
    return depth;
}
TElemType GetSqBiTreeRoot(SqBiTree T)
{
    if (T.n == 0 || T.data[0] == '\0')
        return '\0'; // 树为空，返回空字符
    return T.data[0];
}
// visit function example
int VisitSq(TElemType e)
{
    printf("%c ", e);
    return OK;
}