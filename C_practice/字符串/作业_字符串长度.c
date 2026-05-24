//编写函数 int my_strlen(const char *s)，
//不调用任何标准库函数，使用指针方式实现计算字符串长度的功能。在主函数中测试。

#include <stdio.h>

int my_strlen(const char *s) {
    if (s == NULL) {
        return 0;
    }
    int i = 0;
    while (*s != '\0') {
        i++;
        s++;
    }
    return i;
}

int main() {
    char str[] = "HelloWorld";
    const char *s = str;

    int len = my_strlen(s);

    printf("%d", len);

    return 0;

}