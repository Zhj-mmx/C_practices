/**
 * 练习7：字符串和字符数组
 * 练习字符串的基本操作
 */

#include <stdio.h>
#include <string.h>

// 自定义函数
void printString(char str[]);
int stringLength(char str[]);
void reverseString(char str[]);
void uppercaseString(char str[]);

int main() {
    printf("=== 字符串基础练习 ===\n\n");
    
    // 练习1: 字符串的声明和初始化
    printf("1. 字符串声明和初始化:\n");
    char str1[] = "Hello, World!";
    char str2[50] = "C Programming";
    char str3[20] = {'H', 'e', 'l', 'l', 'o', '\0'};
    
    printf("   str1: %s\n", str1);
    printf("   str2: %s\n", str2);
    printf("   str3: %s\n\n", str3);
    
    // 练习2: 使用 strlen() 计算字符串长度
    printf("2. 字符串长度:\n");
    printf("   '%s' 的长度: %lu\n", str1, strlen(str1));
    printf("   '%s' 的长度: %lu\n", str2, strlen(str2));
    printf("   '%s' 的长度: %lu\n\n", str3, strlen(str3));
    
    // 练习3: 字符串拼接
    printf("3. 字符串拼接 (strcat):\n");
    char dest[100] = "Hello, ";
    char src[] = "C Language!";
    printf("   拼接前: dest = '%s', src = '%s'\n", dest, src);
    strcat(dest, src);
    printf("   拼接后: dest = '%s'\n\n", dest);
    
    // 练习4: 字符串复制
    printf("4. 字符串复制 (strcpy):\n");
    char source[] = "Original String";
    char destination[50];
    printf("   复制前: source = '%s', destination = '%s'\n", source, destination);
    strcpy(destination, source);
    printf("   复制后: source = '%s', destination = '%s'\n\n", source, destination);
    
    // 练习5: 字符串比较
    printf("5. 字符串比较 (strcmp):\n");
    char s1[] = "apple";
    char s2[] = "banana";
    char s3[] = "apple";
    
    printf("   strcmp(\"%s\", \"%s\") = %d\n", s1, s2, strcmp(s1, s2));
    printf("   strcmp(\"%s\", \"%s\") = %d\n", s1, s3, strcmp(s1, s3));
    printf("   (返回0表示相等，负数表示第一个小于第二个，正数表示第一个大于第二个)\n\n");
    
    // 练习6: 自定义函数演示
    printf("6. 自定义字符串函数:\n");
    char test[] = "Hello";
    printf("   原字符串: '%s'\n", test);
    printf("   长度 (自定义): %d\n", stringLength(test));
    
    // 演示大写转换
    char lower[] = "hello world";
    printf("   转换前: '%s'\n", lower);
    uppercaseString(lower);
    printf("   转换后: '%s'\n\n", lower);
    
    // 练习7: 综合练习 - 回文字符串检查
    printf("7. 综合练习 - 回文检查:\n");
    
    // 测试用例
    char test1[] = "level";
    char test2[] = "hello";
    char test3[] = "madam";
    
    printf("   '%s' 是回文? ", test1);
    // 临时实现回文检查逻辑
    int isPalindrome1 = 1;
    int len1 = strlen(test1);
    for (int i = 0; i < len1 / 2; i++) {
        if (test1[i] != test1[len1 - 1 - i]) {
            isPalindrome1 = 0;
            break;
        }
    }
    printf("%s\n", isPalindrome1 ? "是" : "不是");
    
    printf("   '%s' 是回文? ", test2);
    int isPalindrome2 = 1;
    int len2 = strlen(test2);
    for (int i = 0; i < len2 / 2; i++) {
        if (test2[i] != test2[len2 - 1 - i]) {
            isPalindrome2 = 0;
            break;
        }
    }
    printf("%s\n", isPalindrome2 ? "是" : "不是");
    
    return 0;
}

// 自定义函数实现
void printString(char str[]) {
    printf("   %s\n", str);
}

int stringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void reverseString(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void uppercaseString(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;  // 转换为大写
        }
    }
}
