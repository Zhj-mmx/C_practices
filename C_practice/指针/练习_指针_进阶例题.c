# C语言指针 进阶例题 + 答案详解（初中生友好版）

> 🧠 **进阶提示**：下面的题目会把指针和你之前学过的数组、函数、结构体组合起来，解决更接近真实编程的问题。继续用生活比喻，但逻辑会更复杂一点。  
> 建议：先自己画内存图（柜子分布图），再写代码。

---

## 进阶例题1：指针数组——管理多个藏宝图

**生活场景**：  
你有 4 个宝箱，每个宝箱里放着一个数字。你画了 4 张藏宝图。现在需要一个小册子，把 4 张藏宝图收集在一起，方便管理。  
这个小册子就是一个**指针数组**——数组的每个格子里放的不是普通数字，而是一张藏宝图（指针）。

**任务要求**：  
1. 创建 4 个 `int` 变量 `a=10, b=20, c=30, d=40`。  
2. 创建一个指针数组 `arr[4]`，依次存放 `a, b, c, d` 的地址。  
3. 用一个循环通过指针数组打印出 4 个变量的值。  
4. 通过指针数组把 `b` 的值修改为 `999`。

```c
#include <stdio.h>

int main() {
    int a = 10, b = 20, c = 30, d = 40;
    
    // ========== 你的代码在这里 ==========
    // 声明指针数组 arr，并将四个变量的地址存进去
    int *arr[4] = {______, ______, ______, ______};
    // ===================================
    
    printf("=== 通过指针数组打印原始值 ===\n");
    for (int i = 0; i < 4; i++) {
        printf("arr[%d] 指向的值: %d\n", i, ______);  // 解引用
    }
    
    // 修改 b 的值为 999
    ______ = 999;   // 用 arr 去修改
    
    printf("\n修改后 b = %d\n", b);  // 应输出 999
    
    return 0;
}
```

<details>
<summary><b>✅ 点击查看答案与解析</b></summary>

**完整答案代码：**
```c
#include <stdio.h>

int main() {
    int a = 10, b = 20, c = 30, d = 40;
    
    // 指针数组：每个元素是一个 int* 类型的指针
    int *arr[4] = {&a, &b, &c, &d};
    
    printf("=== 通过指针数组打印原始值 ===\n");
    for (int i = 0; i < 4; i++) {
        printf("arr[%d] 指向的值: %d\n", i, *arr[i]);  // *arr[i] 拿出第i张藏宝图，找到宝箱
    }
    
    // 修改 b：arr[1] 是 b 的地址，*arr[1] 进入 b 的房间
    *arr[1] = 999;
    
    printf("\n修改后 b = %d\n", b);  // 999
    
    return 0;
}
```

**解析（初中生版）：**
- `int *arr[4]`：这个语法读作“arr 是一个有4个格子的数组，每个格子里放的是 `int*` 类型的藏宝图”。  
- 初始化时直接用 `{&a, &b, &c, &d}` 把四个宝箱的地址依次放进小册子。  
- `*arr[i]`：先取小册子第 `i` 页的藏宝图，再用 `*` 按图找到宝箱打开看。  
- 修改 `*arr[1] = 999`：找到 b 的房间，把里面的东西换成 999。

> **区别重要**：  
> - 数组指针：`int (*p)[4]` —— 一张藏宝图，指着“一整排4个宝箱”。  
> - 指针数组：`int *p[4]` —— 一个本子，装着4张藏宝图。  
> 我们今天用的是指针数组。
</details>

---

## 进阶例题2：函数指针——把“方法说明书”当成纸条传递

**生活场景**：  
有时候你想让一个函数变得万能——不是把数据传进去，而是把**“做事的方法”**传进去。比如一个排序函数，你想让它有时按成绩排，有时按身高排，你不需要写两个排序，只需传入不同的“比较方法”。  
“比较方法”就是一个函数，我们把函数的地址（像说明书所在柜子的地址）传给排序函数。这就是**函数指针**。

**任务要求**：  
1. 写两个函数：`add(int a, int b)` 返回两数和；`multiply(int a, int b)` 返回两数积。  
2. 写一个 **“通用计算器”函数** `compute(int x, int y, int (*op)(int, int))`，它接受两个整数和一个函数指针，用传入的函数处理 x 和 y 并返回结果。  
3. 在 `main` 中调用 `compute`，分别做加法和乘法，并打印结果。

```c
#include <stdio.h>

// 加法和乘法函数
int add(int a, int b) {
    return a + b;
}
int multiply(int a, int b) {
    return a * b;
}

// 通用计算器：第三个参数 op 是函数指针，指向“二元操作方法”
int compute(int x, int y, int (*op)(int, int)) {
    return op(x, y);   // 通过纸条调用函数
}

int main() {
    int a = 10, b = 5;
    
    // ========== 你的代码在这里 ==========
    int sum = compute(a, b, ______);   // 传入加法说明书
    int prod = compute(a, b, ______);  // 传入乘法说明书
    // ===================================
    
    printf("10 + 5 = %d\n", sum);
    printf("10 * 5 = %d\n", prod);
    return 0;
}
```

<details>
<summary><b>✅ 点击查看答案与解析</b></summary>

**完整答案代码：**
```c
#include <stdio.h>

int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

int compute(int x, int y, int (*op)(int, int)) {
    return op(x, y);
}

int main() {
    int a = 10, b = 5;
    
    int sum = compute(a, b, add);      // 函数名就是函数地址
    int prod = compute(a, b, multiply);
    
    printf("10 + 5 = %d\n", sum);      // 15
    printf("10 * 5 = %d\n", prod);     // 50
    return 0;
}
```

**解析（初中生版）：**
- 函数指针的声明比较吓人：`int (*op)(int, int)`。拆解：  
  - `*op` 表示 op 是一张纸条。  
  - 前面 `int` 表示纸条指向的函数**返回类型**是 `int`。  
  - 后面 `(int, int)` 表示这个函数需要两个 `int` 参数。  
- 函数名 `add` 本身就代表函数的地址（就像数组名代表首地址）。所以直接传 `add` 即可。  
- `op(x, y)` 就是拿着那张“说明书”去调用对应的函数。  
- 这样 `compute` 就变成了万能计算器，以后想加新运算（减法、除法）只需写新函数，`compute` 不用改。
</details>

---

## 进阶例题3：动态二维数组——用指针模拟“学霸座位表”

**生活场景**：  
你需要一个**座位表**（二维数组）来存每个学生的成绩，但行数（学生数）和列数（科目数）是用户输入的。普通的二维数组必须在编译时确定大小，现在我们用指针和 `malloc` 动态创建。

**任务要求**：  
1. 用户输入行数 `rows` 和列数 `cols`。  
2. 动态分配一个 `rows` 行 `cols` 列的二维数组，用来存放成绩。  
3. 输入所有成绩，并打印矩阵。  
4. 释放所有内存。

**技术提示**：需要先分配 `rows` 个**行指针**，然后为每一行分配 `cols` 个 `int` 房间。

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    printf("请输入行数（学生数）和列数（科目数）: ");
    scanf("%d %d", &rows, &cols);
    
    // ========== 你的代码在这里 ==========
    // 第一步：分配指针数组（每行一个藏宝图）
    int **matrix = (int **)malloc(______ * sizeof(int *));
    // 第二步：为每一行分配 cols 个 int 房间
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(______ * sizeof(int));
    }
    // ===================================
    
    // 输入成绩
    printf("请输入 %d x %d 的成绩矩阵:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);   // 可以直接像二维数组一样用！
        }
    }
    
    // 打印矩阵
    printf("\n成绩表:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
    
    // 释放：先释放每一行，再释放指针数组
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);   // 退租每一行的房间
    }
    free(matrix);           // 退租藏宝图小册子本身
    matrix = NULL;
    
    return 0;
}
```

<details>
<summary><b>✅ 点击查看答案与解析</b></summary>

**填空答案：**
```c
int **matrix = (int **)malloc(rows * sizeof(int *));
for (int i = 0; i < rows; i++) {
    matrix[i] = (int *)malloc(cols * sizeof(int));
}
```

**解析（初中生版）：**
- `int **matrix`：这是一个**二级指针**。它指向一本“藏宝图小册子”，小册子里每一页是一张藏宝图，记录着一行房间的位置。  
- `malloc(rows * sizeof(int *))`：租 `rows` 页的小册子，每页大小是存放一个指针所需的字节数。  
- 循环里 `matrix[i] = malloc(cols * sizeof(int))`：给每一页画上藏宝图——租了 `cols` 个 `int` 柜子，并把第一间柜子的钥匙（地址）放在小册子第 `i` 页。  
- 访问 `matrix[i][j]`：先从册子第 `i` 页拿到藏宝图，再按图找到第 `j` 个柜子，完全等价于普通二维数组。  
- 释放时必须**先释放每一行的房间**，再释放小册子本身，否则小册子丢了就找不到行的房间，造成内存泄漏。
</details>

---

## 进阶例题4：指针与结构体——通过纸条修改学生档案

**生活场景**：  
每个学生都有一个档案袋（结构体），里面有姓名和分数。你现在要做两件事：  
1. 直接通过指针读取和修改某个学生的分数。  
2. 写一个“升级函数”，把分数不够 60 的学生加分到 60（补考通过），用指针传递避免复制整个档案袋。

**任务要求**：  
1. 定义结构体 `Student`，包含 `name[20]` 和 `score`。  
2. 创建一个学生 `s1 = {"小明", 55}`，用指针 `p` 指向它。  
3. 通过 `p` 把分数改为 60（直接改）。  
4. 编写函数 `passCheck(Student *stu)`，如果分数 < 60 则设为 60。  
5. 调用该函数处理 `s1`，并打印结果。

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    int score;
} Student;

// 补考升级函数
void passCheck(Student *stu) {
    // ========== 你的代码在这里 ==========
    // 通过指针访问分数并修改
    if (______ < 60) {
        ______ = 60;
    }
    // ===================================
}

int main() {
    Student s1;
    strcpy(s1.name, "小明");
    s1.score = 55;
    
    Student *p = &s1;
    
    printf("=== 原始档案 ===\n");
    printf("姓名: %s, 分数: %d\n", ______, ______);  // 通过指针打印
    
    // 通过指针直接改成 60
    ______ = 60;
    printf("直接修改后分数: %d\n", s1.score);
    
    // 改回 55，再用函数处理
    s1.score = 55;
    passCheck(______);   // 传地址
    printf("补考后分数: %d\n", s1.score);   // 应为 60
    
    return 0;
}
```

<details>
<summary><b>✅ 点击查看答案与解析</b></summary>

**完整答案代码：**
```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    int score;
} Student;

void passCheck(Student *stu) {
    if (stu->score < 60) {   // 通过箭头访问成员
        stu->score = 60;
    }
}

int main() {
    Student s1;
    strcpy(s1.name, "小明");
    s1.score = 55;
    
    Student *p = &s1;
    
    printf("=== 原始档案 ===\n");
    printf("姓名: %s, 分数: %d\n", p->name, p->score);  // 指针访问结构体成员
    
    p->score = 60;   // 直接通过指针修改
    printf("直接修改后分数: %d\n", s1.score);
    
    s1.score = 55;   // 改回去
    passCheck(&s1);  // 传地址
    printf("补考后分数: %d\n", s1.score);  // 60
    
    return 0;
}
```

**解析（初中生版）：**
- 访问结构体成员有两种方式：  
  - 用普通变量 `s1.分数`。  
  - 用指针 `p->分数`。箭头 `->` 就是“拿着地址直接进入档案袋找某个条目”。  
- `passCheck` 的参数是 `Student *stu`，调用时传入 `&s1`（把档案袋位置告诉函数），函数内部通过 `stu->score` 直接修改原件。  
- 这样避免了复制整个 `Student` 结构体（里面可能有很多信息），既快又省内存。

> 延伸思考：如果结构体很大（比如包含头像照片），用值传递会非常浪费，所以一般都用指针传递结构体。
</details>

---

## 进阶例题5：链表节点——用指针把柜子串成一条龙

**生活场景**：  
数组是一排连号的柜子，但有时候你不需要连号，你想把柜子散落在各地，然后用一根绳子（指针）把它们串起来：每个柜子里除了数据，还放着一张纸条，写着下一个柜子的地址。这就是**链表**。

**任务要求**：  
1. 定义链表节点结构体 `Node`，包含 `int data` 和 `Node *next`。  
2. 手动创建三个节点，存放数据 10、20、30，并把它们串成一条链。  
3. 编写函数 `printList` 遍历链表并打印所有数据。  
4. 在链表头部插入一个新节点（数据 5），再打印。

```c
#include <stdio.h>
#include <stdlib.h>

// 链表节点：一个宝箱，里面放着数据和指向下一个宝箱的纸条
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 遍历打印链表
void printList(Node *head) {
    // ========== 你的代码在这里 ==========
    // 提示：用 while 循环，顺着 next 纸条走，直到 NULL
    Node *cur = ______;
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = ______;   // 移动到下一个宝箱
    }
    printf("NULL\n");
    // ===================================
}

// 在头部插入新节点（返回新头指针）
Node* insertHead(Node *head, int newData) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = ______;   // 新节点的 next 指向上一个头节点
    return newNode;            // 新节点成为新的头
}

int main() {
    // 创建三个节点并串起来
    Node *n1 = (Node *)malloc(sizeof(Node));
    Node *n2 = (Node *)malloc(sizeof(Node));
    Node *n3 = (Node *)malloc(sizeof(Node));
    
    n1->data = 10; n1->next = n2;
    n2->data = 20; n2->next = n3;
    n3->data = 30; n3->next = NULL;   // 最后一张纸条是空
    
    Node *head = n1;
    printf("原始链表: ");
    printList(head);
    
    // 头部插入 5
    head = insertHead(head, 5);
    printf("头部插入5后: ");
    printList(head);
    
    // 释放内存（好习惯）
    Node *cur = head, *temp;
    while (cur != NULL) {
        temp = cur;
        cur = cur->next;
        free(temp);
    }
    return 0;
}
```

<details>
<summary><b>✅ 点击查看答案与解析</b></summary>

**填空答案：**
```c
void printList(Node *head) {
    Node *cur = head;
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

Node* insertHead(Node *head, int newData) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = head;   // 新节点指向原先的头
    return newNode;
}
```

**解析（初中生版）：**
- **链表**：每个宝箱分成两个格子——一格放数据（`data`），一格放指向下个宝箱的藏宝图（`next`）。  
- `printList`：从头结点出发，每次通过 `cur->next` 拿到下一张藏宝图，走到藏宝图是 `NULL`（空）表示到队尾。  
- `insertHead`：新宝箱的 `next` 指向原来的头，然后新宝箱成为新的头，就像排队时有人插队到最前面。  
- 链表的好处：插入删除不需要移动大量数据，只需改几张纸条。但访问第 `k` 个元素必须从头一个个找（不能像数组直接下标跳转）。
</details>

---

> 🏆 **恭喜你完成了进阶练习！**  
> 这五道题涵盖了指针数组、函数指针、动态二维数组、结构体指针和链表节点，这些都是C语言里指针真正发挥威力的地方。  
> 每道题都建议自己画一画内存图（宝箱和纸条的分布），然后上机修改参数，故意制造内存泄漏或越界，观察报错——你会进步飞快！