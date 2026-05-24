/*输入一个正整数 n，输出如下图形（以 n=5 为例）：

*
**
***
****
*****
要求：

使用嵌套循环实现

外层循环控制行数，内层循环控制每行输出的*个数

不允许直接写多条 printf 语句 */

#include <studio.h>
int main() {
    int n;
    printf("请输入一个正整数 n：");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}