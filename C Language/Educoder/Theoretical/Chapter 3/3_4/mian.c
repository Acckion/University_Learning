/*求三个数中最大值
任务描述
本关任务：代码填空，写一个表达式，求整数a，b，c三个数中最大值。

相关知识
为了完成本关任务，你需要掌握：

C语言三目运算符（? : ）。
编程要求
根据提示，在右侧编辑器Begin-End填写表达式，表达式的值等于三个数中的最大值。

测试说明
平台会对你编写的代码进行测试：

测试输入：1 2 3
预期输出：3

开始你的任务吧，Showtime！*/

#include <stdio.h>

int main()
{
    int a, b, c, max;
    scanf("%d%d%d", &a, &b, &c);
    max = (
#include "expression.h"
    );
    printf("%d", max);
    return 0;
}