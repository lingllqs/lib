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

void run();
void show_menu();
void delete_menu();
void search_menu();
void modify_menu();
void alter_menu();
void chg_menu();

void add_student();
void delete_student();
void search_student();
void modify_student();
void travel_student();

int cmp_by_id(void *dest, void *src);
int cmp_by_name(void *dest, void *src);
int cmp_by_class(void *dest, void *src);

void delete_by_id();
void delete_by_name();
void delete_by_class();

void search_by_id();
void search_by_name();
void search_by_class();

void modify_by_id();
void modify_by_name();

void opt_id(void *dest, void *src);
void opt_name(void *dest, void *src);
void opt_class(void *dest, void *src);
void opt_c_score(void *dest, void *src);
void opt_math(void *dest, void *src);
void opt_english(void *dest, void *src);

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

#endif // !SMS_H
#define SMS_H
