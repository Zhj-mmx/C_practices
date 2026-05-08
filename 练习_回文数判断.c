/*输入一个正整数 n，判断它是否是“回文数”。
例如：121、1331 是回文数，123 不是回文数。

要求：

不允许把整数转成字符串处理

使用循环构造它的逆序数

输出Yes或No

示例输入：*/

#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);
    int original = n; // 保存原始数值
    int reversed = 0; // 用于存储逆序数

    while (n > 0) {
        int digit = n % 10; // 获取最后一位数字
        reversed = reversed * 10 + digit; // 构造逆序数
        n /= 10; // 去掉最后一位数字
    }

    if (original == reversed) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }

    return 0;

}