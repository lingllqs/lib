#ifndef SMS_H
#define SMS_H

#include "list.h"

typedef struct Student
{
    unsigned int id; // 学号
    char name[64];   // 姓名
    char cls[64];    // 班级
    double c_score;  // C语言成绩
    double math;     // 高等数学成绩
    double english;  // 英语成绩
} Student;

void run();         // 运行系统
void main_menu();   // 主菜单
void delete_menu(); // 删除菜单
void search_menu(); // 查找菜单
void modify_menu(); // 修改菜单
void alter_menu();  // 修改子菜单

void add_student();    // 录入学生信息
void delete_student(); // 删除学生信息
void search_student(); // 查找学生信息
void modify_student(); // 修改学生信息
void travel_student(); // 浏览学生信息

int cmp_by_id(void *dest, void *src);    // 根据学号比较
int cmp_by_name(void *dest, void *src);  // 根据姓名比较
int cmp_by_class(void *dest, void *src); // 根据班级比较

void delete_by_id();    // 根据学号删除
void delete_by_name();  // 根据姓名删除
void delete_by_class(); // 根据班级删除

void search_by_id();    // 根据学号查找
void search_by_name();  // 根据姓名查找
void search_by_class(); // 根据班级查找

void modify_by_id();   // 查找学号修改
void modify_by_name(); // 查找姓名修改

void opt_id(void *dest, void *src);      // 修改学号
void opt_name(void *dest, void *src);    // 修改姓名
void opt_class(void *dest, void *src);   // 修改班级
void opt_c_score(void *dest, void *src); // 修改C语言成绩
void opt_math(void *dest, void *src);    // 修改数学成绩
void opt_english(void *dest, void *src); // 修改英语成绩

void alter_id(unsigned int old_id);
void alter_name(unsigned int old_id);
void alter_class(unsigned int old_id);
void alter_c_score(unsigned int old_id);
void alter_math(unsigned int old_id);
void alter_english(unsigned int old_id);
void alter_whole(unsigned int old_id);

void chg_id(char *name);
void chg_name(char *name);
void chg_class(char *name);
void chg_c_score(char *name);
void chg_math(char *name);
void chg_english(char *name);
void chg_whole(char *name);

void save_student();
void load_student();

void print(void *data);

void flush_input();

#endif // !SMS_H
#define SMS_H
