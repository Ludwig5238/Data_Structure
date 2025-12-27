#include "SqString.h"
#include <stdio.h>
// 重点KMP算法
// 初始化
Status InitString(SqString *T)
{
    T->length = 0;
    T->ch[0] = '\0';
    return OK;
}
// 赋值
Status StrAssign(SqString *T, const char *chars)
{
    int i = 0;
    while (chars[i] != '\0' && i < MAXSIZE)
    {
        T->ch[i] = chars[i];
        i++;
    }  
    T->length = i;
    T->ch[i] = '\0';
    return OK;
}
// 求串长度
int StrLength(const SqString T)
{
    return T.length;
}
// 串连接
Status Concat(SqString *T, const SqString S1, const SqString S2)
{
    if (S1.length + S2.length <= MAXSIZE)
    {
        for (int i = 0; i < S1.length; i++)
        {
            T->ch[i] = S1.ch[i];
        }
        for (int j = 0; j < S2.length; j++)
        {
            T->ch[S1.length + j] = S2.ch[j];
        }
        T->length = S1.length + S2.length;
        T->ch[T->length] = '\0';
    }
    else
    {
        for (int i = 0; i < S1.length; i++)
        {
            T->ch[i] = S1.ch[i];
        }
        for (int j = 0; j < MAXSIZE - S1.length; j++)
        {
            T->ch[S1.length + j] = S2.ch[j];
        }
        T->length = MAXSIZE;
        T->ch[T->length] = '\0';
    }
    return OK;
}
// 求子串
Status SubString(SqString *Sub, const SqString S, int pos, int len)
{
    if (pos < 1 || pos > S.length || len < 0 || pos + len - 1 > S.length)
    {
        return ERROR;
    }
    for (int i = 0; i < len; i++)
    {
        Sub->ch[i] = S.ch[pos - 1 + i];
    }
    Sub->length = len;
    Sub->ch[len] = '\0';
    return OK;
}
// 串比较
int StrCompare(const SqString S, const SqString T)
{
    int minLength = (S.length < T.length) ? S.length : T.length;
    for (int i = 0; i < minLength; i++)
    {
        if (S.ch[i] != T.ch[i])
        {
            return S.ch[i] - T.ch[i];
        }
    }
    return S.length - T.length;
}
// 清空串
Status ClearString(SqString *S)
{
    S->length = 0;
    S->ch[0] = '\0';
    return OK;
}
// 输出串
Status PrintString(const SqString S)
{
    for (int i = 0; i < S.length; i++)
    {
        putchar(S.ch[i]);
    }
    putchar('\n');
    return OK;
}
// 求子串在主串中的位置
int Index(const SqString S, const SqString T, int pos)
{
    if (pos < 1 || pos > S.length)
    {
        return 0;
    }
    for (int i = pos - 1; i <= S.length - T.length; i++)
    {
        int j = 0;
        while (j < T.length && S.ch[i + j] == T.ch[j])
        {
            j++;
        }
        if (j == T.length)
        {
            return i + 1; // 返回位置从1开始
        }
    }
    return 0; // 未找到
}
// KMP算法求子串在主串中的位置
int KMP_Index(const SqString S, const SqString T, int pos)
{
    if (pos < 1 || pos > S.length)
    {
        return 0;
    }
    int next[MAXSIZE];
    Compute_KMP_Next(T, next);
    int i = pos - 1; // 主串指针
    int j = 0;       // 子串指针
    while (i < S.length && j < T.length)
    {
        if (j == -1 || S.ch[i] == T.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j == T.length)
    {
        return i - T.length + 1; // 返回位置从1开始
    }
    else
    {
        return 0; // 未找到
    }
}
// 计算KMP算法中的next数组
void Compute_KMP_Next(const SqString T, int *next)
{
    
    int i = 0;
    int j = -1;
    next[0] = -1;
    while (i < T.length - 1)
    {
        if (j == -1 || T.ch[i] == T.ch[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}