/**
 * 练习6：函数基础
 * 练习函数的定义、调用和参数传递
 * 
 * 本程序演示了C语言中函数的写法：
 * 1. 加减乘除运算
 * 2. 计算阶乘（比如 5! = 5×4×3×2×1）
 * 3. 找出数组中的最大值
 */

#include <stdio.h>   // 引入标准输入输出库，才能使用 printf 等函数

// ----- 函数声明（告诉编译器这些函数将要被定义，方便调用）-----
int add(int a, int b);          // 加法函数：接收两个整数，返回它们的和
int subtract(int a, int b);     // 减法函数：返回 a - b
int multiply(int a, int b);     // 乘法函数：返回 a * b
double divide(double a, double b);  // 除法函数：返回 a / b（结果可能是小数）

// 计算阶乘的函数：比如 factorial(5) = 5×4×3×2×1 = 120
// 返回类型是 long long，因为阶乘结果可能很大
long long factorial(int n);

// 查找数组最大值的函数：给定一个整数数组和它的大小，返回最大的那个数
int findMax(int arr[], int size);

// ----- 主函数：程序的入口，从这里开始执行 -----
int main() {
    printf("=== 函数基础练习 ===\n\n");
    
    // ---------- 测试基本运算函数 ----------
    printf("基本运算:\n");
    // 调用 add 函数，把 10 和 5 传进去，打印返回的结果
    printf("add(10, 5) = %d\n", add(10, 5));          // 10 + 5 = 15
    printf("subtract(10, 5) = %d\n", subtract(10, 5)); // 10 - 5 = 5
    printf("multiply(10, 5) = %d\n", multiply(10, 5)); // 10 × 5 = 50
    // 除法结果可能是小数，用 %.2f 保留两位小数
    printf("divide(10, 5) = %.2f\n", divide(10, 5));   // 10 ÷ 5 = 2.00
    
    // ---------- 测试阶乘函数 ----------
    printf("\n阶乘计算:\n");
    // 用 for 循环计算 1! 到 10!，并打印
    for (int i = 1; i <= 10; i++) {
        // %lld 是 long long 类型的输出格式
        printf("%d! = %lld\n", i, factorial(i));
    }
    
    // ---------- 测试数组处理函数 ----------
    printf("\n数组处理:\n");
    int numbers[] = {23, 45, 12, 67, 34, 89, 56};  // 定义一个整数数组
    // sizeof(numbers) 得到整个数组占用的总字节数
    // sizeof(numbers[0]) 得到数组中第一个元素占用的字节数
    // 两者相除就是数组的元素个数
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("数组: ");
    // 遍历数组，依次打印每个元素
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    // 调用 findMax 函数，找出数组中的最大值
    int max = findMax(numbers, size);
    printf("最大值: %d\n", max);
    
    return 0;   // 返回 0 告诉操作系统程序运行成功
}

// ----- 函数定义（具体实现）-----

// 加法：返回 a + b
int add(int a, int b) {
    return a + b;
}

// 减法：返回 a - b
int subtract(int a, int b) {
    return a - b;
}

// 乘法：返回 a * b
int multiply(int a, int b) {
    return a * b;
}

// 除法：返回 a / b
// 注意：分母 b 不能是 0，否则数学上没有意义
double divide(double a, double b) {
    // 如果 b 等于 0，打印错误信息并返回 0
    if (b == 0) {
        printf("错误: 除数不能为0！\n");
        return 0;
    }
    return a / b;   // 正常除法
}

// 计算 n 的阶乘（n!）
// 阶乘定义：0! = 1, 1! = 1, 2! = 2×1 = 2, 3! = 3×2×1 = 6, ...
long long factorial(int n) {
    // 负数没有阶乘，打印错误信息
    if (n < 0) {
        printf("错误: 阶乘不支持负数！\n");
        return -1;   // 返回 -1 表示出错
    }
    // 0! 和 1! 都等于 1
    if (n == 0 || n == 1) {
        return 1;
    }
    
    // 从 2 开始一直乘到 n
    long long result = 1;   // 用 long long 存放积，防止溢出
    for (int i = 2; i <= n; i++) {
        result *= i;        // result = result * i
    }
    return result;
}

// 找出数组中的最大值
// arr[] 表示一个整数数组，size 表示数组中有多少个元素
int findMax(int arr[], int size) {
    // 如果数组大小小于等于 0，说明没有元素可找，打印错误信息
    if (size <= 0) {
        printf("错误: 数组大小必须大于0！\n");
        return -1;   // 返回 -1 表示出错
    }
    
    // 先假设第一个元素是最大的
    int max = arr[0];
    // 从第二个元素开始（下标1）依次与当前最大值比较
    for (int i = 1; i < size; i++) {
        // 如果发现更大的数，就更新 max
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;   // 返回找出的最大值
}