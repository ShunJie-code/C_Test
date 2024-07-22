/**
 * @file pointer.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief C传递指针给函数，获取当前秒数
 * @version 0.1
 * @date 2023-03-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <time.h>


void GetSecond(unsigned long *par){
    *par = time(NULL);
    return;
}

double GetAverage(int *arr,int size){
    int sum = 0;
    double avg = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }
    avg = (double)sum / size;//没有强转，计算的结果会出错
    return avg;
}

void Test1(void)
{
    unsigned long sec;
    GetSecond(&sec);
    printf("Number of second : %ld\n", sec);
    // 数组首地址作为指针参数
    int array[5] = {10, 20, 30, 40, 56};
    printf("sizeof array : %d\n", sizeof(array));
    double avg = GetAverage(array, 5);
    printf("average of array : %f\n", avg);
}

// int *p[4]   // 一个长度为4的数组，数组元素为指向int类型的指针
// int (*p)[4]  //  一个指向数组长度为4的指针，类似于二级指针
// 指针数组
void Test2(void)
{
    int *p[2];
    int num[2][3] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 2; i++)
    {
        p[i] = num[i];
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // 占两个位置，右对齐
            printf("%2d", *(p[i] + j));
        }
        putchar('\n');
    }
}
// 数组指针
void Test3(void)
{
    int (*p)[3];
    int num[2][3] = {1, 2, 3, 4, 5, 6};
    p = num;
    for (int i = 0; i < 2; i++, p++)
    {
        for (int j = 0; j < 3; j++)
        {
            // 占三个位置，左对齐
            printf("%-3d", *(*p + j));
        }        
        // for (int i = 0; i < 3; i++)// 写法2
        // {
        //     printf("%-3d", *(*p + i));
        // }
        putchar('\n');
    }
}
int main(){
    // Test1();
    // Test2();
    Test3();
    return 0;
}

