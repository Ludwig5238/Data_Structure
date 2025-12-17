#ifndef LINKSTRING_H
#define LINKSTRING_H
// 不重要
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
// 链式存储结构的字符结点
typedef struct LNode
{
    char data;
    struct LNode *next;
} LNode, *LinkList;
// 链式存储结构的串
typedef struct
{
    LinkList head; // 指向链表头结点
    int length;    // 串的长度
} LinkString;
// 链式串的基本操作函数声明
// 初始化
Status InitLinkString(LinkString *T);
// 赋值
Status LinkStrAssign(LinkString *T, const char *chars);
// 求串长度
int LinkStrLength(const LinkString T);
// 串连接
Status LinkConcat(LinkString *T, const LinkString S1, const LinkString S2);
// 求子串
Status LinkSubString(LinkString *Sub, const LinkString S, int pos, int len);
// 串比较
int LinkStrCompare(const LinkString S, const LinkString T);
// 清空串
Status LinkClearString(LinkString *S);
// 输出串
Status LinkPrintString(const LinkString S);
// 求子串在主串中的位置
int LinkIndex(const LinkString S, const LinkString T, int pos);
// KMP算法求子串在主串中的位置
int LinkKMP_Index(const LinkString S, const LinkString T, int pos);
// 计算KMP算法中的next数组
void LinkCompute_KMP_Next(const LinkString T, int *next);

#endif // LINKSTRING_H