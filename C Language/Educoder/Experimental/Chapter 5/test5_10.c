/*消除类游戏
任务描述
实验指导书 P143 程序设计第（6）题
本关任务：消除类游戏是一种益智游戏，其核心规则是将一定的彼此相邻的相同元素配对消除。现给定一个n行m列的棋盘，棋盘中的每一个方格上放着一个棋子，每个棋子都有颜色，编号用1~9表示。当一行或一列上有连续3个或3个以上同色棋子时，这些棋子都被同时消除，对应的方格用0表示，请输出经过消除后的棋盘。例如，给定棋盘为：
4 4 3 1 4
3 1 1 1 1
4 3 4 1 2
4 4 2 2 2
消除后为：
4 4 3 0 4
3 0 0 0 0
4 3 4 0 2
4 4 0 0 0

示例
输入（输入的前两个数字为棋盘的行数和列数）：
4 5
4 4 3 1 4
3 1 1 1 1
4 3 4 1 2
4 4 2 2 2
输出（同行每个元素之间以空格分隔）：
4 4 3 0 4
3 0 0 0 0
4 3 4 0 2
4 4 0 0 0

开始你的任务吧，祝你成功！*/

#include <stdio.h>

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    int sheet[x][y];
    int toDelete[x][y];
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            scanf("%d", &sheet[i][j]);
            toDelete[i][j] = 0;
        }
    } // 构建棋盘

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            int temp = sheet[i][j];
            int n;
            for (n = 1; sheet[i][j + n] == temp && j + n < y; n++)
                ;
            if (n >= 3)
            {
                for (int k = 0; k < n; k++)
                {
                    toDelete[i][j + k] = 1;
                }
            }
        }
    } // 横向扫描

    for (int j = 0; j < y; j++)
    {
        for (int i = 0; i < x; i++)
        {
            int temp = sheet[i][j];
            int n;
            for (n = 1; sheet[i + n][j] == temp && i + n < x; n++)
                ;
            if (n >= 3)
            {
                for (int k = 0; k < n; k++)
                {
                    toDelete[i + k][j] = 1;
                }
            }
        }
    } // 纵向扫描

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (toDelete[i][j] == 1)
            {
                sheet[i][j] = 0;
            }

            printf("%d", sheet[i][j]);
            if (j < y - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    } // 输出

    return 0;
}