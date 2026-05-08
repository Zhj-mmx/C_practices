/**
 * 练习7：字符串和字符数组
 * 练习字符串的基本操作
 * 
 * 字符串就是一堆字符排成的队，最后用一个特殊字符 '\0'（空字符）标记结尾。
 * 比如 "Hello" 在内存中是 'H','e','l','l','o','\0'
 */

#include <stdio.h>    // 输入输出库
#include <string.h>   // 字符串库，里面有很多现成的字符串函数，比如 strlen, strcat 等

// ----- 自定义函数声明（告诉编译器我们有这些函数）-----
void printString(char str[]);          // 打印字符串
int stringLength(char str[]);          // 手动计算字符串长度（不用 strlen）
void reverseString(char str[]);        // 把字符串反转，比如 "hello" 变成 "olleh"
void uppercaseString(char str[]);      // 把小写字母全部变成大写

// ----- 主函数 -----
int main() {
    printf("=== 字符串基础练习 ===\n\n");
    
    // ---------- 练习1: 字符串的声明和初始化（三种常见写法）----------
    printf("1. 字符串声明和初始化:\n");
    // 写法1：自动计算大小，后面自动加上 '\0'
    char str1[] = "Hello, World!";   
    // 写法2：指定数组大小 50，可以放最多 49 个有效字符 + 结尾 '\0'
    char str2[50] = "C Programming";
    // 写法3：一个一个字符写出来，记得最后加上 '\0'，否则不是字符串（会乱套）
    char str3[20] = {'H', 'e', 'l', 'l', 'o', '\0'};
    
    // %s 是输出字符串的格式
    printf("   str1: %s\n", str1);
    printf("   str2: %s\n", str2);
    printf("   str3: %s\n\n", str3);
    
    // ---------- 练习2: 使用 strlen() 计算字符串长度（不包括结尾的 '\0'）----------
    printf("2. 字符串长度:\n");
    // strlen 是系统自带的函数，返回类型是 size_t，我们用 %lu 输出
    printf("   '%s' 的长度: %lu\n", str1, strlen(str1));
    printf("   '%s' 的长度: %lu\n", str2, strlen(str2));
    printf("   '%s' 的长度: %lu\n\n", str3, strlen(str3));
    
    // ---------- 练习3: 字符串拼接（把 src 接到 dest 后面）----------
    printf("3. 字符串拼接 (strcat):\n");
    char dest[100] = "Hello, ";        // 目的地要足够大，能放下拼接后的结果
    char src[] = "C Language!";
    printf("   拼接前: dest = '%s', src = '%s'\n", dest, src);
    strcat(dest, src);                 // 把 src 的内容追加到 dest 后面
    printf("   拼接后: dest = '%s'\n\n", dest);
    
    // ---------- 练习4: 字符串复制（把 source 的内容拷贝到 destination）----------
    printf("4. 字符串复制 (strcpy):\n");
    char source[] = "Original String";
    char destination[50];              // 刚开始里面可能是什么垃圾数据
    printf("   复制前: source = '%s', destination = '%s'\n", source, destination);
    strcpy(destination, source);       // source 的内容覆盖 destination
    printf("   复制后: source = '%s', destination = '%s'\n\n", source, destination);
    
    // ---------- 练习5: 字符串比较（比较两个字符串是否相同）----------
    printf("5. 字符串比较 (strcmp):\n");
    char s1[] = "apple";
    char s2[] = "banana";
    char s3[] = "apple";
    
    // strcmp 返回 0 表示相等，负数表示 s1 < s2，正数表示 s1 > s2
    printf("   strcmp(\"%s\", \"%s\") = %d\n", s1, s2, strcmp(s1, s2));
    printf("   strcmp(\"%s\", \"%s\") = %d\n", s1, s3, strcmp(s1, s3));
    printf("   (返回0表示相等，负数表示第一个小于第二个，正数表示第一个大于第二个)\n\n");
    
    // ---------- 练习6: 自定义函数演示 ----------
    printf("6. 自定义字符串函数:\n");
    char test[] = "Hello";
    printf("   原字符串: '%s'\n", test);
    printf("   长度 (自定义): %d\n", stringLength(test));   // 调用我们自己写的长度函数
    
    // 演示大写转换
    char lower[] = "hello world";
    printf("   转换前: '%s'\n", lower);
    uppercaseString(lower);            // 全部转成大写
    printf("   转换后: '%s'\n\n", lower);
    
    // ---------- 练习7: 综合练习 - 回文字符串检查 ----------
    // 回文：正着读和倒着读都一样，比如 "level"、"madam"
    printf("7. 综合练习 - 回文检查:\n");
    
    // 测试用例1: "level"
    char test1[] = "level";
    // 测试用例2: "hello"
    char test2[] = "hello";
    // 测试用例3: "madam"
    char test3[] = "madam";
    
    // 检查 test1
    printf("   '%s' 是回文? ", test1);
    int isPalindrome1 = 1;            // 先假设它是回文（1 表示真）
    int len1 = strlen(test1);         // 获取长度
    // 只需要比较前半部分和后半部分对应的字符
    for (int i = 0; i < len1 / 2; i++) {
        // 如果对称位置上的字符不一样，就不是回文
        if (test1[i] != test1[len1 - 1 - i]) {
            isPalindrome1 = 0;        // 0 表示假
            break;                    // 不用继续比了
        }
    }
    // 条件运算符 ? :  : 如果 isPalindrome1 真就输出"是"，否则"不是"
    printf("%s\n", isPalindrome1 ? "是" : "不是");
    
    // 检查 test2（同样的逻辑）
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
    
    // 你可以自己尝试检查 test3，或者改成用函数实现
    
    return 0;   // 程序正常结束
}

// ----- 自定义函数的实现（具体代码）-----

// 打印字符串：直接使用 printf 输出
void printString(char str[]) {
    // %s 会自动输出字符串，直到遇到 '\0'
    printf("   %s\n", str);
}

// 手动计算字符串长度
// 思路：从第一个字符开始数，一直数到 '\0' 为止（不包括 '\0'）
int stringLength(char str[]) {
    int length = 0;
    // 只要当前字符不是结束符 '\0'，就长度加1，并移到下一个字符
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// 把字符串反转
// 比如传入 "hello"，函数执行后变成 "olleh"
void reverseString(char str[]) {
    int len = strlen(str);               // 先获取长度
    // 只需要交换前半部分和后半部分对应的字符
    // 比如长度是5，i=0 交换下标0和4，i=1 交换下标1和3，i=2 时中间的不需要交换
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];              // 临时保存前面的字符
        str[i] = str[len - 1 - i];       // 后面的字符放到前面
        str[len - 1 - i] = temp;        // 前面的字符放到后面
    }
}

// 将字符串中的所有小写字母转换成大写
// 原理：小写字母 'a' 到 'z' 的 ASCII 码是 97-122，大写 'A' 到 'Z' 是 65-90
// 小写比大写大32，所以小写 - 32 就是大写
void uppercaseString(char str[]) {
    // 遍历字符串中的每一个字符，直到遇到结尾 '\0'
    for (int i = 0; str[i] != '\0'; i++) {
        // 如果当前字符是小写字母
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;        // 转换成大写
        }
    }
}