/*二分查找
任务描述
实验指导书 P142 程序设计第（3）题
本关任务：对第（2）题的程序增加查找功能（功能编号4）：输入一个C语言课程成绩值，用二分查找进行搜索。如果查找到有该成绩，则输出该成绩所有学生的姓名和C语言课程的成绩；否则，输出提示"not found"。

示例
输入：
依次输入功能编号1，学生数量n，每个学生的姓名和成绩，功能编号2，二分查找4，查找的成绩x：
1
3
xiaoming 90
xiaohong 79
zhangsan 83
2
4 90
0
输出：（如果有多个，一行一个学生；如果有相同分数，按照姓名字母排序输出）
xiaoming 90

开始你的任务吧，祝你成功！*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10
#define MAX_STUDENT 100

void input(char sheet[][2][MAX_LENGTH], int *n);
void sort(char sheet[][2][MAX_LENGTH], int n);
void output(char sheet[][2][MAX_LENGTH], int n);
void found(char sheet[][2][MAX_LENGTH], int a, int b, int x);

int main()
{
    char sheet[MAX_STUDENT][2][MAX_LENGTH];
    int slect = 0;
    int n = 0;

    while (1)
    {
        // printf("选择菜单");
        scanf("%d", &slect);
        switch (slect)
        {
        case 0:
        { // input
            return 0;
        }
        case 1:
        { // input
            input(sheet, &n);
            break;
        }
        case 2:
        { // sort
            sort(sheet, n);
            break;
        }
        case 3:
        { // output
            output(sheet, n);
            break;
        }
        case 4:
        { // found
            int x;
            scanf("%d", &x);
            found(sheet, 0, n, x);
            break;
        }
        }
    }
    return 0;
}

void input(char sheet[][2][MAX_LENGTH], int *n)
{
    scanf("%d", n);
    for (int i = 0; i < *n; i++)
    {
        scanf("%s %s", sheet[i][0], sheet[i][1]);
    }
    // printf("完成");
}

void sort(char sheet[][2][MAX_LENGTH], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(sheet[j][1], sheet[j + 1][1]) < 0)
            {
                char temp[2][MAX_LENGTH];
                strcpy(temp[0], sheet[j][0]);
                strcpy(temp[1], sheet[j][1]);
                strcpy(sheet[j][0], sheet[j + 1][0]);
                strcpy(sheet[j][1], sheet[j + 1][1]);
                strcpy(sheet[j + 1][0], temp[0]);
                strcpy(sheet[j + 1][1], temp[1]);
            }
            else if (strcmp(sheet[j][1], sheet[j + 1][1]) == 0)
            {
                if (strcmp(sheet[j][0], sheet[j + 1][0]) > 0)
                {
                    char temp[2][MAX_LENGTH];
                    strcpy(temp[0], sheet[j][0]);
                    strcpy(temp[1], sheet[j][1]);
                    strcpy(sheet[j][0], sheet[j + 1][0]);
                    strcpy(sheet[j][1], sheet[j + 1][1]);
                    strcpy(sheet[j + 1][0], temp[0]);
                    strcpy(sheet[j + 1][1], temp[1]);
                }
            }
        }
    }
}

void output(char sheet[][2][MAX_LENGTH], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s %s\n", sheet[i][0], sheet[i][1]);
    }
}

void found(char sheet[][2][MAX_LENGTH], int a, int b, int x)
{
    if (x == atoi(sheet[(a + b) / 2][1]))
    {
        int result;
        result = (a + b) / 2;
        while (x == atoi(sheet[--result][1]))
            ;
        while (x == atoi(sheet[++result][1]))
            printf("%s %s\n", sheet[result][0], sheet[(a + b) / 2][1]);
    }
    if ((a + b) / 2 == a || (a + b) / 2 == b)
    {
        printf("not found");
        return;
    }
    if (x > atoi(sheet[(a + b) / 2][1]))
        found(sheet, (a + b) / 2, b, x);
    if (x < atoi(sheet[(a + b) / 2][1]))
        found(sheet, a, (a + b) / 2, x);
}