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

void GetSecond(unsigned long *par);
double GetAverage(int *arr, int size);

int main(){
    unsigned long sec;
    GetSecond(&sec);
    printf("Number of second : %ld\n", sec);
    // 数组首地址作为指针参数
    int array[5] = {10, 20, 30, 40, 56};
    printf("sizeof array : %d\n", sizeof(array));
    double avg = GetAverage(array, 5);
    printf("average of array : %f\n", avg);
    return 0;
}

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