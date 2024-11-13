#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char stunum[20];
    char name[10];
    int eng;
    int math;
    int phy;
    int lanc;
    int sum;
    float average;
    struct student *next;
};
struct student *tail = NULL;

struct student *inputInfo(struct student *);
void printInfo(struct student *);
void changeInfo(struct student *);
void cacuAverage(struct student *);
void printAverage(struct student *);

int main()
{
    struct student *p = NULL; // 创建一个链表

    int choice; // 选择菜单
    //printf("选择菜单\n");
    scanf("%d", &choice);
    while (choice)
    {
        switch (choice)
        {
        case 1:
            p = inputInfo(p);
            break;
        case 2:
            printInfo(p);
            break;
        case 3:
            changeInfo(p);
            break;
        case 4:
            cacuAverage(p);
            break;
        case 5:
            printAverage(p);
            break;
        }
        //printf("选择菜单\n");
        scanf("%d", &choice);
    }
    return 0;
}

struct student *inputInfo(struct student *stu) // 填入链表
{
    int count;
    scanf("%d", &count);

    struct student *p = NULL;

    for (int i = 0; i < count; i++)
    {
        p = (struct student *)malloc(sizeof(struct student));
        if (p == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }

        // 输入学生信息
        scanf("%s", p->stunum);
        scanf("%s", p->name);
        scanf("%d", &p->eng);
        scanf("%d", &p->math);
        scanf("%d", &p->phy);
        scanf("%d", &p->lanc);
        p->sum = p->eng + p->math + p->phy + p->lanc;
        p->average = p->sum / 4.0;
        p->next = NULL;

        if (stu == NULL)
        {
            stu = p;
        }
        else
        {
            tail->next = p;
        }

        tail = p;
    }

    return stu;
}

void printInfo(struct student *stu)
{
    struct student *head = stu;
    while (head != NULL)
    {
        printf("%s ", head->stunum);
        printf("%s ", head->name);
        printf("%d ", head->eng);
        printf("%d ", head->math);
        printf("%d ", head->phy);
        printf("%d\n", head->lanc);
        head = head->next;
    }
}

void cacuAverage(struct student *stu)
{
    struct student *head = stu;
    while (head != NULL)
    {
        head->sum = head->eng + head->math + head->phy + head->lanc;
        head->average = head->sum / 4.0;
        printf("%s ", head->stunum);
        printf("%s ", head->name);
        printf("%.2f\n", head->average);
        head = head->next;
    }
}

void printAverage(struct student *stu)
{
    struct student *head = stu;
    while (head != NULL)
    {
        printf("%s ", head->stunum);
        printf("%s ", head->name);
        printf("%d ", head->sum);
        printf("%.2f\n", head->average);
        head = head->next;
    }
}

void changeInfo(struct student *stu)
{
    char stunum[20];
    int subj, score;
    //printf("输入要修改的学号,科目,分数");
    scanf("%s %d %d", stunum, &subj, &score); // 输入要修改的学号，科目（1英语，2数学，3物理，4C语言），目标分数

    struct student *head = stu;
    while (head != NULL)
    { // 遍历（到达链表尾部结束）
        if (strcmp(stunum, head->stunum) == 0)
        { // 学号相匹配
            switch (subj) { //修改分数
                case 1:
                    head->eng = score;
                    break;
                case 2:
                    head->math = score;
                    break;
                case 3:
                    head->phy = score;
                    break;
                case 4:
                    head->lanc = score;
                    break;
            }
            head->sum = head->eng + head->math + head->phy + head->lanc;
            head->average = head->sum / 4.0;
        }
        head = head->next;  //下一个
    }
}