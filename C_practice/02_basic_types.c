/**
 * 练习2：基本数据类型和运算
 * 练习变量声明、基本算术运算、输入输出
 */

#include <stdio.h>

int main() {
    int a = 10, b = 3;
    int sum, difference, product, quotient, remainder;
    
    sum = a + b;
    difference = a - b;
    product = a * b;
    quotient = a / b;
    remainder = a % b;
    
    printf("=== 基本算术运算 ===\n");
    printf("a = %d, b = %d\n\n", a, b);
    printf("加法: %d + %d = %d\n", a, b, sum);
    printf("减法: %d - %d = %d\n", a, b, difference);
    printf("乘法: %d × %d = %d\n", a, b, product);
    printf("除法: %d ÷ %d = %d (商)\n", a, b, quotient);
    printf("取余: %d mod %d = %d (余数)\n\n", a, b, remainder);
    
    // 浮点数运算
    float x = 10.5f, y = 3.2f;
    printf("=== 浮点数运算 ===\n");
    printf("x = %.1f, y = %.1f\n", x, y);
    printf("x + y = %.2f\n", x + y);
    printf("x - y = %.2f\n", x - y);
    printf("x × y = %.2f\n", x * y);
    printf("x ÷ y = %.2f\n\n", x / y);
    
    // 字符类型
    char ch = 'A';
    printf("=== 字符类型 ===\n");
    printf("字符 '%c' 的ASCII码是: %d\n", ch, ch);
    
    return 0;
}

%u #有符号数
%s #字符串
%h #短整型
%e #科学计数法