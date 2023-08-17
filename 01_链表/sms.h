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

void save_student();
void load_student();

void print(void *data);

#endif // !SMS_H
#define SMS_H
