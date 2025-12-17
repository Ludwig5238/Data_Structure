#include <stdio.h>
#include "Queue/LinkQueue.h"

// 打印元素的辅助函数
void printElement(QElemType e)
{
    printf("%d ", e);
}

// 测试链队列
void testLinkQueue()
{
    LinkQueue Q;
    QElemType e;
    int i;
    
    printf("=== 链队列测试 ===\n");
    
    // 1. 初始化队列
    printf("1. 初始化队列...\n");
    if (InitQueue(&Q) == OK)
        printf("   初始化成功\n");
    else
        printf("   初始化失败\n");
    
    // 2. 判断队列是否为空
    printf("2. 判断队列是否为空: ");
    if (QueueEmpty(Q) == TRUE)
        printf("队列为空\n");
    else
        printf("队列不为空\n");
    
    // 3. 入队操作
    printf("3. 入队操作 (入队元素: 10, 20, 30, 40, 50)...\n");
    for (i = 10; i <= 50; i += 10)
    {
        if (EnQueue(&Q, i) == OK)
            printf("   元素 %d 入队成功\n", i);
        else
            printf("   元素 %d 入队失败\n", i);
    }
    
    // 4. 遍历队列
    printf("4. 遍历队列:\n");
    QueueTraverse(Q, printElement);
    
    // 5. 获取队头元素
    printf("5. 获取队头元素: ");
    if (GetHead(Q, &e) == OK)
        printf("队头元素为 %d\n", e);
    else
        printf("获取队头元素失败\n");
    
    // 6. 求队列长度
    printf("6. 队列长度: %d\n", QueueLength(Q));
    
    // 7. 出队操作
    printf("7. 出队操作...\n");
    if (DeQueue(&Q, &e) == OK)
        printf("   出队元素: %d\n", e);
    
    if (DeQueue(&Q, &e) == OK)
        printf("   出队元素: %d\n", e);
    
    // 8. 再次遍历队列
    printf("8. 出队两次后遍历队列:\n");
    QueueTraverse(Q, printElement);
    
    // 9. 再次获取队头元素
    printf("9. 获取队头元素: ");
    if (GetHead(Q, &e) == OK)
        printf("队头元素为 %d\n", e);
    else
        printf("获取队头元素失败\n");
    
    // 10. 测试空队列操作
    printf("10. 测试空队列操作...\n");
    printf("   清空队列...\n");
    if (ClearQueue(&Q) == OK)
        printf("   清空成功\n");
    else
        printf("   清空失败\n");
    
    printf("   尝试从空队列出队: ");
    if (DeQueue(&Q, &e) == ERROR)
        printf("正确返回错误 (队列为空)\n");
    else
        printf("错误: 应该返回错误\n");
    
    printf("   尝试获取空队列队头: ");
    if (GetHead(Q, &e) == ERROR)
        printf("正确返回错误 (队列为空)\n");
    else
        printf("错误: 应该返回错误\n");
    
    // 11. 测试重新入队
    printf("11. 测试重新入队 (入队元素: 100, 200)...\n");
    if (EnQueue(&Q, 100) == OK)
        printf("   元素 100 入队成功\n");
    if (EnQueue(&Q, 200) == OK)
        printf("   元素 200 入队成功\n");
    
    printf("   遍历队列:\n");
    QueueTraverse(Q, printElement);
    
    // 12. 销毁队列
    printf("12. 销毁队列...\n");
    if (DestroyQueue(&Q) == OK)
        printf("   销毁成功\n");
    else
        printf("   销毁失败\n");
    
    printf("=== 链队列测试结束 ===\n\n");
}

// 测试边界情况
void testEdgeCases()
{
    LinkQueue Q;
    QElemType e;
    
    printf("=== 边界情况测试 ===\n");
    
    // 测试未初始化队列的操作
    printf("1. 测试未初始化队列...\n");
    printf("   尝试在未初始化队列上出队: ");
    if (DeQueue(&Q, &e) == ERROR)
        printf("正确返回错误\n");
    else
        printf("可能有问题\n");
    
    // 初始化队列
    printf("2. 初始化队列...\n");
    InitQueue(&Q);
    
    // 测试单个元素队列
    printf("3. 测试单个元素队列...\n");
    EnQueue(&Q, 999);
    printf("   入队元素 999\n");
    printf("   队列长度: %d\n", QueueLength(Q));
    
    DeQueue(&Q, &e);
    printf("   出队元素: %d\n", e);
    
    printf("   出队后队列是否为空: ");
    if (QueueEmpty(Q) == TRUE)
        printf("是\n");
    else
        printf("否\n");
    
    // 销毁队列
    DestroyQueue(&Q);
    printf("4. 队列已销毁\n");
    
    printf("=== 边界情况测试结束 ===\n\n");
}

int main()
{
    // 测试链队列
    testLinkQueue();
    
    // 测试边界情况
    testEdgeCases();
    
    return 0;
}
