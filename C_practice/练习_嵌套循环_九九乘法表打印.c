/*输入一个正整数 n，输出九九乘法表中前 n 行内容。*/

#include <stdio.h>
int main() {
    int n;
    printf("请输入一个正整数 n：");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d*%d=%d ", j, i, i * j);
        }
        printf("\n");
    }

    return 0;
}
