/*n天股票最大波动值
任务描述
本关任务：实验课本P85  程序设计第（3）题
输入一直股票连续n天的收盘价格，输出该股票这n天中的最大波动值，波动值是指某天收盘价格与前一天收盘价格只差的绝对值。

编程要求
在右侧编辑器补充代码，使之满足任务描述。

测试说明
平台会对你编写的代码进行测试：

测试输入：
7
24 32 6 9 23 13 15;

开始你的任务吧，祝你成功！*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int stock[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &stock[i]);
    }

    int max = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int delta = stock[i + 1] - stock[i];
        delta = (delta > 0) ? (delta) : (-delta);

        if (delta > max)
            max = delta;
    }
    printf("%d", max);
    return 0;
}