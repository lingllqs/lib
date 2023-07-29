#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *node_new(void *data, unsigned int data_size)
{
    Node *new_node = (Node *)calloc(sizeof(Node), 1);
    ERRP(new_node == NULL, calloc new_node, goto ERR1);

    new_node->data = (void *)calloc(data_size, 1);
    ERRP(new_node->data == NULL, calloc data, goto ERR2);

    memcpy(new_node->data, data, data_size);
    new_node->prev = new_node->next = NULL;

    return new_node;

ERR2:
    free(new_node);
    new_node = NULL;
ERR1:
    return NULL;
}

List *list_new(unsigned int type_size)
{
    List *new_list = (List *)calloc(sizeof(List), 1);
    ERRP(new_list == NULL, calloc new list, goto ERR1);

    new_list->front = new_list->end = NULL;
    new_list->size = 0;
    new_list->type_size = type_size;

    return new_list;

ERR1:
    return NULL;
}

int push_head(List *list, void *data)
{
    ERRP(list == NULL || data == NULL, push_head, return -1);

    Node *new_node = node_new(data, list->type_size);

    if (list->size == 0)
    {
        list->front = list->end = new_node;
    }
    else
    {
        new_node->next = list->front;
        list->front->prev = new_node;
        list->front = new_node;
    }

    list->size++;
    return 0;
}

int push_back(List *list, void *data)
{
    ERRP(list == NULL || data == NULL, push_back, return -1);

    Node *new_node = node_new(data, list->type_size);

    if (list->size == 0)
    {
        list->front = list->end = new_node;
    }
    else
    {
        new_node->prev = list->end;
        list->end->next = new_node;
        list->end = new_node;
    }

    list->size++;
    return 0;
}

int pop_head(List *list)
{
    ERRP(list == NULL || list->size == 0, pop_head, return -1);

    Node *p = list->front;
    if (list->size == 1)
    {
        list->front = list->end = NULL;
    }
    else
    {
        list->front = p->next;
        list->front->prev = NULL;
    }

    node_destroy(p);
    list->size--;
    return 0;
}

int pop_back(List *list)
{
    ERRP(list == NULL || list->size == 0, pop_back, return -1);

    Node *p = list->end;
    if (list->size == 1)
    {
        list->front = list->end = NULL;
    }
    else
    {
        list->end = p->prev;
        list->end->next = NULL;
    }

    node_destroy(p);
    list->size--;
    return 0;
}

int pop_index(List *list, unsigned int index)
{
    if (!list || index < 0 || index >= list->size)
        return -1;

    if (index == 0)
    {
        pop_head(list);
    }
    else if (index == list->size - 1)
    {
        pop_back(list);
    }
    else
    {
        Node *p = list->front;
        unsigned int count = index;
        while (count--)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;

        node_destroy(p);
        list->size--;
    }

    return 0;
}

int pop_key(List *list, void *key, CMP cmp)
{
    if (!list || list->size == 0)
        return -1;

    Node *p = list->front;
    Node *pn;
    int i = 0;
    while (p)
    {
        pn = p->next;
        if (cmp(p->data, key) == 0)
        {
            pop_index(list, i);
            i = 0;
        }
        else
        {
            i++;
        }
        p = pn;
    }

    return 0;
}

Node *find_first(List *list, void *key, CMP cmp, PRI pri)
{
    ERRP(list == NULL || key == NULL, search_key, return NULL);

    int i;
    Node *p = list->front;
    for (i = 0; i < list->size; i++)
    {
        if (cmp(p->data, key) == 0)
        {
            if (pri)
                pri(p->data);
            return p;
        }
        p = p->next;
    }

    return p;
}

Node *find_last(List *list, void *key, CMP cmp, PRI pri)
{
    ERRP(list == NULL || key == NULL, search_key, return NULL);

    int i;
    Node *p = list->end;
    for (i = 0; i < list->size; i++)
    {
        if (cmp(p->data, key) == 0)
        {
            if (pri)
                pri(p->data);
            return p;
        }
        p = p->prev;
    }

    return p;
}

List *find_all(List *list, void *key, CMP cmp, PRI pri)
{
    ERRP(list == NULL || key == NULL, search_key, return NULL);

    int i;
    Node *p = list->end;
    List *l = list_new(list->type_size);
    for (i = 0; i < list->size; i++)
    {
        if (cmp(p->data, key) == 0)
        {
            push_back(l, p->data);
            if (pri)
                pri(p->data);
        }
        p = p->prev;
    }

    return l;
}

// list: 要操作的链表
// data: 新的数据
// key: 要查找的关键字
// cmp: 自定义比较方法
// opt: 自定义修改方法
int alter_first(List *list, void *new_data, void *key, CMP cmp, OPT opt)
{
    ERRP(list == NULL || new_data == NULL || key == NULL, alter, return -1);

    int i;
    Node *p = list->front;
    for (i = 0; i < list->size; i++)
    {
        if (cmp(p->data, key) == 0)
        {
            opt(p->data, new_data);
            return 0;
        }
        p = p->next;
    }

    return 0;
}

//
int alter_last(List *list, void *new_data, void *key, CMP cmp, OPT opt)
{
    ERRP(list == NULL || new_data == NULL || key == NULL, alter, return -1);

    int i;
    Node *p = list->end;
    for (i = 0; i < list->size; i++)
    {
        if (cmp(p->data, key) == 0)
        {
            opt(p->data, new_data);
            return 0;
        }
        p = p->prev;
    }

    return 0;
}

// list: 要修改的链表
// new_data: 新数据
// key: 查找的关键字
// cmp: 比较方法(自定义),和参数key相关
// opt: 修改数据的方法(自定义),和参数new_data相关
int alter_all(List *list, void *new_data, void *key, CMP cmp, OPT opt)
{
    ERRP(list == NULL || new_data == NULL || key == NULL, alter, return -1);

    int i, count = 0;
    Node *p = list->end;
    for (i = 0; i < list->size; i++)
    {
        if (cmp(p->data, key) == 0)
        {
            count++;
            opt(p->data, new_data);
        }
        p = p->prev;
    }

    return count;
}

// list: 保存的链表
// path: 保存到的文件路径
void save(List *list, const char *path)
{
    FILE *fp = NULL;
    fp = fopen(path, "w+");
    ERRP(fp == NULL, fopen in function save, exit(1));

    fwrite(&list->type_size, sizeof(list->type_size), 1, fp);
    fwrite(&list->size, 1, sizeof(list->size), fp);

    int i;
    Node *p = list->front;
    for (i = 0; i < list->size; i++)
    {
        fwrite(p->data, 1, list->type_size, fp);
        p = p->next;
    }
    fclose(fp);
}

// path: 加载的文件路径
// 返回值: 返回一个加载后的链表
List *load(const char *path)
{
    FILE *fp = NULL;
    fp = fopen(path, "r");
    ERRP(fp == NULL, fopen in function load, exit(2));

    unsigned int type_size;
    unsigned int size;
    fread(&type_size, sizeof(unsigned int), 1, fp);
    fread(&size, sizeof(unsigned int), 1, fp);

    List *list = list_new(type_size);
    void *data = malloc(type_size);

    for (int i = 0; i < size; i++)
    {
        fread(data, type_size, 1, fp);
        push_back(list, data);
    }

    free(data);
    fclose(fp);

    return list;
}

// list: 要遍历的链表
// print: 遍历单个数据的方法(自定义)
void for_each(List *list, PRI print)
{
    ERRP(list == NULL, for_each, exit(1));

    int i;
    Node *p = list->front;
    for (i = 0; i < list->size; ++i)
    {
        print(p->data);
        p = p->next;
    }
}

void list_destroy(List *list)
{
    ERRP(list == NULL, list_destroy, exit(1));

    int i;
    Node *p = list->front;
    for (i = 0; i < list->size; ++i)
    {
        list->front = p->next;
        node_destroy(p);
        p = list->front;
    }

    list->front = list->end = NULL;
    free(list);
    list = NULL;
}

void node_destroy(Node *node)
{
    if (node)
    {
        if (node->data)
        {
            free(node->data);
            node->data = NULL;
        }
        node->prev = node->next = NULL;

        free(node);
        node = NULL;
    }
}
