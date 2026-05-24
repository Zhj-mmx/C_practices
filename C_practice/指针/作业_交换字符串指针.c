//定义两个字符指针char *s1 = "Apple", *s2 = "Banana"；
//写void swapStr(char **p1, char **p2)，用二级指针交换两个字符串指针的指向，
//最后打印两个字符串。

#include <stdio.h>

void swapStr(char **p1,char **p2) {
    if (p1 == NULL || p2 == NULL) {
        return;
    }
    char *temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
int main() {
    char *s1 = "Apple";
    char *s2 = "Banana";

    printf("交换前: s1 = %s, s2 = %s\n", s1, s2);
    swapStr(&s1,&s2);
    printf("交换后: s1 = %s, s2 = %s\n", s1, s2);

    return 0;

}


//参考答案
#include <stdio.h>

void swapStr(char **p1, char **p2) {
    // 检查指针有效性
    if (p1 == NULL || p2 == NULL) {
        return;
    }
    char *temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    char *s1 = "Apple";
    char *s2 = "Banana";

    printf("交换前: s1 = %s, s2 = %s\n", s1, s2);
    swapStr(&s1, &s2);
    printf("交换后: s1 = %s, s2 = %s\n", s1, s2);

    return 0;
}