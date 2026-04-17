#include <stdio.h>

int main() {
    int score;

    printf("=== 成绩判断程序 ===\n");
    printf("请输入你的分数 (0-100): ");
    scanf("%d", &score);

    if (score >= 90) {
        printf("优秀A\n");
    }
    else if (score >= 80) {
        printf("良好B\n");
    }
    else if (score >= 70) {
        printf("中等C\n");
    }
    else if (score >= 60) {
        printf("及格D\n");
    }
    else {
        printf("不及格E\n");
    }

    int num;
    printf("\n=== 奇偶数判断 ===\n");
    printf("请输入一个整数: ");
    scanf("%d", &num);

    if (num % 2 == 0) {
        printf("%d是偶数\n", num);
    }
    else {
        printf("%d是奇数\n", num);
    }

    int x, y, z max;
    printf("\n=== 找最大值 ===\n");
    printf("请输入三个整数: ");
    scanf("%d %d %d", &x, &y, &z);

    max = x;
    if (y > max) max = y;
    if (z > max) max = z;

    printf("最大的数是: %d\n", max);

    return 0;

}