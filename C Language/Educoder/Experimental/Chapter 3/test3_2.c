/*程序修改替换（1）
任务描述
本关任务：实验教材P85 程序修改替换第（1）题
修改第一关的代码，将内层两出口的for循环结构改用单出口结构，即不允许用break，goto等非结构化语句

编程要求
在右侧编辑器修改代码。

测试说明
平台会对你编写的代码进行测试：

平台会对你编写的代码进行测试：

测试输入：4；
预期输出：4是合数

测试输入：5；
预期输出：5不是合数

开始你的任务吧，祝你成功！*/

#include <stdio.h>
int main()
{
    int i, x, k, flag = 0;
    //	printf("本程序判断合数，请输入大于1的整数，以Ctrl+Z结束\n");
    while (scanf("%d", &x) != EOF)
    {
        flag = 0;
        if (x <= 2)
            ;
        else
        {
            for (i = 2, k = x / 2; i <= k; i++)
                if (x % i == 0)
                {
                    flag = 1;
                    continue;
                }
        }
        if (flag == 1)
            printf("%d是合数", x);
        else
            printf("%d不是合数", x);
    }
    return 0;
}