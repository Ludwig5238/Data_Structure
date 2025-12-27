#include <stdio.h>
#include "Tree/BinaryTree.h"

int main()
{
    BiTree T;
    InitBiTree(&T);
    // Further operations can be performed on the binary tree T
    CreateBiTree(&T);
    printf("Pre-order traversal: ");
    PreOrderTraverse(T, Visit);
    printf("\nIn-order traversal: ");
    InOrderTraverse(T, Visit);
    printf("\nPost-order traversal: ");
    PostOrderTraverse(T, Visit);
    printf("\n");
    DestroyBiTree(&T);

    return 0;
}
