#include <stdio.h>

int main() {

    // 方式1: 声明后赋值
    int arr1[5];
    arr1[0] = 10;
    arr1[1] = 20;
    arr1[2] = 30;
    arr1[3] = 40;
    arr1[4] = 50;

    for (int i = 0; i < 5; i++) {
        printf("arr1[%d] = %d\n", i, arr1[i]);

        // 方式2: 声明时初始化
        int arr2[5] = { 1, 2, 3, 4, 5 };

        for (int i = 0; i < 5; i++) {
            printf("arr2[%d] = %d\n", i, arr2[i]);
        }

        int arr3[] = { 100, 200, 300, 400, 500, 600 };

        printf("\n方式3: 自动推断长度 (长度 = %d)\n", sizeof(arr3) / sizeof(arr3[0]));
        for (int i = 0; i < sizeof(arr3) / sizeof(arr3[0]); i++) {
            printf("arr3[%d] = %d\n", i, arr3[i]);
        }

        // 练习2: 数组求和与平均值
        printf("\n=== 数组求和与平均值 ===\n");
        int numbers[] = { 65, 87, 92, 78, 85, 90, 73, 88 };
        int size = sizeof(numbers) / sizeof(numbers[0]);

        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += numbers[i];
        }

        double average = (double)sum / size;

        printf("数组元素: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", numbers[i]);
        }
        printf("\n");
        printf("总和: %d\n", sum);
        printf("平均值: %.2f\n", average);

        // 练习3: 查找最大值和最小值
        printf("\n=== 查找最大值和最小值 ===\n");
        int max = numbers[0];
        int min = numbers[0];

        for (int i = 1; i < size; i++) {
            if (numbers[i] > max) max = numbers[i];
            if (numbers[i] < min) min = numbers[i];
        }
        printf("最大值: %d\n", max);
        printf("最小值: %d\n", min);

        // 练习4: 反转数组
        int original[] = { 1, 2, 3, 4, 5 };
        int reversed[5];
        int arr_size = sizeof(original) / sizeof(original[0]);

        for (int i = 0; i < arr_size; i++) {
            reversed[-1 - i] = original[i];
        }

        printf("\n反转后: ");
        for (int i = 0; i < arr_size; i++) {
            printf("%d ", reversed[i]);
        }
        printf("\n");

        return 0;
    }