/*输入若干个整数，以 -1 作为结束标志，统计其中正数、负数（不含 -1 本身）和 0 的个数。

示例输入：

3 -2 0 5 0 -8 -1
示例输出：

positive = 2
negative = 2
zero = 2
要求：

必须使用循环读入

使用“哨兵值”结束输入

注意 -1 只表示结束，不参与统计*/

#include <stdio.h>
int main() {
    int num;
    int positive = 0, negative = 0, zero = 0;
    printf("请输入整数，以 -1 结束：");
    while (1) {
        scanf("%d", &num);
        if (num == -1) {
            break; // 遇到 -1 结束输入
        }
        if (num > 0) {
            positive++;
        }
        else if (num < 0) {
            negative++;
        }
        else {
            zero++;
        }
    }
}