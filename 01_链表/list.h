#ifndef LIST_H
#define LIST_H

#include <stdio.h>

/* 错误处理宏 */
#define ERRP(condition, message, process)                                                                              \
    do                                                                                                                 \
    {                                                                                                                  \
        if (condition)                                                                                                 \
        {                                                                                                              \
            fprintf(stderr, #message " false!");                                                                       \
            process;                                                                                                   \
        }                                                                                                              \
    } while (0);

// 结点
typedef struct Node
{
    void *data;        // 数据
    struct Node *prev; // 前一个结点
    struct Node *next; // 后一个结点
} Node;

// 链表
typedef struct List
{
    unsigned int type_size; // 数据类型大小
    unsigned int size;      // 结点个数
    struct Node *front;     // 第一个结点
    struct Node *end;       // 最后一个结点
} List;

typedef int (*CMP)(void *dest, void *src);  // 比较
typedef void (*OPT)(void *dest, void *src); // 修改
typedef void (*PRI)(void *data);            // 打印

Node *node_new(void *data, unsigned int data_size); // 新建一个结点
List *list_new(unsigned int type_size);             // 新建一个链表

int push_head(List *list, void *data); // 头插法
int push_back(List *list, void *data); // 尾插法

int pop_head(List *list);                      // 头删法
int pop_back(List *list);                      // 尾删法
int pop_index(List *list, unsigned int index); // 根据索引删除
int pop_key(List *list, void *key, CMP cmp);   // 根据关键字删除

Node *find_first(List *list, void *key, CMP cmp, PRI pri); // 查找第一个找到的结点
Node *find_last(List *list, void *key, CMP cmp, PRI pri);  // 查找最后一个找到的结点
List *find_all(List *list, void *key, CMP cmp, PRI pri);   // 查找所有符合的结点

int alter_first(List *list, void *new_data, void *key, CMP cmp, OPT opt); // 修改第一个找的数据
int alter_last(List *list, void *new_data, void *key, CMP cmp, OPT opt);  // 修改最后一个找的数据
int alter_all(List *list, void *new_data, void *key, CMP cmp, OPT opt);   // 修改所有符合的数据

void save(List *list, const char *path); // 保存
List *load(const char *path);            // 加载

void for_each(List *list, PRI print); // 遍历链表
void list_destroy(List *list);        // 销毁链表
void node_destroy(Node *node);        // 销毁结点

#endif // !LIST_H
