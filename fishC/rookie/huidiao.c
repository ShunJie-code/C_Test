#include <stdlib.h>
#include <stdio.h>

typedef int (*FuncPtr)(void);

// 注册函数
void populate_array(int *array, size_t arraySize, FuncPtr getNextValue)
{
    for (size_t i = 0; i < arraySize; i++)
        array[i] = getNextValue();
}
 
// 回调函数，获取随机值
int getNextRandomValue(void)
{
    return rand();
}

int getConstNum(void)
{
    return 8;
} 
int main(void)
{
    int myarray[10];
    /* getNextRandomValue 不能加括号，否则无法编译，因为加上括号之后相当于传入此参数时传入了 int , 而不是函数指针*/
    populate_array(myarray, 10, getNextRandomValue);
    for (int i = 0; i < 10; i++) {
        printf("%10d ", myarray[i]);
    }
    printf("\n");
    populate_array(myarray, 8, getConstNum);
    for (int i = 0; i < 10; i++) {
        printf("%10d ", myarray[i]);
    }
    printf("\n");
    return 0;
}