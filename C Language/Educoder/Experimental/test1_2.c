/*字符数和行数
任务描述
本关任务：实验教材 1.5 实验一 第2题
输入一段正文，统计字符数和行数。

编程要求
认真阅读教材 P33 的实验步骤，学习断点调试和单步跟踪等程序调试方法。按步骤调试右侧代码框里程序，找出程序中的错误，使之输出正确结果。

测试说明
平台会对你编写的代码进行测试：

测试输入：   （↙代表回车）
Asd↙
xcvb↙
^+Z       （Ctrl+z结束输入）

预期输出：
字符数:9,行数:2
*/

#include <stdio.h>

int main(void)
{
    char c, numchar, numline;
    numchar = 0;
    numline = 0;
    while ((c = getchar()) != EOF)
    {
        numchar++;
        if (c == '\n')
            numline++;
    }
    printf("字符数:%d,", numchar);
    printf("行数:%d", numline);
    return 0;
}