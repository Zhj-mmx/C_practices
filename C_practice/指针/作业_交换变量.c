//定义两个整型变量a=55, b=88，写void swap(int *x, int *y)函数，用指针交换两个变量的值。

#include <stdio.h>

void swap(int *x, int *y) {
    if (x == NULL || y == NULL) {
        return;
    }
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 55;
    int b = 88;

    int *x = &a;
    int *y = &b;

    printf("交换前: a = %d, b = %d\n", a, b);

    swap(x,y);

    printf("交换后: a = %d, b = %d\n", a, b);

    return 0;
}