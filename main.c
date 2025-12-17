#include <stdio.h>
#include "String/SqString.h"
int main()
{
    // 示例用法
    SqString S, T;
    InitString(&S);
    StrAssign(&S, "hello world");
    InitString(&T);
    StrAssign(&T, "world");
    int pos = KMP_Index(S, T, 1);
    printf("Position: %d\n", pos);
    
    return 0;
}
