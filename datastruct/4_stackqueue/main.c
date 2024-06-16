#include <stdio.h>
#include "stackdefine.h"

void Test1(void)
{
    SqStack sta;
    int e;

    printf("%s_%d: \n", __func__, __LINE__);
    StackInit(&sta);
    for (int i = 0; i < 30; i++)
    {
        StackPush(&sta, i);
    }
    for (int j = 0; j < 31; j++)
    {
        StackPop(&sta, &e);
        printf("%d ", e);
    }
    putchar('\n');
    
    
}

int main(void)
{
    Test1();
    return 0;
}