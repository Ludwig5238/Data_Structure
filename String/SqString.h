#ifndef SQLSTRING_H
#define SQLSTRING_H

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

// 串的顺序存储结构
#define MAXSIZE 255
typedef struct
{
    char ch[MAXSIZE + 1]; // 多分配一个存储串的结束标志'\0'
    int length;
} SqString;

// 顺序串的基本操作函数声明
// 初始化
Status InitString(SqString *T);
// 赋值
Status StrAssign(SqString *T, const char *chars);
// 求串长度
int StrLength(const SqString T);
// 串连接
Status Concat(SqString *T, const SqString S1, const SqString S2);
// 求子串
Status SubString(SqString *Sub, const SqString S, int pos, int len);
// 串比较
int StrCompare(const SqString S, const SqString T);
// 清空串
Status ClearString(SqString *S);
// 输出串
Status PrintString(const SqString S);
// 求子串在主串中的位置
int Index(const SqString S, const SqString T, int pos);
// KMP算法求子串在主串中的位置
int KMP_Index(const SqString S, const SqString T, int pos);
// 计算KMP算法中的next数组
void Compute_KMP_Next(const SqString T, int *next);

#endif // SQLSTRING_H