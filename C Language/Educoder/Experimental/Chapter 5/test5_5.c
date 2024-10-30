/*解约瑟夫问题（改进）
任务描述
实验指导书P142 约瑟夫问题第（2）问
本关任务：改进实验指导书P142的求解约瑟夫问题的源程序，采用标记元素而非压缩数组的方法记录出圈者。

示例
输入（第一个数位为M，第二个数为N）：
5 3
输出：（仅输出最后留在圈中人的编号）
4

开始你的任务吧，祝你成功！*/

#include <stdio.h>

void joseph(int m, int n);

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    joseph(m, n);
    return 0;
}

void joseph(int m, int n)
{
    int list[m];
    for (int i = 0; i < m; i++)
    {
        list[i] = 0;
    }
    int count = 0;
    int out = 0;
    for (int i = 0;; i++)
    {
        i %= m;
        if (list[i] == 0)
        {
            count++;
            if (count == n)
            {
                list[i] = 1;
                out++;
                printf("%d      ", i + 1);
                count = 0;
            }
        }
        if (out == m - 1)
            break;
    }
    for (int i = 0; i < m; i++)
    {
        if (list[i] == 0)
        {
            printf("\n%d", i + 1);
            break;
        }
    }
}
