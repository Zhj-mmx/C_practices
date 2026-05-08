#include <stdio.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(double a, double b);

long long factorial(int n);

int findMax(int arr[], int size);

int main() {
    printf("=== 函数基础练习 ===\n\n");
    printf("add(10, 5) = %d\n", add(10, 5));          // 10 + 5 = 15
    printf("subtract(10, 5) = %d\n", subtract(10, 5)); // 10 - 5 = 5
    printf("multiply(10, 5) = %d\n", multiply(10, 5));
    printf("divide(10, 5) = %.2f\n", divide(10, 5));

    printf("\n阶乘计算:\n");

    for (int i = 1; i <= 10; i++) {
        printf("%d! = %lld\n", i, factorial(i));
    }

    printf("\n数组处理:\n");
    int numbers[] = { 23, 45, 12, 67, 34, 89, 56 };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("数组: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    int max = findMax(numbers, size);
    printf("最大值: %d\n", max);

    return 0;
}

// ----- 函数定义（具体实现）-----

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
    // 如果 b 等于 0，打印错误信息并返回 0
    if (b == 0) {
        printf("错误: 除数不能为0！\n");
        return 0;
    }
    return a / b;   // 正常除法
}

long long factorial(int n) {
    if (n < 0) {
        printf("错误: 阶乘不支持负数！\n");
        return -1;
    }

    if (n == 0 || n == 1) {
        return 1;
    }

    long long result = 1;   // 用 long long 存放积，防止溢出
    for (int i = 2; i <= n; i++) {
        result *= i;        // result = result * i
    }
    return result;

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