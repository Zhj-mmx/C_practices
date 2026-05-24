/**
 * 练习4：循环结构（for, while, do-while）
 * 练习各种循环的使用
 */

#include <stdio.h>

int main() {
    // 练习1: for循环 - 打印1到10
    printf("=== for循环: 打印1到10 ===\n");
    for (int i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n\n");
    
    // 练习2: for循环 - 求1到100的和
    printf("=== for循环: 求和1到100 ===\n");
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i;
    }
    printf("1 + 2 + 3 + ... + 100 = %d\n\n", sum);
    
    // 练习3: while循环 - 逆序打印
    printf("=== while循环: 逆序打印10到1 ===\n");
    int j = 10;
    while (j >= 1) {
        printf("%d ", j);
        j--;
    }
    printf("\n\n");
    
    // 练习4: while循环 - 求阶乘
    printf("=== while循环: 求5的阶乘 ===\n");
    int n = 5;
    int factorial = 1;
    int k = 1;
    
    while (k <= n) {
        factorial *= k;
        k++;
    }
    printf("%d! = %d\n\n", n, factorial);
    
    // 练习5: do-while循环 - 至少执行一次
    printf("=== do-while循环: 输入验证 ===\n");
    int input;
    
    do {
        printf("请输入一个1-10之间的数字: ");
        scanf("%d", &input);
        if (input < 1 || input > 10) {
            printf("输入错误！请重新输入。\n\n");
        }
    } while (input < 1 || input > 10);
    
    printf("恭喜！你输入了: %d\n\n", input);
    
    // 练习6: 嵌套循环 - 打印乘法表
    printf("=== for循环嵌套: 九九乘法表 ===\n");
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d×%d=%-2d ", j, i, i * j);
        }
        printf("\n");
    }
    
    return 0;
}
