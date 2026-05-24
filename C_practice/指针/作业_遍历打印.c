//用指针遍历，打印数组所有元素。
//任务要求
//定义整型数组int arr[5] = {10,20,30,40,50}，不用下标，只用指针遍历，打印数组所有元素。

#include <stdio.h>

int main() {
    int arr[5] = {10,20,30,40,50};
    int *p = arr;

    for (int i = 0; i < 5; i++) {
        printf("%d", *p);
        p++;
    }
    return 0
}