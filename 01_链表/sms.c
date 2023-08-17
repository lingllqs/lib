#include "sms.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

List *list;

void run()
{
    list = list_new(sizeof(Student));
    while (1)
    {
        system("clear");
        show_menu();
        char c;
        scanf("%c", &c);
        switch (c)
        {
        case '1':
            // 录入
            add_student();
            break;
        case '2':
            // 删除
            delete_student();
            break;
        case '3':
            // 查找
            search_student();
            break;
        case '4':
            // 修改
            modify_student();
            break;
        case '5':
            // 浏览
            travel_student();
            system("read -p \"按回车继续\"");
            break;
        case '6':
            save_student();
            break;
        case '7':
            load_student();
            break;
        case '0':
            // 退出
            list_destroy(list);
            exit(1);
        default:
            fprintf(stderr, "输入选项错误");
            sleep(1);
            break;
        }
        int ch;
        while ((ch = getchar()) != ' ' && ch != '\n')
            ;
    }
}

void add_student()
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

void delete_student()
{
    while (1)
    {
        system("clear");
        delete_menu();
        char c;
        scanf("%c", &c);
        switch (c)
        {
        case '1':
            delete_by_id();
            break;
        case '2':
            delete_by_name();
            break;
        case '3':
            delete_by_class();
            break;
        case '0':
            return;
        }
    }
}

void search_student()
{
}

void modify_student()
{
}

void travel_student()
{
    for_each(list, print);
}

void print(void *data)
{
    Student stu = *(Student *)data;
    printf("%d %s %s %.2lf %.2lf %.2lf\n", stu.id, stu.name, stu.cls, stu.c_score, stu.math, stu.english);
}

int cmp_by_id(void *dest, void *src)
{
    Student *stu = (Student *)dest;
    unsigned int id = *(unsigned int *)src;
    return stu->id - id;
}
int cmp_by_name(void *dest, void *src)
{
    Student *stu = (Student *)dest;
    char *name = (char *)src;
    return strcmp(stu->name, name);
}
int cmp_by_class(void *dest, void *src)
{
    Student *stu = (Student *)dest;
    char *class = (char *)src;
    return strcmp(stu->cls, class);
}

void delete_by_id()
{
    unsigned int id;
    printf("请输入要删除学生的学号: ");
    scanf("%u", &id);
    pop_key(list, &id, cmp_by_id);
}

void delete_by_name()
{
    char name[64];
    printf("请输入要删除学生的姓名: ");
    scanf("%s", name);
    pop_key(list, name, cmp_by_name);
}

void delete_by_class()
{
    char cls[64];
    printf("请输入要删除学生的班级: ");
    scanf("%s", cls);
    pop_key(list, cls, cmp_by_class);
}

void save_student()
{
    printf("请输入保存文件名称: ");
    char path[64];
    scanf("%s", path);
    FILE *fp = fopen(path, "w+");
    if (fp == NULL)
    {
        printf("打开或创建文件(%s)失败", path);
    }

    fprintf(fp, "学生人数: %u\n", list->size);

    int i;
    Node *p = list->front;
    for (i = 0; i < list->size; i++)
    {
        Student *stu = (Student *)p->data;
        fprintf(fp, "%-10u %-10s %-10s %6.2lf %6.2lf %6.2lf\n", stu->id, stu->name, stu->cls, stu->c_score, stu->math,
                stu->english);
        p = p->next;
    }

    fclose(fp);
}

void load_student()
{
    printf("请输入加载的文件名称: ");
    char path[64];
    scanf("%s", path);
    FILE *fp = fopen(path, "r");
    if (fp == NULL)
    {
        printf("打开文件(%s)失败", path);
    }

    int size;
    fscanf(fp, "学生人数: %u\n", &size);

    for (int i = 0; i < size; i++)
    {
        Student stu;
        fscanf(fp, "%u%s%s%lf%lf%lf\n", &stu.id, stu.name, stu.cls, &stu.c_score, &stu.math, &stu.english);
        print(&stu);
        push_back(list, &stu);
    }

    fclose(fp);
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
    printf("*********6.保存学生信息*********\n");
    printf("*********7.加载学生信息*********\n");
    printf("*********0.退出系统*************\n");
    printf("*********请输入选项*************\n");
}

void delete_menu()
{
    printf("*********功能列表********\n");
    printf("*********1.根据学号删除*********\n");
    printf("*********2.根据姓名删除*********\n");
    printf("*********3.根据班级删除*********\n");
    printf("*********0.返回主菜单*********\n");
    printf("*********请输入选项*************\n");
}
