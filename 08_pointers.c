/**
 * 练习8：指针基础（进阶）
 * 练习指针的概念、声明和基本使用
 */

#include <stdio.h>

int main() {
    printf("=== 指针基础练习 ===\n\n");
    
    // 练习1: 基本指针概念
    printf("1. 基本指针概念:\n");
    int var = 42;
    int *ptr = &var;
    
    printf("   变量 var 的值: %d\n", var);
    printf("   变量 var 的地址: %p\n", (void*)&var);
    printf("   指针 ptr 保存的地址: %p\n", (void*)ptr);
    printf("   通过指针访问的值 (*ptr): %d\n", *ptr);
    
    // 修改指针指向的值
    *ptr = 100;
    printf("\n   修改 *ptr = 100 后:\n");
    printf("   var 的值现在是: %d\n\n", var);
    
    // 练习2: 指针与数组
    printf("2. 指针与数组:\n");
    int arr[] = {10, 20, 30, 40, 50};
    int *arrPtr = arr;  // 数组名代表首元素地址
    
    printf("   数组内容: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(arrPtr + i));
    }
    printf("\n");
    
    // 使用指针遍历
    printf("   指针遍历: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arrPtr[i]);
    }
    printf("\n\n");
    
    // 练习3: 指向指针的指针
    printf("3. 指向指针的指针:\n");
    int num = 100;
    int *p1 = &num;
    int **p2 = &p1;
    
    printf("   原始值: num = %d\n", num);
    printf("   一级指针: *p1 = %d\n", *p1);
    printf("   二级指针: **p2 = %d\n\n", **p2);
    
    // 练习4: 函数参数传递（指针作参数）
    printf("4. 指针作函数参数 - 交换两个数:\n");
    
    void swap(int *a, int *b);
    int x = 10, y = 20;
    printf("   交换前: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("   交换后: x = %d, y = %d\n\n", x, y);
    
    // 练习5: 动态内存分配（malloc）
    printf("5. 动态内存分配:\n");
    
    int n = 5;
    int *dynamicArr = (int *)malloc(n * sizeof(int));
    
    if (dynamicArr == NULL) {
        printf("   内存分配失败！\n");
        return 1;
    }
    
    // 使用动态分配的内存
    for (int i = 0; i < n; i++) {
        dynamicArr[i] = (i + 1) * 10;
    }
    
    printf("   动态数组内容: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", dynamicArr[i]);
    }
    printf("\n");
    
    // 释放内存
    free(dynamicArr);
    printf("   内存已释放\n\n");
    
    // 练习6: const 指针
    printf("6. const 指针区别:\n");
    
    int a = 10, b = 20;
    const int *ptr1 = &a;  // 指向const的指针（可改指针，不可改值）
    int * const ptr2 = &b; // const指针（可改值，不可改指针）
    
    printf("   const int *ptr1: 可以改变ptr1指向的地址，但不能通过ptr1修改值\n");
    printf("   int * const ptr2: 可以通过ptr2修改值，但不能改变ptr2指向的地址\n\n");
    
    // 演示 const int *ptr1
    ptr1 = &b;  // 合法：可以改变ptr1指向
    printf("   ptr1 现在指向 b，*ptr1 = %d\n", *ptr1);
    // *ptr1 = 30;  // 编译错误：不能通过ptr1修改值
    
    // 演示 int * const ptr2
    *ptr2 = 30;  // 合法：可以修改值
    printf("   通过 ptr2 修改 b 的值，b 现在 = %d\n", b);
    // ptr2 = &a;  // 编译错误：不能改变ptr2指向
    
    return 0;
}

// 交换函数定义
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
