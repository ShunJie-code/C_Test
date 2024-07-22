/**
 * @file Classic100_2.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 企业发放的奖金根据利润提成
 * 从键盘输入当月利润I，求应发放奖金总数？
 * 利润(I)低于或等于10万元时，奖金可提10%；
 * 利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可提成7.5%；
 * 20万到40万之间时，高于20万元的部分，可提成5%；
 * 40万到60万之间时高于40万元的部分，可提成3%；
 * 60万到100万之间时，高于60万元的部分，可提成1.5%；
 * 高于100万元时，超过100万元的部分按1%提成。
 * @version 0.1
 * @date 2023-03-11
 * @copyright Copyright (c) 2023
 */
#include <stdio.h>

int main(void){
    double i;
    printf("Your profit is :\n");
    scanf("%lf", &i);                              //scanf_s更安全
    i /=10000;
    double bonus;
    double bonus1, bonus2, bonus4, bonus6, bonus10;
    bonus1 = 10 * 0.10;
    bonus2 = bonus1 + 10 * 0.75;
    bonus4 = bonus2 + 20 * 0.05;
    bonus6 = bonus4 + 20 * 0.03;
    bonus10 = bonus6 + 40 * 0.015;

    if(i <= 10){
        bonus = i * 0.10;
    }else if(i <= 20){
        bonus = bonus1 + (i - 10) * 0.075;
    }else if(i <= 40){
        bonus = bonus2 + (i - 20) * 0.05;
    }else if(i <= 60){
        bonus = bonus4 + (i - 40) * 0.03;
    }else if(i <= 100){
        bonus = bonus6 + (i - 60) * 0.015;
    }else{
        bonus = bonus10 + (i - 100) * 0.01;
    }
    bonus *= 10000;
    printf("bonus = %lf.\n", bonus);
    return 0;
}
