好的，我们继续深入 C 语言字符串的练习！下面再提供 **5 道进阶题目**，涵盖更实用的字符串处理场景：字符串转整数、查找子串、删除字符、字符频率统计、以及字符串数组排序。每道题依然包含题目描述、完整代码和初中生级详细解析。

---

# C语言 字符串 进阶练习（第二弹）

> 🧠 这些题目会让你把之前学到的“四大金刚”和指针、循环真正融会贯通。

---

### 进阶题 6：自己实现 `atoi`（字符串转整数）

**题目描述：**  
C 标准库有 `atoi` 函数可以把字符串 `"123"` 变成整数 `123`。请你动手实现一个 `myAtoi(char str[])`，规则如下：
- 忽略字符串开头的空格；
- 如果第一个非空格字符是 `'+'` 或 `'-'`，则作为符号处理；
- 之后连续的数字字符转换为整数，遇到非数字字符停止；
- 如果没有任何数字，返回 0。
**示例输入：** `"   -42abc"` → 输出 `-42`

<details>
<summary><b>✅ 点击查看答案与解析</b></summary>

```c
#include <stdio.h>
#include <ctype.h>  // isspace, isdigit

int myAtoi(char str[]) {
    int i = 0;
    int sign = 1;
    int result = 0;

    // 1. 跳过前导空格
    while (isspace(str[i])) {
        i++;
    }

    // 2. 看符号
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    // 3. 逐位转换数字
    while (isdigit(str[i])) {
        // 把上次的结果左移一位（乘以10），加上当前数字
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return sign * result;
}

int main() {
    char test1[] = "   -42abc";
    char test2[] = "4193 with words";
    char test3[] = "words and 987";
    printf("\"%s\" -> %d\n", test1, myAtoi(test1));
    printf("\"%s\" -> %d\n", test2, myAtoi(test2));
    printf("\"%s\" -> %d\n", test3, myAtoi(test3));
    return 0;
}
```

**解析：**
- `isspace()` 判断是否空格（包括空格、制表符等）。
- `isdigit()` 判断是不是数字字符。
- `str[i] - '0'` 是将字符数字变成真正数字值的经典魔法（因为 `'0'` 的 ASCII 码是 48，`'1'` 是 49，相减正好是 1）。
</details>

---

### 进阶题 7：在字符串中查找子串（自己实现 `strstr`）

**题目描述：**  
标准库有 `strstr(haystack, needle)`，能在干草堆里找针。请实现一个 `myStrstr(char haystack[], char needle[])`，返回 `needle` 在 `haystack` 中第一次出现的首字符地址，如果没找到返回 `NULL`。
**示例输入：** 查找 `"ana"` 在 `"banana"` 中 → 应返回指向第一个 `'a'` 的指针（索引 1 处）。

<details>
<summary><b>✅ 点击查看答案与解析</b></summary>

```c
#include <stdio.h>
#include <string.h>

char* myStrstr(char haystack[], char needle[]) {
    int hayLen = strlen(haystack);
    int neeLen = strlen(needle);

    if (neeLen == 0) return haystack;  // 空针在任何位置都找到

    for (int i = 0; i <= hayLen - neeLen; i++) {
        int j;
        for (j = 0; j < neeLen; j++) {
            if (haystack[i + j] != needle[j]) {
                break;  // 有一个字符对不上就跳出
            }
        }
        if (j == neeLen) {  // 完全匹配
            return &haystack[i];
        }
    }
    return NULL;
}

int main() {
    char text[] = "banana";
    char pattern[] = "ana";
    char* pos = myStrstr(text, pattern);
    if (pos) {
        printf("找到子串，从 \"%s\" 开始\n", pos);
    } else {
        printf("未找到\n");
    }
    return 0;
}
```

**解析：**
- 外层循环 `i` 是每次尝试匹配的起始位置。
- 内层循环逐字符比较，如果全部匹配，返回当前位置的指针。
- `i <= hayLen - neeLen` 是防止越界，因为剩下的字符已经不够长了。
</details>

---

### 进阶题 8：删除字符串中的所有指定字符

**题目描述：**  
写一个函数 `removeChar(char str[], char ch)`，将字符串 `str` 中所有出现的字符 `ch` 删除（原地修改），后面的字符依次前移，最后补 `'\0'`。
**示例输入：** 删除 `"Hello world"` 中的 `'l'` → 得到 `"Heo word"`

<details>
<summary><b>✅ 点击查看答案与解析</b></summary>

```c
#include <stdio.h>

void removeChar(char str[], char ch) {
    int writePos = 0;  // 写指针，指向下一个干净位置

    for (int readPos = 0; str[readPos] != '\0'; readPos++) {
        if (str[readPos] != ch) {
            str[writePos] = str[readPos];  // 不是要删的，就抄到前面去
            writePos++;
        }
        // 如果是 ch，什么都不做，跳过去
    }
    str[writePos] = '\0';  // 新哨兵
}

int main() {
    char s[] = "Hello world";
    removeChar(s, 'l');
    printf("删除后: \"%s\"\n", s);  // "Heo word"
    return 0;
}
```

**解析：**
- 用两个下标：`readPos` 从头扫到尾，`writePos` 指向当前可以覆盖的位置。
- 遇到不需要删的字符，就把它搬到 `writePos` 处，然后 `writePos` 前进一步。要删的字符直接忽略，就被“挤掉”了。
- 最后别忘了设置新哨兵。
</details>

---

### 进阶题 9：统计字符串中各字符的出现次数（频率）

**题目描述：**  
输入一个字符串，统计里面每个字母（不区分大小写）出现的次数，并按字母顺序打印出来。只统计英文字母，忽略其他字符。
**示例输入：** `"Hello, World!"`  
**输出：**
```
d: 1
e: 1
h: 1
l: 3
o: 2
r: 1
w: 1
```

<details>
<summary><b>✅ 点击查看答案与解析</b></summary>

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

int main() {
    char str[] = "Hello, World!";
    int freq[ALPHABET_SIZE] = {0};  // 26个位置，都初始化为0

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (isalpha(ch)) {
            freq[ch - 'a']++;  // 对应字母的计数加一
        }
    }

    printf("字符频率统计（小写）：\n");
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (freq[i] > 0) {
            printf("%c: %d\n", 'a' + i, freq[i]);
        }
    }
    return 0;
}
```

**解析：**
- 用一个大小为 26 的数组 `freq`，下标 0 对应 `'a'`，1 对应 `'b'`...
- `ch - 'a'` 将字母映射到 0-25 的索引。
- 最后只打印出现次数 >0 的字母。
</details>

---

### 进阶题 10：对字符串数组进行字典序排序

**题目描述：**  
假设你有一个字符串数组（例如几个同学的名字），请写程序用**冒泡排序**将它们按字典序从小到大排列。名字不超过 20 个字符，数组长度固定为 5。  
**示例输入：** `{"Alice", "Charlie", "Bob", "David", "Eve"}`  
**预期输出：** `Alice Bob Charlie David Eve`

<details>
<summary><b>✅ 点击查看答案与解析</b></summary>

```c
#include <stdio.h>
#include <string.h>

#define N 5
#define MAX_LEN 20

int main() {
    char names[N][MAX_LEN] = {"Alice", "Charlie", "Bob", "David", "Eve"};
    char temp[MAX_LEN];

    // 冒泡排序
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                // 交换两个字符串
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("排序后：");
    for (int i = 0; i < N; i++) {
        printf("%s ", names[i]);
    }
    printf("\n");
    return 0;
}
```

**解析：**
- 字符串不能直接赋值，交换必须用 `strcpy`。
- `strcmp` 返回正数表示前一个大，所以 `> 0` 时交换，实现升序。
- 这其实就是把整数排序的模板照搬，只不过比较和交换换成了字符串专用函数。
</details>

---

### ✨ 现在你已经是 C 语言字符串小能手了！

完成这 10 道题，你已经覆盖了：
- 字符串基本输入输出
- `strlen`/`sizeof` 区别
- 复制、连接、比较
- 指针遍历
- 手动实现 `atoi`、`strstr`、`remove`
- 字符频率统计
- 字符串数组排序

把这些题目的代码自己敲一遍，修改参数跑一跑，你就能应付绝大多数 C 语言字符串相关的面试题和作业了。如果还想继续，可以试试**命令行参数（argc, argv）**和**文件读写中的字符串处理**，那些都是真实项目中用得最多的东西！