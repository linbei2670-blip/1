#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct Student {
    int id;
    char name[20];
    float c_score;
    float math_score;
    float total_score;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void ShowMenu();
void AddStudent();
void ViewAll();
void SearchStudent();
void ModifyStudent();
void DeleteStudent();
void SortByTotal();
void CalculateStats();
void ClearInputBuffer();

int main() {
    int choice;

    while (1) {
        ShowMenu();
        printf("请输入您的选择 (0-7): ");

        if (scanf("%d", &choice) != 1) {
            printf("\n 输入非法！请输入数字。\n");
            ClearInputBuffer();
            system("pause");
            continue;
        }

        switch (choice) {
        case 1: AddStudent(); break;
        case 2: ViewAll(); break;
        case 3: SearchStudent(); break;
        case 4: ModifyStudent(); break;
        case 5: DeleteStudent(); break;
        case 6: SortByTotal(); break;
        case 7: CalculateStats(); break;
        case 0:
            printf("\n感谢使用，系统已安全退出！\n");
            return 0;
        default:
            printf("\n 没有这个选项，请重新输入！\n");
        }
        system("pause");
    }
}

void ShowMenu() {
    system("cls");
    printf("===================================\n");
    printf("      学生成绩管理系统       \n");
    printf("===================================\n");
    printf("         1. 录入学生成绩\n");
    printf("         2. 显示所有成绩\n");
    printf("         3. 查找学生成绩\n");
    printf("         4. 修改学生成绩\n");
    printf("         5. 删除学生记录\n");
    printf("         6. 按总分降序排序\n");
    printf("         7. 班级成绩统计\n");
    printf("         0. 退出管理系统\n");
    printf("===================================\n");
}

void AddStudent() {
    if (student_count >= MAX_STUDENTS) {
        printf("\n 系统已满，无法继续录入！\n");
        return;
    }

    Student s;
    printf("\n--- 录入学生信息 ---\n");
    printf("请输入学号: ");
    scanf("%d", &s.id);

    for (int i = 0; i < student_count; i++) {
        if (students[i].id == s.id) {
            printf("\n 错误：该学号已存在，无法重复录入！\n");
            return;
        }
    }

    printf("请输入姓名: ");
    scanf("%s", s.name);
    printf("请输入C语言成绩: ");
    scanf("%f", &s.c_score);
    printf("请输入高数成绩: ");
    scanf("%f", &s.math_score);

    s.total_score = s.c_score + s.math_score;

    students[student_count] = s;
    student_count++;

    printf("\n录入成功！\n");
}

void ViewAll() {
    if (student_count == 0) {
        printf("\n当前系统中暂无学生数据。\n");
        return;
    }

    printf("\n---------------------------------------------------------\n");
    printf("%-10s %-12s %-10s %-10s %-10s\n", "学号", "姓名", "C语言", "高数", "总分");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < student_count; i++) {
        printf("%-10d %-12s %-10.1f %-10.1f %-10.1f\n",
            students[i].id,
            students[i].name,
            students[i].c_score,
            students[i].math_score,
            students[i].total_score);
    }
    printf("---------------------------------------------------------\n");
    printf("共计: %d 个学生记录。\n", student_count);
}

void SearchStudent() {
    if (student_count == 0) {
        printf("\n数据为空，无法查找。\n");
        return;
    }

    int id;
    printf("\n请输入要查找的学生学号: ");
    scanf("%d", &id);

    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            printf("\n 找到该学生信息：\n");
            printf("学号: %d\n", students[i].id);
            printf("姓名: %s\n", students[i].name);
            printf("C语言: %.1f\n", students[i].c_score);
            printf("高数: %.1f\n", students[i].math_score);
            printf("总分: %.1f\n", students[i].total_score);
            return;
        }
    }
    printf("\n 未找到学号为 %d 的学生。\n", id);
}

void ModifyStudent() {
    int id;
    printf("\n请输入要修改的学生学号: ");
    scanf("%d", &id);

    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            printf("\n找到该学生当前成绩：C语言(%.1f), 高数(%.1f)\n", students[i].c_score, students[i].math_score);
            printf("请输入新的C语言成绩: ");
            scanf("%f", &students[i].c_score);
            printf("请输入新的高数成绩: ");
            scanf("%f", &students[i].math_score);

            students[i].total_score = students[i].c_score + students[i].math_score;
            printf("\n 修改成功！\n");
            return;
        }
    }
    printf("\n 修改失败：未找到该学生。\n");
}

void DeleteStudent() {
    int id;
    printf("\n 请输入要删除的学生学号: ");
    scanf("%d", &id);

    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("\n 成功删除学号为 %d 的学生记录。\n", id);
            return;
        }
    }
    printf("\n 删除失败：未找到该学生。\n");
}

void SortByTotal() {
    if (student_count < 2) {
        printf("\n学生人数不足，无需排序。\n");
        return;
    }

    for (int i = 0; i < student_count - 1; i++) {
        for (int j = 0; j < student_count - 1 - i; j++) {
            if (students[j].total_score < students[j + 1].total_score) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("\n 已按总分从高到低完成排序！请选择功能2查看效果。\n");
}

void CalculateStats() {
    if (student_count == 0) {
        printf("\n没有学生数据，无法生成统计报告。\n");
        return;
    }

    float c_sum = 0, math_sum = 0;
    float c_max = students[0].c_score;
    float math_max = students[0].math_score;

    for (int i = 0; i < student_count; i++) {
        c_sum += students[i].c_score;
        math_sum += students[i].math_score;

        if (students[i].c_score > c_max) c_max = students[i].c_score;
        if (students[i].math_score > math_max) math_max = students[i].math_score;
    }

    printf("\n=======  班级成绩统计报告 =======\n");
    printf("总人数: %d 人\n", student_count);
    printf("C语言 - 平均分: %.2f | 最高分: %.1f\n", c_sum / student_count, c_max);
    printf("高 数 - 平均分: %.2f | 最高分: %.1f\n", math_sum / student_count, math_max);
    printf("===================================\n");
}

void ClearInputBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}