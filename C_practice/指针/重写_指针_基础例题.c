//例一
#include <stdio.h>

int main() {
    int money = 100;

    int *p = &money;

    printf("=== 指针初体验 ===\n");
    printf("当前余额: %d 元\n", *p);

    *p = *p + 50;

    printf("加钱后余额: %d 元\n", money);

    return 0
}

//例题2：指针的算术运算（遍历数组）

#include <stdio.h>

int main() {
    int scores[5] = {85, 92, 78, 90, 88};
    int *ptr = scores;

    printf("=== 用指针遍历分数 ===\n");
    printf("方法1 - 移动纸条：");
    for (int i = 0; i < 5; i++) {
        printf("%d", *ptr);
        ptr++;
    }
    printf("\n");

    prt = scores;

    printf("方法2 - 纸条+偏移量：");
    for (int i = 0; i < 5; i++) {
        printf("%d", *(ptr + i));
    }
    printf("\n");

    printf("方法3 - 指针当数组名：");
    for (int i = 0; i < 5; i++) {
        printf("%d", ptr[i]);
    }
    printf("\n");
    
    return 0;
}

//例题3：指针与数组名的区别

#include <stdio.h>

int main() {
    int arr[3] = {10, 20, 30};
    int *p = arr;

    printf("arr 的地址: %p\n", arr);
    printf("p 的值:    %p\n\n", p);

    p = arr + 1;
    printf("移动后 p 的值: %p\n", p);
    printf("现在 *p = %d\n", *p); 

    int x = 100;
    p = &x;  // 便利贴改贴到 x 的柜子上
    printf("改贴后 *p = %d\n", *p);  // 输出 100
    
    return 0;
}

//例题4：指针作为函数参数（值传递 vs 地址传递）

#include <stdio.h>

void doubleValue_wrong(int *p) {
    *p = *p * 2;
    printf("(函数内复印件) *p = %d\n", *p);
}


int main() {
    int score = 60;
    
    printf("=== 值传递 vs 地址传递 ===\n");
    printf("原始分数: %d\n\n", score);
    
    // 尝试1：值传递（无法修改）
    doubleValue_wrong(score);
    printf("调用了 doubleValue_wrong 后，score = %d (没变!)\n\n", score);
    
    // 尝试2：地址传递（成功修改）
    doubleValue_right(&score);  // 把 score 的地址（作业本）交给函数
    printf("调用了 doubleValue_right 后，score = %d (被改了!)\n", score);
    
    return 0;
}

// 例题5：指针与字符串（字符数组）

include <stdio.h>

int main() {
    char name[] = "Hello";
    char *ptr = name;

    printf("=== 用指针遍历字符串 ===\n");
    printf("字符串内容：");

    while (*ptr != '\0') {
        printf("%c", *ptr);
        ptr++;
    }
}

//例题6：指针与动态内存分配（malloc）

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("请输入学生人数: ");
    scanf("%d", &n);

    int *scores = (int *)malloc(n * sizeof(int));

    if (scores == NULL) {
        printf("内存分配失败\n")
        return 1;
    }

    printf("请输入 %d 个学生的分数：\n", n);
    for (int i = 0; i < n; i++) {
        sum += scores[i];
    }
    double average = (double)sum / n;
    printf("平均分: %.2f\n", average);

    free(scores);
    scores = NULL;

    return 0;
}

//