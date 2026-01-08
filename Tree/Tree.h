#ifndef TREE_H
#define TREE_H

// 树的双亲表示法
typedef struct {
    int data;       // 结点数据
    int parent;     // 双亲位置
} PTNode;
typedef struct {
    PTNode *nodes;  // 结点数组
    int n;          // 结点数
} PTree;

// 树的孩子表示法
typedef struct CTNode {
    int child;                  // 孩子结点位置
    struct CTNode *next;        // 指向下一个孩子结点
} *ChildPtr;
typedef struct {
    int data;                   // 结点数据
    ChildPtr firstChild;       // 指向第一个孩子结点
} CTBox;
typedef struct {
    CTBox *nodes;               // 结点数组
    int n;                      // 结点数
} CTree;  

// 树的孩子兄弟表示法
typedef struct CSNode {
    int data;                   // 结点数据
    struct CSNode *firstChild;  // 指向第一个孩子结点
    struct CSNode *nextSibling; // 指向下一个兄弟结点
} *CSTree;



#endif // TREE_H