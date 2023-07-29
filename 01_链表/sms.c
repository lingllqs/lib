#include "sms.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void run()
{
    List *list = list_new(sizeof(Student));
    while (1)
    {
        system("clear");
        show_menu();
        char c;
        scanf("%c", &c);
        switch (c)
        {
        case '1':
            add_student(list);
            break;
        case '2':
            delete_student(list);
            break;
        case '3':
            search_student(list);
            break;
        case '4':
            modify_student(list);
            break;
        case '5':
            travel_student(list);
            break;
        case '0':
            list_destroy(list);
            exit(1);
        }
        getchar();
        getchar();
    }
}

void add_student(List *list)
{
    Student stu;

    printf("请输入学生的学号: ");
    scanf("%d", &stu.id);

    printf("请输入学生的姓名: ");
    scanf("%s", stu.name);

    printf("请输入学生的班级: ");
    scanf("%s", stu.cls);

    printf("请输入学生的C语言成绩: ");
    scanf("%lf", &stu.c_score);

    printf("请输入学生的高数成绩: ");
    scanf("%lf", &stu.math);

    printf("请输入学生的英语成绩: ");
    scanf("%lf", &stu.english);

    push_back(list, &stu);
}

void delete_student(List *list)
{
    system("clear");
    printf("*********功能列表********\n");
    printf("*********1.根据学号删除*********\n");
    printf("*********2.根据姓名删除*********\n");
    printf("*********3.根据删班级除*********\n");
    printf("*********0.返回主菜单*********\n");
    printf("*********请输入选项*************\n");
}

void modify_student(List *list)
{
}

void print(void *data)
{
    Student stu = *(Student *)data;
    printf("%d %s %s %.2lf %.2lf %.2lf\n", stu.id, stu.name, stu.cls, stu.c_score, stu.math, stu.english);
}

void show_menu()
{
    printf("******************************************\n");
    printf("*********欢迎使用学生信息管理系统*********\n");
    printf("******************************************\n\n");

    printf("*********功能列表********\n");
    printf("*********1.录入学生信息*********\n");
    printf("*********2.删除学生信息*********\n");
    printf("*********3.查找学生信息*********\n");
    printf("*********4.修改学生信息*********\n");
    printf("*********5.浏览学生信息*********\n");
    printf("*********0.退出系统*************\n");
    printf("*********请输入选项*************\n");
}
