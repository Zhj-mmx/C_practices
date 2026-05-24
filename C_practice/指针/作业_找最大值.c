//写一个函数int getMax(int *arr, int n)，用指针方式找出数组最大值，主函数调用测试。

#include <stdio.h>

int getMax(int *arr, int n) {
    if (n <= 0 || arr == NULL) {
        return -1;
    }
    int max = *arr;
    for (int i = 0; i < n; i++) {
        if (max < *(arr + i)) {
            max = *(arr + i);
        }
    }
    return max;
}

int main() {
    int arr[5] = {3, 1, 4, 1, 5};
    int max = getMax(arr, 5);
    
    // 检查返回值是否有效
    if (max != -1) {
        printf("最大值为%d\n", max);
    }
    return 0;
}