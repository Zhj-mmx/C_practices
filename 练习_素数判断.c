/*输入一个正整数 n，判断它是否为素数。

要求：

若是素数输出 Yes，否则输出 No

不允许从 1 一直试到 n

思考循环应该到哪里停止更合理

示例输入：29

示例输出：Yes*/

#include <stdio.h>
#include <math.h>

int main() {
    int n;

    scanf("%d", n);

    if (n <= 0) {
        printf("False");
    }

    for (int i = 1; i <= sqrt(n); i++) {
        if i* (n / i) = n{
            printf("%d不是素数", n);
            break
        }
        else {
            continue
        }
        printf("%d是素数", n);

        return 0;
    }
}

//上面代码问题有点多hhh，下面是正确代码示范

#include <stdio.h>
#include <math.h>

// 判断一个正整数是否为素数
int isPrime(int n) {
    // 处理小于2的数
    if (n <= 1) {
        return 0;
    }
    // 处理最小素数2
    if (n == 2) {
        return 1;
    }
    // 处理偶数
    if (n % 2 == 0) {
        return 0;
    }
    // 只需要检查到sqrt(n)，且只检查奇数
    int sqrtN = sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    // 安全输入并检查有效性
    printf("请输入一个正整数: ");
    if (scanf("%d", &n) != 1) {
        printf("输入错误，请输入一个有效的正整数\n");
        return 1;
    }

    // 判断并输出结果
    if (isPrime(n)) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }

    return 0;
}