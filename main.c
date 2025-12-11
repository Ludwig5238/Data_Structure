#include <stdio.h>
#include "LinkList/LinkList.h"

int main()
{
    LinkList L;
    Status status = InitList(&L);
    if (status == OK)
    {
        printf("初始化成功\n");
    }
    return 0;
}
