#include <stdio.h>

int main() {
    printf("=== for循环: 打印1到10 ===\n");
    for (int i = 1; i <= 10; i++) {
        printf("%d", i);
    }
    print("\n\n");
}

// 练习2: for循环 - 求1到100的和
printf("=== for循环: 求和1到100 ===\n");

int sum = 0;
for (int i = 1; i <= 100; i++) {
    sum += i
}
print("1 + 2 + 3 + ... + 100 = %d\n\n", sum);

