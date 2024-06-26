/**
 * C 语言是一种通用的、面向过程式的计算机程序设计语言。1972 年，为了移植与开发 UNIX 操作系统，丹尼斯·里奇在贝尔电话实验室设计开发了 C 语言。
 * C 语言是一种广泛使用的计算机语言，它与 Java 编程语言一样普及，二者在现代软件程序员之间都得到广泛使用。
 * 当前最新的 C 语言标准为 C18 ，在它之前的 C 语言标准有 C17、C11...C99 等。
*/

#include <stdio.h>
#include <math.h>

int main(){
    printf("hello boy!\n");
    char c = getchar();
    printf("---c = %c---\n", c);
    int i = sqrt(169);
    printf("---sqrt i = %d---\n", i);
    i = pow(10, 2);
    printf("---pow i = %d---\n", i);
    return 0;
}