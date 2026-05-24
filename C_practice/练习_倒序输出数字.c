/*输入一个正整数 n，输出它的每一位数字，要求从低位到高位输出，每个数字占一行。

示例输入：3527

示例输出：

7

2

5

3

要求：

使用循环实现

不允许把整数转成字符串处理

思考当输入为 0 时应如何处理*/

#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    if (n == 0) {
        printf("%d\n", n)
    }

    if (n < 0) {
        n = -n
    }

    while (n >= 1) {
        int a = n % 10;
        n /= 10;
        printf("%d\n", a);
    }

    return 0;
}