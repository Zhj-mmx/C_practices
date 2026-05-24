/**
 * 练习9：结构体基础
 * 练习结构体的定义和使用
 */

#include <stdio.h>
#include <string.h>

// 定义结构体
struct Student {
    char name[50];
    int age;
    float score;
};

// 定义嵌套结构体
struct Date {
    int year;
    int month;
    int day;
};

struct Person {
    char name[50];
    int age;
    struct Date birthday;
};

int main() {
    printf("=== 结构体基础练习 ===\n\n");
    
    // 练习1: 声明和初始化结构体变量
    printf("1. 声明和初始化结构体:\n");
    
    // 方式1: 分别赋值
    struct Student s1;
    strcpy(s1.name, "张三");
    s1.age = 20;
    s1.score = 85.5;
    
    printf("   方式1 - 分别赋值:\n");
    printf("   姓名: %s, 年龄: %d, 成绩: %.1f\n\n", s1.name, s1.age, s1.score);
    
    // 方式2: 初始化列表
    struct Student s2 = {"李四", 19, 92.0};
    
    printf("   方式2 - 初始化列表:\n");
    printf("   姓名: %s, 年龄: %d, 成绩: %.1f\n\n", s2.name, s2.age, s2.score);
    
    // 方式3: 指定字段初始化（C99特性）
    struct Student s3 = {.name = "王五", .score = 78.5, .age = 21};
    
    printf("   方式3 - 指定字段初始化:\n");
    printf("   姓名: %s, 年龄: %d, 成绩: %.1f\n\n", s3.name, s3.age, s3.score);
    
    // 练习2: 结构体数组
    printf("2. 结构体数组:\n");
    struct Student students[3] = {
        {"赵六", 18, 88.0},
        {"孙七", 20, 95.5},
        {"周八", 19, 72.5}
    };
    
    printf("   学生信息列表:\n");
    for (int i = 0; i < 3; i++) {
        printf("   学生%d: %s, 年龄: %d, 成绩: %.1f\n", 
               i + 1, students[i].name, students[i].age, students[i].score);
    }
    printf("\n");
    
    // 练习3: 计算平均分
    printf("3. 计算平均分:\n");
    float sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += students[i].score;
    }
    printf("   三名学生的平均分: %.2f\n\n", sum / 3);
    
    // 练习4: 嵌套结构体
    printf("4. 嵌套结构体:\n");
    struct Person person = {"梦哥", 20, {2005, 1, 15}};
    
    printf("   个人信息:\n");
    printf("   姓名: %s, 年龄: %d\n", person.name, person.age);
    printf("   出生日期: %d年%d月%d日\n\n", 
           person.birthday.year, person.birthday.month, person.birthday.day);
    
    // 练习5: 结构体指针
    printf("5. 结构体指针:\n");
    struct Student *ptr = &s1;
    
    printf("   使用结构体指针访问成员:\n");
    printf("   姓名: %s\n", ptr->name);
    printf("   年龄: %d\n", ptr->age);
    printf("   成绩: %.1f\n\n", ptr->score);
    
    // 练习6: 通过指针修改成员
    printf("6. 通过指针修改结构体成员:\n");
    printf("   修改前: s1.age = %d\n", s1.age);
    ptr->age = 21;
    printf("   修改后: s1.age = %d\n", s1.age);
    printf("   (通过 ptr->age = 21 修改)\n\n");
    
    // 练习7: 结构体作为函数参数
    printf("7. 结构体作为函数参数:\n");
    
    void printStudent(struct Student s);
    void updateScore(struct Student *s, float newScore);
    
    printStudent(s2);
    printf("   更新前成绩: %.1f\n", s2.score);
    updateScore(&s2, 98.5);
    printf("   更新后成绩: %.1f\n\n", s2.score);
    
    // 练习8: 查找最高分学生
    printf("8. 查找最高分学生:\n");
    int maxIndex = 0;
    float maxScore = students[0].score;
    
    for (int i = 1; i < 3; i++) {
        if (students[i].score > maxScore) {
            maxScore = students[i].score;
            maxIndex = i;
        }
    }
    
    printf("   最高分学生: %s, 成绩: %.1f\n\n", students[maxIndex].name, maxScore);
    
    return 0;
}

// 函数定义
void printStudent(struct Student s) {
    printf("   学生: %s, 年龄: %d, 成绩: %.1f\n", s.name, s.age, s.score);
}

void updateScore(struct Student *s, float newScore) {
    s->score = newScore;
}
