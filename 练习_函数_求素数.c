/*编写一个函数int isPrime(int n)，判断n是否为素数。若是素数返回1，否则返回0。在main函数中输入一个正整数，调用该函数并输出判断结果。*/
#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    if (n <= 1) {
        return 0; // 1和负数不是素数
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0; // n能被i整除，说明n不是素数
        }
    }   
    return 1; // n是素数
}