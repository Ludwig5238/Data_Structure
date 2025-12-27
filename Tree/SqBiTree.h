#ifndef SQBITREE_H
#define SQBITREE_H

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

// 二叉树的顺序存储结构定义
typedef char TElemType;
#define MAX_TREE_SIZE 100 // 最大树容量
typedef struct
{
    TElemType data[MAX_TREE_SIZE]; // 存储二叉树结点元素
    int n;                         // 结点数
} SqBiTree;

// 顺序存储二叉树的操作
int InitSqBiTree(SqBiTree *T);
int DestroySqBiTree(SqBiTree *T);
int CreateSqBiTree(SqBiTree *T);
// 先序遍历
int PreOrderTraverseSq(SqBiTree T, int (*Visit)(TElemType), int index);
// 中序遍历
int InOrderTraverseSq(SqBiTree T, int (*Visit)(TElemType), int index);
// 后序遍历
int PostOrderTraverseSq(SqBiTree T, int (*Visit)(TElemType), int index);
int SqBiTreeEmpty(SqBiTree T);
int SqBiTreeDepth(SqBiTree T);
TElemType GetSqBiTreeRoot(SqBiTree T);
// visit function example
int VisitSq(TElemType e);

#endif // SQBITREE_H