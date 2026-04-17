/**
 * 练习6：函数基础
 * 练习函数的定义、调用和参数传递
 */

#include <stdio.h>

// 函数声明
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(double a, double b);

// 计算阶乘的函数
long long factorial(int n);

// 查找数组最大值的函数
int findMax(int arr[], int size);

int main() {
    printf("=== 函数基础练习 ===\n\n");
    
    // 测试基本运算函数
    printf("基本运算:\n");
    printf("add(10, 5) = %d\n", add(10, 5));
    printf("subtract(10, 5) = %d\n", subtract(10, 5));
    printf("multiply(10, 5) = %d\n", multiply(10, 5));
    printf("divide(10, 5) = %.2f\n", divide(10, 5));
    
    // 测试阶乘函数
    printf("\n阶乘计算:\n");
    for (int i = 1; i <= 10; i++) {
        printf("%d! = %lld\n", i, factorial(i));
    }
    
    // 测试数组处理函数
    printf("\n数组处理:\n");
    int numbers[] = {23, 45, 12, 67, 34, 89, 56};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("数组: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    int max = findMax(numbers, size);
    printf("最大值: %d\n", max);
    
    return 0;
}

// 函数定义
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        printf("错误: 除数不能为0！\n");
        return 0;
    }
    return a / b;
}

long long factorial(int n) {
    if (n < 0) {
        printf("错误: 阶乘不支持负数！\n");
        return -1;
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int findMax(int arr[], int size) {
    if (size <= 0) {
        printf("错误: 数组大小必须大于0！\n");
        return -1;
    }
    
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
