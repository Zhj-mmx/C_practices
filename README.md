# C语言入门练习集合

这是一个为初学者准备的C语言练习项目，包含10个循序渐进的练习文件。

## 练习列表

| 编号 | 文件名 | 主题 | 难度 |
|------|--------|------|------|
| 1 | 01_hello_world.c | Hello World - 基础语法 | ⭐ |
| 2 | 02_basic_types.c | 基本数据类型和运算 | ⭐ |
| 3 | 03_conditions.c | 条件判断 (if-else) | ⭐⭐ |
| 4 | 04_loops.c | 循环结构 (for/while/do-while) | ⭐⭐ |
| 5 | 05_arrays.c | 数组基础 | ⭐⭐⭐ |
| 6 | 06_functions.c | 函数定义和调用 | ⭐⭐⭐ |
| 7 | 07_strings.c | 字符串处理 | ⭐⭐⭐ |
| 8 | 08_pointers.c | 指针基础 (进阶) | ⭐⭐⭐⭐ |
| 9 | 09_structures.c | 结构体 | ⭐⭐⭐⭐ |
| 10 | 10_grade_system.c | 综合练习 - 成绩管理系统 | ⭐⭐⭐⭐⭐ |

## 如何使用

### 编译和运行

```bash
# 编译单个文件
gcc 01_hello_world.c -o hello

# 运行程序
./hello

# 或者一行命令
gcc 01_hello_world.c -o hello && ./hello
```

### Windows (使用 MinGW)

```bash
# 编译
gcc 01_hello_world.c -o hello.exe

# 运行
hello.exe
```

## 学习路径建议

1. **第1-2天**：练习 1-2 (Hello World, 基本类型)
2. **第3-4天**：练习 3-4 (条件判断, 循环)
3. **第5-6天**：练习 5 (数组)
4. **第7-8天**：练习 6 (函数)
5. **第9-10天**：练习 7 (字符串)
6. **第11-12天**：练习 8 (指针 - 重点难点)
7. **第13-14天**：练习 9 (结构体)
8. **第15天+**：练习 10 (综合项目)

## 环境准备

需要安装C语言编译器：

- **Windows**: MinGW 或 Visual Studio Build Tools
- **macOS**: Xcode Command Line Tools (`xcode-select --install`)
- **Linux**: `sudo apt-get install build-essential` (Debian/Ubuntu)

## 每个练习包含

- 详细的中文注释
- 多种实现方式对比
- 实用的示例代码
- 语法要点说明

## 注意事项

- 指针和内存管理是C语言的重点和难点，建议多花时间理解
- 建议亲手敲代码，不要只是阅读
- 遇到问题时，注意编译器错误信息的提示
- 多使用 printf 调试程序状态

## 下一步

掌握这些基础后，可以尝试：
- 动态内存分配 (malloc/free)
- 文件操作
- 链表、树等数据结构
- 更复杂的项目实践

祝学习愉快！ 🌱
