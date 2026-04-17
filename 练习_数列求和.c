/*输入一个正整数 n，计算1 - 2 + 3 - 4 + ... ± n的结果并输出。

要求：

使用循环实现

不允许直接套公式

注意当 n 为奇数和偶数时最后一项符号不同

示例输入：5

示例输出：3
*/

#include <stdio.h>

int main() {
    int n;
    int sum = 0;
    int a = 1;

    scanf("%d", &n)

        for (int i = 1; i <= n; i++) {
            sum += i * a;
            a = -a
        }
    printf("%d", sum)

        return 0
}