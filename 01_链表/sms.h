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

void add_student(List *list);
void delete_student(List *list);
void search_student(List *list);
void modify_student(List *list);
void travel_student(List *list);

void print(void *data);

#endif // !SMS_H
#define SMS_H
