好的，我们继续！下面进入 **基础例题+代码示范** 环节。每个例子都配有完整的可运行代码和超详细注释，建议你打开你的 C 语言编译器，边看边敲。

---

# C语言 字符串 基础例题 + 代码示范（初中生详细注释版）

> 💡 **运行小贴士**：把所有 `#include` 放在文件最开头，然后一段一段复制代码运行观察输出。

---

### 示例 1：创建字符串并打印，看看它到底占多少位置

**场景：** 我们先声明一根竹签（字符数组），穿上几个山楂（字符），然后打印出来，并看看 `strlen` 和 `sizeof` 的区别。

```c
#include <stdio.h>
#include <string.h>  // strlen 需要这个头文件

int main() {
    // 方式一：让编译器自动数长度（推荐初学用）
    char fruit[] = "Apple";   // 实际存的是 'A','p','p','l','e','\0'，共6个

    // 方式二：指定竹签长度，但只用了前面几个位置
    char name[10] = "Tom";    // 10个格子，只用了前4个（T,o,m,\0），后面全是\0

    // 打印字符串：用 %s
    printf("fruit = %s\n", fruit);
    printf("name  = %s\n", name);

    // 长度测量
    printf("strlen(fruit) = %d\n", (int)strlen(fruit));  // 5 （只要山楂）
    printf("sizeof(fruit) = %d\n", (int)sizeof(fruit));  // 6 （整根竹签，含尖）
    printf("sizeof(name)  = %d\n", (int)sizeof(name));   // 10 （竹签总长）

    // 看看每个字符是啥（用循环）
    printf("fruit 每个字符的 ASCII 码：\n");
    for (int i = 0; i < sizeof(fruit); i++) {
        printf("  第%d个: '%c' (ASCII=%d)\n", i, fruit[i], fruit[i]);
    }
    // 最后一个一定是 '\0' ，ASCII 码为 0

    return 0;
}
```

**运行预期输出：**
```
fruit = Apple
name  = Tom
strlen(fruit) = 5
sizeof(fruit) = 6
sizeof(name)  = 10
fruit 每个字符的 ASCII 码：
  第0个: 'A' (ASCII=65)
  第1个: 'p' (ASCII=112)
  第2个: 'p' (ASCII=112)
  第3个: 'l' (ASCII=108)
  第4个: 'e' (ASCII=101)
  第5个: '' (ASCII=0)
```

---

### 示例 2：安全地输入带空格的字符串（fgets）

**场景：** 你写了一个程序要问用户“你叫什么名字？”，用户输入了“Taylor Swift”，如果用 `scanf`，只会读到“Taylor”，后面的“Swift”就丢了。我们用 `fgets` 来拯救它。

```c
#include <stdio.h>
#include <string.h>

int main() {
    char fullName[30];  // 申请一根能装29个有效字符的竹签

    printf("请输入你的全名（可以有空格）：");
    // fgets 会读一整行，包括空格，直到遇到换行或长度上限
    fgets(fullName, sizeof(fullName), stdin);

    // 注意：fgets 会把用户按下的回车键 '\n' 也读进去！
    // 如果我们不想要这个回车，可以找到它并把它换成 '\0'
    int len = strlen(fullName);
    if (len > 0 && fullName[len - 1] == '\n') {
        fullName[len - 1] = '\0';  // 把最后一个山楂（回车）抠掉，换成尖头
    }

    printf("你好，%s！\n", fullName);
    printf("你的名字长度（不含哨兵）：%d\n", (int)strlen(fullName));

    return 0;
}
```

**运行示例：**
```
请输入你的全名（可以有空格）：Taylor Swift
你好，Taylor Swift！
你的名字长度（不含哨兵）：12
```

---

### 示例 3：复制和粘贴字符串（strcpy / strncpy）

**场景：** 你想把一句话抄到另一张纸上。不能用 `=` 直接赋值，要用 `strcpy` 这只“笔”。

```c
#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "I love C!";  // 源字符串，带哨兵共11个位置
    char dest[20];             // 目标数组，要有足够空间

    // 复制：把 src 完完整整抄到 dest 里
    strcpy(dest, src);
    printf("复制后 dest = %s\n", dest);

    // 更安全的版本：strncpy，限制最多抄几个字符
    char dest2[5];  // 很小的竹签，只能装4个山楂
    strncpy(dest2, src, sizeof(dest2) - 1); // 最多抄4个字符
    dest2[sizeof(dest2) - 1] = '\0';        // 手动补上哨兵，确保安全
    printf("安全复制后 dest2 = %s\n", dest2); // 输出 "I lo"

    return 0;
}
```

**输出：**
```
复制后 dest = I love C!
安全复制后 dest2 = I lo
```

---

### 示例 4：连接两个字符串（strcat / strncat）

**场景：** 你有一张纸条写着“Hello”，你想在后面续写“ World”，但不能把纸写爆。

```c
#include <stdio.h>
#include <string.h>

int main() {
    char msg[30] = "Hello";   // 必须留够空间给后面要加的内容

    strcat(msg, " World");    // 在 msg 的哨兵位置开始写入第二个串
    printf("连接后：%s\n", msg); // Hello World

    // 安全版：限制追加的字符数
    char msg2[10] = "Hi";
    strncat(msg2, " there!", sizeof(msg2) - strlen(msg2) - 1); // 算好还剩多少空间
    printf("限制连接后：%s\n", msg2); // 可能是 "Hi there" 或截断

    return 0;
}
```

**输出：**
```
连接后：Hello World
限制连接后：Hi there
```

---

### 示例 5：比较两个字符串（strcmp）

**场景：** 用户登录时要输入密码，怎么判断他输的密码和预设的是否相同？不能用 `==`！

```c
#include <stdio.h>
#include <string.h>

int main() {
    char password[] = "abc123";
    char input[20];

    printf("请输入密码：");
    fgets(input, sizeof(input), stdin);
    // 去除换行符（和前面一样）
    input[strcspn(input, "\n")] = '\0';  // strcspn 快速找到换行位置，换成 '\0'

    // 比较：strcmp 返回 0 表示相等
    if (strcmp(input, password) == 0) {
        printf("密码正确，欢迎！\n");
    } else {
        printf("密码错误，请重试。\n");
    }

    return 0;
}
```

**讲解：** `strcspn(input, "\n")` 是找第一个换行符的位置，然后把它替换成 `'\0'`，这是一种常见去换行技巧。

---

### 示例 6：用指针遍历字符串

**场景：** 你不用知道数组的长度，只需要顺着指针一直走，直到碰到哨兵 `'\0'`。

```c
#include <stdio.h>

int main() {
    char str[] = "C is fun!";
    char *p = str;   // 指针 p 现在指向竹签的第一个山楂

    printf("逐个字符输出：");
    while (*p != '\0') {   // 不是哨兵就继续
        putchar(*p);       // 输出当前山楂
        p++;               // 竹签往前推一格
    }
    printf("\n");

    // 还可以用这种简洁写法
    for (char *q = str; *q != '\0'; q++) {
        putchar(*q);
    }
    printf("\n");

    return 0;
}
```

**输出：**
```
逐个字符输出：C is fun!
C is fun!
```

---

> 上面这 6 个例子涵盖了 C 语言字符串日常操作的 80%。自己敲一遍，改改里面的字符串，看看结果，很快就能熟练。接下来，准备迎接几个**进阶挑战题**！

---

# 进阶例题 + 答案 + 详细解析

> 🧩 这几道题会综合运用你刚学过的知识。先自己思考，写代码试试，然后再看答案。

---

### 进阶题 1：统计句子中的单词数

**题目描述：**  
输入一个英文句子（可能包含多个空格），统计里面有多少个单词。假设单词之间由空格分隔，且句子开头和结尾可能有多余空格。  
**示例输入：** `"   Hello   world  from C   "`  
**示例输出：** `4`

<details>
<summary><b>✅ 点击查看答案与解析</b></summary>

```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h> // 为了用 bool 类型

int countWords(char str[]) {
    int count = 0;
    bool inWord = false;  // 当前是否在单词内部（就像是不是还在一个山楂里面）

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {        // 遇到非空格，说明碰到单词了
            if (!inWord) {          // 如果之前不在单词里，说明一个新单词开始了
                inWord = true;
                count++;
            }
        } else {
            inWord = false;         // 遇到空格，离开单词
        }
    }
    return count;
}

int main() {
    char sentence[] = "   Hello   world  from C   ";
    printf("单词数: %d\n", countWords(sentence)); // 输出 4
    return 0;
}
```

**解析：**
- 用一个布尔变量 `inWord` 就像个开关：当从空格进入字母时，开关打开，单词数 +1；遇到空格就关掉。
- 这样不管多少个连续空格，都只会在第一次遇到单词时计数。
</details>

---

### 进阶题 2：判断回文字符串

**题目描述：**  
回文是指正着读和倒着读都一样的字符串，比如 `"racecar"`, `"level"`，`"madam"`。请编写函数判断一个字符串是否是回文，忽略大小写。  
**示例输入：** `"Racecar"` → 是回文  
**示例输入：** `"Hello"` → 不是

<details>
<summary><b>✅ 点击查看答案与解析</b></summary>

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>  // 为了用 tolower

bool isPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // 都转成小写再比较，实现忽略大小写
        if (tolower(str[left]) != tolower(str[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    char s1[] = "Racecar";
    char s2[] = "Hello";
    printf("%s: %s\n", s1, isPalindrome(s1) ? "回文" : "不是回文");
    printf("%s: %s\n", s2, isPalindrome(s2) ? "回文" : "不是回文");
    return 0;
}
```

**解析：**
- 两个指针 `left` 和 `right` 一头一尾往中间走，像两个人从两端检查山楂是否一样。
- `tolower()` 函数可以把字母变成小写，这样 'R' 和 'r' 就被视作相同了。
</details>

---

### 进阶题 3：自己实现字符串反转

**题目描述：**  
写一个函数 `reverseString(char str[])`，将传入的字符串**原地反转**。  
**示例输入：** `"abcd"`  
**示例输出：** `"dcba"`

<details>
<summary><b>✅ 点击查看答案与解析</b></summary>

```c
#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int len = strlen(str);
    int left = 0;
    int right = len - 1;

    while (left < right) {
        // 交换左右两个山楂
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }
}

int main() {
    char test[] = "abcdef";
    reverseString(test);
    printf("反转后: %s\n", test); // "fedcba"
    return 0;
}
```

**解析：**
- 同样是双指针夹逼，交换两端的字符，直到中间相遇。跟检查回文很像，只是多了一个交换的动作。
</details>

---

### 进阶题 4：提取子串（类似 Python 的切片）

**题目描述：**  
手动实现一个函数 `substring(char dest[], char src[], int start, int len)`，从 `src` 的第 `start` 位置开始，截取 `len` 个字符存入 `dest`，并在末尾补上 `'\0'`。如果越界，需要合理截断。

<details>
<summary><b>✅ 点击查看答案与解析</b></summary>

```c
#include <stdio.h>
#include <string.h>

void substring(char dest[], char src[], int start, int len) {
    int srcLen = strlen(src);
    if (start >= srcLen) {
        dest[0] = '\0';  // 起始位置超出，返回空串
        return;
    }

    int i;
    for (i = 0; i < len && src[start + i] != '\0'; i++) {
        dest[i] = src[start + i];
    }
    dest[i] = '\0';  // 别忘了哨兵
}

int main() {
    char source[] = "Hello, world!";
    char result[20];

    substring(result, source, 7, 5);  // 从索引7开始取5个字符 -> "world"
    printf("截取结果: %s\n", result);

    substring(result, source, 0, 5);  // "Hello"
    printf("截取结果: %s\n", result);

    return 0;
}
```

**解析：**
- 用循环一个一个复制，同时检查是否到达原串的哨兵，防止越界。
- 最后一定要手动加上 `'\0'`，不然字符串会“放飞自我”。
</details>

---

### 进阶题 5：凯撒密码加密（简单字符替换）

**题目描述：**  
凯撒密码是一种古老的加密方式：把每个字母在字母表上向后移动固定位数。例如，加密 `"abc"`，偏移 3 位得到 `"def"`。请实现函数 `caesarEncrypt(char str[], int shift)`，只处理大写字母和小写字母，非字母不变。  
**示例输入：** `"Hello, Zoo!"`，偏移 `3`  
**示例输出：** `"Khoor, Crr!"`

<details>
<summary><b>✅ 点击查看答案与解析</b></summary>

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void caesarEncrypt(char str[], int shift) {
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if (isupper(ch)) {
            // 'A' 是 65，减去 65 得到 0-25 的序号，加偏移后取模，再加回 65
            str[i] = ((ch - 'A') + shift) % 26 + 'A';
        } else if (islower(ch)) {
            str[i] = ((ch - 'a') + shift) % 26 + 'a';
        }
        // 其他字符不变
    }
}

int main() {
    char msg[] = "Hello, Zoo!";
    caesarEncrypt(msg, 3);
    printf("加密结果: %s\n", msg); // Khoor, Crr!
    return 0;
}
```

**解析：**
- 利用 `isupper`/`islower` 判断类型。
- 字母的循环是通过 `% 26` 实现的，这样 'z' 往后移 3 位会绕回 'c'。
- 不需要改动 `strlen`，因为长度没变。
</details>

---

## 🎉 C 语言字符串通关总结

学完这些你已经掌握了：
- 字符串的本质：字符数组 + `'\0'`
- 如何安全输入输出
- 四大操作：复制、连接、比较、求长度
- 指针与数组的关系
- 常见算法：统计、回文、反转、截取、加密

> **最后一句忠告：** 在 C 语言里，操作字符串时永远多留一个心眼给 `'\0'`，永远检查数组够不够大。做到这两点，你就能避开 90% 的坑。

继续加油，下一步可以挑战**结构体与文件操作**，把你刚学的字符串真正用起来！