/*成绩排序
任务描述
实验指导书 P142 程序设计第（2）题
本关任务：编写一个C程序，要求采用模块化设计思想，将相关功能用函数实现，并提供菜单选项，每次程序运行结束后需通过功能0退出程序。该程序具有以下功能：

退出程序；
输入n个学生的姓名和C语言课程的成绩；
将成绩按从高到低的次序排序，姓名同时进行相应调整（成绩相同的按姓名首字母排序，首字母相同的按第二个字母排序，依次类推）；
输出所有学生的姓名和C语言课程的成绩。
示例
输入1：
依次输入功能编号1，学生数量n，每个学生的姓名和成绩，功能编号3：
1          (功能编号)
3          (学生人数)
xiaoming 90   (学生姓名和成绩)
xiaohong 79
zhangsan 83
3               (功能编号)
0                (功能编号)
输出1：
xiaoming 90
xiaohong 79
zhangsan 83

输入2：
依次输入功能编号1，学生数量n，每个学生的姓名和成绩，功能编号2，功能编号3：
1          (功能编号)
3          (学生人数)
xiaoming 79   (学生姓名和成绩)
xiaohong 79
zhangsan 83
2   (功能编号，成绩相同的按姓名排序)
3   (功能编号)
0       (功能编号)

输出2：
zhangsan 83
xiaohong 79
xiaoming 79
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10
#define MAX_STUDENT 100

void input(char sheet[][2][MAX_LENGTH], int *n);
void sort(char sheet[][2][MAX_LENGTH], int n);
void output(char sheet[][2][MAX_LENGTH], int n);

int main()
{
    char sheet[MAX_STUDENT][2][MAX_LENGTH];
    int slect = 0;
    int n = 0;

    while (1)
    {
        //printf("选择菜单");
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
    //printf("完成");
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