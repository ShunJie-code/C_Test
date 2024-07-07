/**
 * 24 栈的清除和释放
 * 25 使用栈进制转换
 */
#include <stdio.h>
#include "stackapi.h"

void Test1(void)
{
    SqStack sta;
    ElemType e;
    int staLen;

    printf("%s_%d: \n", __func__, __LINE__);
    StackInit(&sta);
    // 测试压栈
    for (int i = 0; i < 30; i++)
    {
        StackPush(&sta, i);
    }
    // 测试读取栈的长度
    staLen = StackLen(sta);
    printf("%d: Stack length is %d\n", __LINE__, staLen);
    // 测试出栈
    for (int j = 0; j < 39; j++)
    {
        if (StackPop(&sta, &e) == SUCCESS)
        {
            printf("%d ", e);
        }
        else
        {
            break;
        }
    }
    putchar('\n');
    // 全部出栈后，栈长度为0
    staLen = StackLen(sta);
    printf("%d: Stack length is %d\n", __LINE__, staLen);
    StackDestroy(&sta);
    if (sta.base == NULL &&
        sta.top == NULL &&
        sta.stackSize == 0)
    {
        printf("StackDestroy is finished!\n");
    }
}

// 利用栈的数据结构的特点，将二进制数转换为十进制数

int main(void)
{
    Test1();
    return 0;
}