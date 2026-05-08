/*编写一个函数int sum(int n)，计算1+2+3+…+n的值，并在main函数中调用该函数，输入n，输出求和结果。*/
#include <stdio.h>

int sum(int n) {
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result += i;
    }
    return result;
}

int main() {
    int n;
    printf("请输入一个正整数n: ");
    scanf("%d", &n);
    printf("1+2+3+...+%d = %d\n", n, sum(n));
    return 0;
}

/*递归写法*/
#include <stdio.h>

int sum(int n) {
    if (n == 1) {
        return 1;
    }
    return n + sum(n - 1);
}