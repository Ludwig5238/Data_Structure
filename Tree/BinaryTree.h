#ifndef BINARYTREE_H
#define BINARYTREE_H

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

// 二叉树结点类型定义
typedef char TElemType;
typedef struct BiTNode
{
    TElemType data;                  // 结点数据
    struct BiTNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

// 二叉树的操作
int InitBiTree(BiTree *T);
int DestroyBiTree(BiTree *T);
// 从字符串创建二叉树
int CreateBiTreeFromString(BiTree *T, const char *input);
int CreateBiTree(BiTree *T);
// 先序遍历
int PreOrderTraverse(BiTree T, int (*Visit)(TElemType));
// 中序遍历
int InOrderTraverse(BiTree T, int (*Visit)(TElemType));
// 后序遍历
int PostOrderTraverse(BiTree T, int (*Visit)(TElemType));
int BiTreeEmpty(BiTree T);
int BiTreeDepth(BiTree T);
TElemType GetRoot(BiTree T);
// 二叉树中序非递归遍历算法
int InOrderTraverseNonRecursion(BiTree T, int (*Visit)(TElemType));
// 二叉树层序遍历算法
int LevelOrderTraverse(BiTree T, int (*Visit)(TElemType));

// visit function example
int Visit(TElemType e);

#endif // BINARYTREE_H