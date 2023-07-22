#include <stdio.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main()
{
    int int_a = 1;
    int int_b = 3;
    int int_c = MIN(int_a, int_b);
    printf("int MIN(a, b) = %d\n", int_c);
    double double_a = 1.78;
    double double_b = 2.99;
    double double_c = MAX(double_a, double_b);
    printf("double MAX(a, b) = %f\n", double_c);
    int diff = maxVal-minVal;
    return 0;
}