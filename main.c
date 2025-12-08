#include <stdio.h>

enum states
{
    FALSE = 0,
    ERROR = 0,
    TRUE = 1,
    OK = 1
};

int main()
{
    char status = OK;
    if (status == TRUE)
    {
        printf("Status is TRUE\n");
    }
    else
    {
        printf("Status is FALSE\n");
    }
    return 0;
}