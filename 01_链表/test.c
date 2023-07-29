#include "list.h"
#include <stdio.h>
#include <string.h>

struct data
{
    char name[64];
    int age;
};

// 打印数据的方法
void print(void *data)
{
    struct data *d = (struct data *)data;
    printf("%s %d\n", d->name, d->age);
}

// 根据age来比较
int cmp_age(void *dest, void *src)
{
    struct data *stu = (struct data *)dest;
    int age = *(int *)src;
    return (stu->age - age);
}

// 修改名字
void opt_name(void *dest, void *src)
{
    struct data *stu = (struct data *)dest;
    char *name = (char *)src;
    strcpy(stu->name, name);
}

int main()
{
    List *list = list_new(sizeof(struct data));
    struct data data1 = {"hello", 17};
    struct data data2 = {"world", 20};
    struct data data3 = {"Rust", 18};
    struct data data4 = {"Python", 17};
    struct data data5 = {"Cpp", 18};

    push_back(list, &data1);
    push_back(list, &data2);
    push_back(list, &data3);
    push_back(list, &data4);
    push_back(list, &data5);
    for_each(list, print);

    /* puts("\n删除后:"); */
    /* int key = 17; */
    /* pop_key(list, &key, cmp_age); */
    /* for_each(list, print); */

    /* puts("\n查找"); */
    /* int val = 18; */
    /* List *l = find_all(list, &val, cmp_age, NULL); */
    /* for_each(l, print); */
    /* list_destroy(l); */

    /* puts("\n修改"); */
    /* int val = 17; */
    /* int ret = alter_all(list, "nihao", &val, cmp_age, opt_name); */
    /* for_each(list, print); */

    /* save(list, "a.txt"); */
    list_destroy(list);

    /* puts("\n加载数据"); */
    /* List *load_list = load("a.txt"); */
    /* for_each(load_list, print); */
    /* list_destroy(load_list); */

    return 0;
}
