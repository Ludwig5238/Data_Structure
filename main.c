#include <stdio.h>
#include "Tree/BinaryTree.h"

int main()
{
    BiTree T;

    InitBiTree(&T);
    // 使用字符串创建二叉树
    const char *input = "ABC##DE#G##F###"; // 示例输入
    CreateBiTreeFromString(&T, input);
    printf("Pre-order traversal: ");
    PreOrderTraverse(T, Visit);
    printf("\nIn-order traversal: ");
    InOrderTraverse(T, Visit);
    printf("\nPost-order traversal: ");
    PostOrderTraverse(T, Visit);
    printf("\nLevel-order traversal: ");
    LevelOrderTraverse(T, Visit);
    // InOrderTraverseNonRecursion
    printf("\nIn-order non-recursive traversal: ");
    InOrderTraverseNonRecursion(T, Visit);
    printf("\n");
    DestroyBiTree(&T);

    return 0;
}
