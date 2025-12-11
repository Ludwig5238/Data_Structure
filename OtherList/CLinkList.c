#include "OtherList.h" 

// 初始化具有头指针的循环链表
Status InitCLinkList(CLinkList *L)
{
    *L = (CLinkList)malloc(sizeof(CNode));
    if (!*L)
        return ERROR;
    (*L)->next = *L; // 头结点指向自己，形成循环
    return OK;
}

// 创建尾指针循环链表
Status CreateCTailList(CLinkList *L)
{
    CLinkList tail;
    ElemType e;
    *L = (CLinkList)malloc(sizeof(CNode));
    if (!*L)
        return ERROR;
    (*L)->next = *L; // 头结点指向自己，形成循环
    tail = *L;      // 初始时尾指针指向头结点

    printf("请输入元素值，输入-1结束:\n");
    while (1)
    {
        scanf("%d", &e);
        if (e == -1)
            break;
        CLinkList newNode = (CLinkList)malloc(sizeof(CNode));
        if (!newNode)
            return ERROR;
        newNode->data = e;
        newNode->next = (*L); // 新结点指向头结点
        tail->next = newNode; // 尾结点指向新结点
        tail = newNode;       // 更新尾指针
    }
    return OK;
}

// 创建头指针循环链表
Status CreateCHeadList(CLinkList *L)
{
    ElemType e;
    *L = (CLinkList)malloc(sizeof(CNode));
    if (!*L)
        return ERROR;
    (*L)->next = *L; // 头结点指向自己，形成循环

    CLinkList tail = *L; // 尾指针初始化为头结点

    printf("请输入元素值，输入-1结束:\n");
    while (1)
    {
        scanf("%d", &e);
        if (e == -1)
            break;
        CLinkList newNode = (CLinkList)malloc(sizeof(CNode));
        if (!newNode)
            return ERROR;
        newNode->data = e;
        newNode->next = (*L); // 新结点指向头结点
        tail->next = newNode; // 尾结点指向新结点
        tail = newNode;       // 更新尾指针
    }
    return OK;
}