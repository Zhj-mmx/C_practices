//编写函数 void reverse(char *s)，使用双指针法将字符串原地反转。例如 "Hello" → "olleH"。

#include <stdio.h>
#include <string.h>

void reverse(char *s) {
    if (s == NULL) {
        return;
    }
    int length = strlen(s);
    if (length <= 1) {
        return;
    }
    char *left = s;
    char *right = s + length - 1;
    while (left < right) {
        char temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}   
    

int main() {
    char s[] = "Hello";
    reverse(s);     //传入指针
    printf("反转后的字符串: %s\n", s);
    return 0;

}


//参考答案
 #include <stdio.h>
#include <string.h>

// 使用双指针法原地反转字符串
avoid reverse(char *s) {
    if (s == NULL) {  // 处理空指针情况
        return;
    }
    int length = strlen(s);
    if (length <= 1) {  // 长度为0或1时无需反转
        return;
    }
    char *left = s;          // 左指针指向字符串起始
    char *right = s + length - 1;  // 右指针指向字符串末尾
    while (left < right) {   // 双指针交换字符
        char temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

int main() {
    char s[] = "Hello";  // 使用字符数组存储可修改的字符串
    reverse(s);           // 传入数组名（指针）
    printf("反转后的字符串: %s\n", s);  // 输出结果验证
    return 0;
}