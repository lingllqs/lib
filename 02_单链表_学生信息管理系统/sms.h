#ifndef SMS_H
#define SMS_H

typedef struct Node
{
    int id;            // 学号
    char name[64];     // 姓名
    char sex[8];       // 性别
    double math;       // 数学
    double english;    // 英语
    double computer;   // 计算机
    double average;    // 平均成绩
    struct Node *next; // 指向下一个结点指针
} Node;

#endif // !sms_h
