/**
 * 练习10：综合练习 - 成绩管理系统（命令行版）
 * 综合运用数组、结构体、函数等知识点
 */

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50

// 学生结构体
struct Student {
    int id;
    char name[MAX_NAME_LEN];
    float scores[3];  // 语文、数学、英语
    float average;
};

// 全局变量
struct Student students[MAX_STUDENTS];
int studentCount = 0;

// 函数声明
void printMenu();
void addStudent();
void displayAllStudents();
void findStudentById();
void calculateClassAverage();
void sortStudentsByAverage();
void deleteStudent();

int main() {
    int choice;
    
    printf("=== 欢迎使用成绩管理系统 ===\n\n");
    
    do {
        printMenu();
        printf("请选择功能 (1-6): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAllStudents();
                break;
            case 3:
                findStudentById();
                break;
            case 4:
                calculateClassAverage();
                break;
            case 5:
                // sort by average (placeholder)
                printf("功能尚未实现！\n");
                break;
            case 6:
                printf("感谢使用成绩管理系统，再见！\n");
                break;
            default:
                printf("无效选择，请重新输入！\n");
        }
        
        printf("\n");
    } while (choice != 6);
    
    return 0;
}

// 显示菜单
void printMenu() {
    printf("=== 主菜单 ===\n");
    printf("1. 添加学生\n");
    printf("2. 显示所有学生\n");
    printf("3. 按学号查找学生\n");
    printf("4. 计算班级平均分\n");
    printf("5. 按平均分排序（未实现）\n");
    printf("6. 退出系统\n");
}

// 添加学生
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("错误: 学生数量已达上限！\n");
        return;
    }
    
    printf("=== 添加新学生 ===\n");
    
    printf("学号: ");
    scanf("%d", &students[studentCount].id);
    
    printf("姓名: ");
    scanf("%s", students[studentCount].name);
    
    printf("语文成绩: ");
    scanf("%f", &students[studentCount].scores[0]);
    
    printf("数学成绩: ");
    scanf("%f", &students[studentCount].scores[1]);
    
    printf("英语成绩: ");
    scanf("%f", &students[studentCount].scores[2]);
    
    // 计算平均分
    students[studentCount].average = 
        (students[studentCount].scores[0] + 
         students[studentCount].scores[1] + 
         students[studentCount].scores[2]) / 3.0;
    
    studentCount++;
    printf("添加成功！\n");
}

// 显示所有学生
void displayAllStudents() {
    if (studentCount == 0) {
        printf("目前没有学生记录。\n");
        return;
    }
    
    printf("=== 所有学生信息 ===\n");
    printf("%-10s %-10s %-8s %-8s %-8s %-10s\n", 
           "学号", "姓名", "语文", "数学", "英语", "平均分");
    printf("---------------------------------------------------\n");
    
    for (int i = 0; i < studentCount; i++) {
        printf("%-10d %-10s %-8.1f %-8.1f %-8.1f %-10.2f\n",
               students[i].id,
               students[i].name,
               students[i].scores[0],
               students[i].scores[1],
               students[i].scores[2],
               students[i].average);
    }
    printf("\n总计: %d 名学生\n", studentCount);
}

// 按学号查找学生
void findStudentById() {
    int id;
    printf("请输入要查找的学号: ");
    scanf("%d", &id);
    
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("=== 找到学生 ===\n");
            printf("学号: %d\n", students[i].id);
            printf("姓名: %s\n", students[i].name);
            printf("语文: %.1f\n", students[i].scores[0]);
            printf("数学: %.1f\n", students[i].scores[1]);
            printf("英语: %.1f\n", students[i].scores[2]);
            printf("平均分: %.2f\n", students[i].average);
            return;
        }
    }
    
    printf("未找到学号为 %d 的学生。\n", id);
}

// 计算班级平均分
void calculateClassAverage() {
    if (studentCount == 0) {
        printf("目前没有学生记录。\n");
        return;
    }
    
    float sumChinese = 0, sumMath = 0, sumEnglish = 0;
    
    for (int i = 0; i < studentCount; i++) {
        sumChinese += students[i].scores[0];
        sumMath += students[i].scores[1];
        sumEnglish += students[i].scores[2];
    }
    
    printf("=== 班级成绩统计 ===\n");
    printf("总人数: %d\n", studentCount);
    printf("语文平均分: %.2f\n", sumChinese / studentCount);
    printf("数学平均分: %.2f\n", sumMath / studentCount);
    printf("英语平均分: %.2f\n", sumEnglish / studentCount);
    printf("三科综合平均分: %.2f\n", 
           (sumChinese + sumMath + sumEnglish) / (studentCount * 3));
}
