#include <stdio.h>
#include <stdlib.h>

// 链表节点结构
typedef struct Node {
    int data;           // 节点存储的数据
    struct Node* next;  // 指向下一个节点的指针
} Node;

// 带尾指针的循环链表结构
typedef struct {
    Node* head;         // 指向哨兵节点（不存储数据）
    Node* tail;         // 指向最后一个实际数据节点
    int size;           // 链表长度（不包括哨兵节点）
} CircularList;

// 创建新节点 - 时间复杂度: O(1)
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// 初始带尾指针的循环链表（带头节点） - 时间复杂度: O(1)
CircularList* init_circular_list() {
    CircularList* list = (CircularList*)malloc(sizeof(CircularList));
    
    // 创建哨兵节点（头节点）
    Node* head_node = create_node(-1);
    head_node->next = head_node; // 自环
    
    list->head = head_node;
    list->tail = head_node; // 开始时尾指针指向哨兵节点
    list->size = 0;
    return list;
}

// 检查链表是否为空 - 时间复杂度: O(1)
int is_empty(CircularList* list) {
    return list->size == 0;
}

// 哨兵节点存在判断 - 时间复杂度: O(1)
int has_head(CircularList* list) {
    return list->head != NULL && list->head->next == list->head;
}

// 在链表头部插入 - 时间复杂度: O(1)
void insert_at_head(CircularList* list, int data) {
    Node* new_node = create_node(data);
    new_node->next = list->head->next;
    list->head->next = new_node;
    list->size++;
    
    // 如果链表为空，更新尾指针
    if (list->tail == list->head) {
        list->tail = new_node;
    }
}

// 在链表尾部插入 - 时间复杂度: O(1)（优化点！）
void insert_at_tail(CircularList* list, int data) {
    Node* new_node = create_node(data);
    
    new_node->next = list->head; // 新节点指向头节点（哨兵）
    list->tail->next = new_node; // 原尾节点指向新节点
    list->tail = new_node;       // 更新尾指针
    
    // 如果链表为空，头指针的下一个也要更新
    if (is_empty(list)) {
        list->head->next = new_node;
    }
    
    list->size++;
}

// 在指定位置插入 - 时间复杂度: O(n)
void insert_at_position(CircularList* list, int position, int data) {
    if (position < 0 || position > list->size) {
        printf("无效位置: %d\n", position);
        return;
    }
    
    // 位置0相当于头部插入
    if (position == 0) {
        insert_at_head(list, data);
        return;
    }
    
    // 尾部插入
    if (position == list->size) {
        insert_at_tail(list, data);
        return;
    }
    
    // 找到插入位置的前驱节点
    Node* current = list->head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    
    Node* new_node = create_node(data);
    new_node->next = current->next;
    current->next = new_node;
    list->size++;
}

// 从头部删除节点 - 时间复杂度: O(1)
int delete_from_head(CircularList* list) {
    if (is_empty(list)) {
        printf("链表为空，无法删除\n");
        return -1; // 错误值
    }
    
    Node* to_delete = list->head->next;
    int deleted_data = to_delete->data;
    
    list->head->next = to_delete->next;
    
    // 如果删除的是唯一节点，更新尾指针
    if (to_delete == list->tail) {
        list->tail = list->head;
        list->head->next = list->head; // 恢复自环
    }
    
    free(to_delete);
    list->size--;
    return deleted_data;
}

// 从尾部删除节点 - 时间复杂度: O(n) → O(1)的挑战（需要双向链表）
int delete_from_tail(CircularList* list) {
    if (is_empty(list)) {
        printf("链表为空，无法删除\n");
        return -1; // 错误值
    }
    
    Node* current = list->head;
    Node* prev = NULL;
    
    // 找到尾节点及其前驱（循环链表尾部删除天然O(n)）
    while (current->next != list->tail) {
        current = current->next;
    }
    
    // 删除尾节点
    prev = current;
    Node* to_delete = list->tail;
    int deleted_data = to_delete->data;
    
    prev->next = list->head; // 新的尾节点指向头节点
    list->tail = prev;       // 更新尾指针
    
    // 如果删除后链表为空
    if (list->size == 1) {
        list->tail = list->head;
        list->head->next = list->head;
    }
    
    free(to_delete);
    list->size--;
    return deleted_data;
}

// 按位置删除节点 - 时间复杂度: O(n)
int delete_by_position(CircularList* list, int position) {
    if (position < 0 || position >= list->size) {
        printf("无效位置: %d\n", position);
        return -1;
    }
    
    // 头部删除
    if (position == 0) {
        return delete_from_head(list);
    }
    
    // 尾部删除
    if (position == list->size - 1) {
        return delete_from_tail(list);
    }
    
    // 找到要删除节点的前驱
    Node* prev = list->head;
    for (int i = 0; i < position; i++) {
        prev = prev->next;
    }
    
    Node* to_delete = prev->next;
    int deleted_data = to_delete->data;
    
    prev->next = to_delete->next;
    free(to_delete);
    list->size--;
    
    return deleted_data;
}

// 按值删除节点 - 时间复杂度: O(n)
int delete_by_value(CircularList* list, int value) {
    if (is_empty(list)) {
        printf("链表为空\n");
        return 0;
    }
    
    Node* current = list->head->next;
    Node* prev = list->head;
    int count = 0;
    
    // 遍历整个链表
    while (current != list->head) {
        if (current->data == value) {
            // 处理尾节点更新
            if (current == list->tail) {
                list->tail = prev;
            }
            
            // 删除节点
            prev->next = current->next;
            free(current);
            current = prev->next;
            count++;
            list->size--;
        } else {
            prev = current;
            current = current->next;
        }
    }
    
    return count;
}

// 查找位置 - 时间复杂度: O(n)
int find_position(CircularList* list, int value) {
    if (is_empty(list)) {
        return -1;
    }
    
    int position = 0;
    Node* current = list->head->next;
    
    while (current != list->head) {
        if (current->data == value) {
            return position;
        }
        current = current->next;
        position++;
    }
    
    return -1; // 未找到
}

// 判断是否存在 - 时间复杂度: O(n)
int contains(CircularList* list, int value) {
    Node* current = list->head->next;
    
    while (current != list->head) {
        if (current->data == value) {
            return 1;
        }
        current = current->next;
    }
    
    return 0;
}

// 获取链表长度 - 时间复杂度: O(1)
int get_length(CircularList* list) {
    return list->size;
}

// 打印链表内容 - 时间复杂度: O(n)
void print_list(CircularList* list) {
    if (is_empty(list)) {
        printf("链表为空\n");
        return;
    }
    
    // 验证循环结构完整性
    printf("head=%p, size=%d, tail=%p, tail->next=%p (should be head: %p)\n", 
        list->head, list->size, list->tail, list->tail->next, list->head);
    
    Node* current = list->head->next;
    
    printf("循环链表内容: ");
    while (current != list->head) {
        printf("%d", current->data);
        current = current->next;
        
        if (current != list->head) {
            printf(" → ");
        }
    }
    
    printf(" → [哨兵] → ...\n");
}

// 销毁链表 - 时间复杂度: O(n)
void destroy_list(CircularList* list) {
    Node* current = list->head->next;
    Node* temp;
    
    // 释放所有数据节点
    while (current != list->head) {
        temp = current;
        current = current->next;
        free(temp);
    }
    
    // 释放哨兵节点
    free(list->head);
    
    // 释放链表结构
    free(list);
}

// 约瑟夫环问题求解（使用尾指针优化）
void josephus_simulation(CircularList* list, int k) {
    if (is_empty(list)) {
        printf("链表为空\n");
        return;
    }
    
    // 为了便于操作，先将指针移动到起始位置
    Node* prev = list->tail;
    Node* current = list->head->next;
    
    printf("约瑟夫环淘汰序列: ");
    
    // 构建初始循环（跳过哨兵节点）
    while (prev == list->tail && current == list->head->next) {
        list->tail->next = list->head->next;
        list->head->next = list->head; 
    }
    
    // 模拟过程
    while (list->size > 0) {
        // 查找第k个节点
        for (int i = 1; i < k; i++) {
            prev = current;
            current = current->next;
        }
        
        // 删除当前节点
        printf("%d ", current->data);
        
        // 维护尾指针
        if (current == list->tail) {
            list->tail = prev;
        }
        if (current == list->head->next) {
            list->head->next = list->head->next->next;
        }
        
        prev->next = current->next; // 前驱连向后继
        Node* to_delete = current;
        current = current->next;    // 移动到下一个起始点
        
        free(to_delete);
        list->size--;
    }
    
    // 恢复基本结构
    list->tail->next = list->head;
    list->head->next = list->tail;
    printf("\n");
}

// 主函数测试
int main() {
    // 初始化带尾指针的循环链表
    CircularList* list = init_circular_list();
    
    printf("====== 带尾指针的循环链表操作演示 ======\n");
    
    // 尾部插入测试
    printf("\n--- 尾部插入测试 ---\n");
    insert_at_tail(list, 10);
    insert_at_tail(list, 20);
    insert_at_tail(list, 30);
    printf("插入10,20,30后: ");
    print_list(list);
    printf("尾指针位置: %p, 数据: %d\n", list->tail, list->tail->data);
    
    // 头部插入测试
    printf("\n--- 头部插入测试 ---\n");
    insert_at_head(list, 5);
    insert_at_head(list, 3);
    printf("头部插入5,3后: ");
    print_list(list);
    printf("第一个节点: %d\n", list->head->next->data);
    
    // 定位插入测试
    printf("\n--- 定位插入测试 ---\n");
    insert_at_position(list, 2, 15);
    insert_at_position(list, 4, 25);
    printf("位置2插入15,位置4插入25后: ");
    print_list(list);
    
    // 删除操作测试
    printf("\n--- 删除操作测试 ---\n");
    printf("删除头部: %d\n", delete_from_head(list));
    print_list(list);
    printf("删除尾部: %d\n", delete_from_tail(list));
    print_list(list);
    printf("位置2删除: %d\n", delete_by_position(list, 2));
    print_list(list);
    
    // 按值删除测试
    printf("\n--- 按值删除测试 ---\n");
    insert_at_tail(list, 15);
    insert_at_tail(list, 10);
    printf("添加15,10后: ");
    print_list(list);
    printf("删除值=10: %d个\n", delete_by_value(list, 10));
    print_list(list);
    
    // 约瑟夫问题模拟
    printf("\n====== 约瑟夫环问题模拟 ======\n");
    destroy_list(list);
    list = init_circular_list();
    
    for (int i = 1; i <= 7; i++) {
        insert_at_tail(list, i);
    }
    
    printf("初始人员: ");
    print_list(list);
    printf("每3人淘汰一个（从1开始）:\n");
    josephus_simulation(list, 3);
    
    // 清理资源
    destroy_list(list);
    
    return 0;
}


// 顺序线性表
// 单链表
// 循环链表
// 双向链表
// 双向循环链表
