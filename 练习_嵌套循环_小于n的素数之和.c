/*输入一个正整数 n，求不大于 n 的所有素数之和。*/

#include <stdio.h>
#include <math.h>

int is_prime(int num) {
    if (num <= 1) {
        return 0; // 0 和 1 不是素数
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0; // num 能被 i 整除，说明 num 不是素数
        }
    }
    return 1; // num 是素数
}

int main() {
    int n;
    printf("请输入一个正整数 n: ");
    scanf("%d", &n);

    int sum = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            sum += i; // 如果 i 是素数，则将其加到 sum 中
        }
    }

    printf("不大于 %d 的所有素数之和是: %d\n", n, sum);
    return 0;
}