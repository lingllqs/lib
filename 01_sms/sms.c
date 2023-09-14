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
            printf("+---------------+---------------+---------------+---------------+---------------+---------------+\n");
            printf("| %s\t\t| %s\t\t| %s\t\t| %s\t\t| %s\t\t| %s\t\t|\n", "学号", "姓名", "班级", "编程", "数学", "英语");
            printf("+---------------+---------------+---------------+---------------+---------------+---------------+\n");
            travel_student();
            printf("+---------------+---------------+---------------+---------------+---------------+---------------+\n");
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
        flush_input();
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
        flush_input();
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
    while (1)
    {
        system("clear");
        flush_input();
        search_menu();
        char c;
        scanf("%c", &c);
        switch (c)
        {
        case '1':
            search_by_id();
            break;
        case '2':
            search_by_name();
            break;
        case '3':
            search_by_class();
            break;
        case '0':
            return;
        }
    }
}

void modify_student()
{
    while (1)
    {
        system("clear");
        flush_input();
        modify_menu();
        char c;
        scanf("%c", &c);
        switch (c)
        {
        case '1':
            // 查找学生学号
            modify_by_id();
            break;
        case '2':
            modify_by_name();
            break;
        case '0':
            return;
        }
    }
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

void search_by_id()
{
    unsigned int id;
    printf("请输入要查找学生的学号: ");
    scanf("%u", &id);
    find_all(list, &id, cmp_by_id, print);
    system("read -p \"按回车继续\"");
}

void search_by_name()
{
    char name[64];
    printf("请输入要查找学生的姓名: ");
    scanf("%s", name);
    find_all(list, name, cmp_by_name, print);
    system("read -p \"按回车继续\"");
}

void search_by_class()
{
    char cls[64];
    printf("请输入要查找学生的班级: ");
    scanf("%s", cls);
    find_all(list, cls, cmp_by_class, print);
    system("read -p \"按回车继续\"");
}

void modify_by_id()
{
    unsigned int old_id;
    printf("请输入要修改学生的id: ");
    scanf("%u", &old_id);
    while (1)
    {
        system("clear");
        flush_input();
        alter_menu();
        char c;
        scanf("%c", &c);
        switch (c)
        {
        case '1':
            alter_id(old_id);
            break;
        case '2':
            alter_name(old_id);
            break;
        case '3':
            alter_class(old_id);
            break;
        case '4':
            alter_c_score(old_id);
            break;
        case '5':
            alter_math(old_id);
            break;
        case '6':
            alter_english(old_id);
            break;
        case '0':
            return;
        }
    }
}

void modify_by_name()
{
    char old_name[64];
    printf("请输入要修改学生的姓名: ");
    scanf("%s", old_name);
    while (1)
    {
        system("clear");
        flush_input();
        alter_menu();
        char c;
        scanf("%c", &c);
        switch (c)
        {
        case '1':
            chg_id(old_name);
            break;
        case '2':
            chg_name(old_name);
            break;
        case '3':
            chg_class(old_name);
            break;
        case '4':
            chg_c_score(old_name);
            break;
        case '5':
            chg_math(old_name);
            break;
        case '6':
            chg_english(old_name);
            break;
        case '0':
            return;
        }
    }
}

void opt_id(void *dest, void *src)
{
    Student *stu = (Student *)dest;
    unsigned int id = *(unsigned int *)src;
    stu->id = id;
}

void opt_name(void *dest, void *src)
{
    Student *stu = (Student *)dest;
    char *name = (char *)src;
    strcpy(stu->name, name);
}

void opt_class(void *dest, void *src)
{
    Student *stu = (Student *)dest;
    char *class = (char *)src;
    strcpy(stu->cls, class);
}

void opt_c_score(void *dest, void *src)
{
    Student *stu = (Student *)dest;
    double c_score = *(double *)src;
    stu->c_score = c_score;
}

void opt_math(void *dest, void *src)
{
    Student *stu = (Student *)dest;
    double math = *(double *)src;
    stu->math = math;
}

void opt_english(void *dest, void *src)
{
    Student *stu = (Student *)dest;
    double english = *(double *)src;
    stu->english = english;
}

// 修改学号
void alter_id(unsigned int old_id)
{
    printf("请输入新的学号: ");
    unsigned int new_id;
    scanf("%u", &new_id);
    alter_all(list, &new_id, &old_id, cmp_by_id, opt_id);
}

void alter_name(unsigned int old_id)
{
    printf("请输入新的姓名: ");
    char name[64];
    scanf("%s", name);
    alter_all(list, name, &old_id, cmp_by_id, opt_name);
}

void alter_class(unsigned int old_id)
{
    printf("请输入新的班级: ");
    char cls[64];
    scanf("%s", cls);
    alter_all(list, cls, &old_id, cmp_by_id, opt_class);
}

void alter_c_score(unsigned int old_id)
{
    printf("请输入新的C语言成绩: ");
    double c_score;
    scanf("%lf", &c_score);
    alter_all(list, &c_score, &old_id, cmp_by_id, opt_c_score);
}

void alter_math(unsigned int old_id)
{
    printf("请输入新的数学成绩: ");
    double math;
    scanf("%lf", &math);
    alter_all(list, &math, &old_id, cmp_by_id, opt_math);
}

void alter_english(unsigned int old_id)
{
    printf("请输入新的英语成绩: ");
    double english;
    scanf("%lf", &english);
    alter_all(list, &english, &old_id, cmp_by_id, opt_english);
}

void chg_id(char *name)
{
    printf("请输入新的学号: ");
    unsigned int id;
    scanf("%u", &id);
    alter_all(list, &id, name, cmp_by_name, opt_id);
}

void chg_name(char *name)
{
    printf("请输入新的姓名: ");
    char new_name[64];
    scanf("%s", new_name);
    alter_all(list, new_name, name, cmp_by_name, opt_name);
}

void chg_class(char *name)
{
    printf("请输入新的班级: ");
    char new_class[64];
    scanf("%s", new_class);
    alter_all(list, new_class, name, cmp_by_name, opt_class);
}
void chg_c_score(char *name)
{
    printf("请输入新的C语言成绩: ");
    double new_c_score;
    scanf("%lf", &new_c_score);
    alter_all(list, &new_c_score, name, cmp_by_name, opt_c_score);
}

void chg_math(char *name)
{
    printf("请输入新的数学成绩: ");
    double new_math;
    scanf("%lf", &new_math);
    alter_all(list, &new_math, name, cmp_by_name, opt_math);
}

void chg_english(char *name)
{
    printf("请输入新的英语成绩: ");
    double new_english;
    scanf("%lf", &new_english);
    alter_all(list, &new_english, name, cmp_by_name, opt_english);
}

void chg_whole(char *name)
{
    system("clear");
    printf("请移步到主菜单先删除再录入新的数据^_^\n");
    sleep(3);
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
        fprintf(fp, "%-10u %-10s %-10s %6.2lf %6.2lf %6.2lf\n", stu->id, stu->name, stu->cls, stu->c_score, stu->math, stu->english);
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
        exit(1);
    }

    int size;
    fscanf(fp, "学生人数: %u\n", &size);

    for (int i = 0; i < size; i++)
    {
        Student stu;
        fscanf(fp, "%u%s%s%lf%lf%lf\n", &stu.id, stu.name, stu.cls, &stu.c_score, &stu.math, &stu.english);
        push_back(list, &stu);
    }

    fclose(fp);
}

void travel_student()
{
    for_each(list, print);
}

void print(void *data)
{
    Student stu = *(Student *)data;
    printf("| %-14u| %-s    \t| %-s    \t| %-12.2lf\t| %-12.2lf\t| %-12.2lf\t|\n", stu.id, stu.name, stu.cls, stu.c_score, stu.math, stu.english);
}

void flush_input()
{
    int ch;
    while ((ch = getchar()) != ' ' && ch != '\n')
        ;
}

void show_menu()
{
    printf("+------------------------------------------+\n"
           "|         \033[36m欢迎使用学生信息管理系统\033[0m         |\n"
           "+------------------------------------------+\n\n"

           "+------------------------------------------+\n"
           "|                  \033[33m功能列表\033[0m                |\n"
           "+------------------------------------------+\n"
           "|               1.录入学生信息             |\n"
           "|               2.删除学生信息             |\n"
           "|               3.查找学生信息             |\n"
           "|               4.修改学生信息             |\n"
           "|               5.浏览学生信息             |\n"
           "|               6.保存学生信息             |\n"
           "|               7.加载学生信息             |\n"
           "|               0.退出系统                 |\n"
           "+------------------------------------------+\n"
           "|                \033[35m请输入选项\033[0m                |\n"
           "+------------------------------------------+\n(0~7):");
}

void delete_menu()
{
    printf("+------------------------------------------+\n"
           "|                  \033[33m功能列表\033[0m                |\n"
           "+------------------------------------------+\n"
           "|               1.根据学号删除             |\n"
           "|               2.根据姓名删除             |\n"
           "|               3.根据班级删除             |\n"
           "|               0.返回主菜单               |\n"
           "+------------------------------------------+\n"
           "|                \033[35m请输入选项\033[0m                |\n"
           "+------------------------------------------+\n(0~3):");
}

void search_menu()
{
    printf("+------------------------------------------+\n"
           "|                  \033[33m功能列表\033[0m                |\n"
           "+------------------------------------------+\n"
           "|               1.根据学号查找             |\n"
           "|               2.根据姓名查找             |\n"
           "|               3.根据班级查找             |\n"
           "|               0.返回主菜单               |\n"
           "+------------------------------------------+\n"
           "|                \033[35m请输入选项\033[0m                |\n"
           "+------------------------------------------+\n(0~3):");
}

void modify_menu()
{
    printf("+------------------------------------------+\n"
           "|                  \033[33m功能列表\033[0m                |\n"
           "+------------------------------------------+\n"
           "|               1.根据学号修改             |\n"
           "|               2.根据姓名修改             |\n"
           "|               0.返回主菜单               |\n"
           "+------------------------------------------+\n"
           "|                \033[35m请输入选项\033[0m                |\n"
           "+------------------------------------------+\n(0~2):");
}

void alter_menu()
{
    printf("+------------------------------------------+\n"
           "|                  \033[33m功能列表\033[0m                |\n"
           "+------------------------------------------+\n"
           "|               1.修改学号                 |\n"
           "|               2.修改姓名                 |\n"
           "|               3.修改班级                 |\n"
           "|               4.修改C语言成绩            |\n"
           "|               5.修改数学升级             |\n"
           "|               6.修改英语成绩             |\n"
           "|               7.修改所有信息             |\n"
           "|               0.返回上一级菜单           |\n"
           "+------------------------------------------+\n"
           "|                \033[35m请输入选项\033[0m                |\n"
           "+------------------------------------------+\n(0~7):");
}
