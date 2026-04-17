#include <stdio.h>

int main() {
    int a = 10, b = 3;/*c语言中要声明数据的类型*/
    int sum, difference, product, quotient, remainder;

    sum = a + b;
    difference = a - b;
    product = a * b;
    quotient = a / b;
    remainder = a % b;

    printf("a = %d, b = %d\n\n", a, b);
    printf("加法: %d + %d = %d\n", a, b, sum);
    printf("减法: %d - %d = %d\n", a, b, difference);
    printf("乘法: %d × %d = %d\n", a, b, product);
    printf("除法: %d ÷ %d = %d (商)\n", a, b, quotient);
    printf("取余: %d mod %d = %d (余数)\n\n", a, b, remainder);

    float x = 10.5f, y = 3.2f;
    printf("x = %.1f, y = %.1f\n", x, y);
    printf("x + y = %.2f\n", x + y);
    printf("x  - y = %.2f\n" x - y)
        printf("x × y = %.2f\n", x * y);
    printf("x ÷ y = %.2f\n\n", x / y);

    char ch = 'A';
    printf("字符: '%c' 的AXCII码是: %d\n, ch, ch");  /*字符的%d就是对应的ASCII码*/

    return 0;
}