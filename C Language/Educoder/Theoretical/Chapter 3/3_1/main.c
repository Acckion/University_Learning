/*第1关：两整数高低字节组合成一个新整数
任务描述
本关任务：程序填空，写一个表达式，将short类型整数k的高字节作为结果的低字节，将short类型整数p的低字节作为结果的高字节，拼成一个新short类型整数。例如：
输入k的值：  -32768（对应二进制为10000000 00000000）；
输入p的值： 128      （对应二进制为00000000 10000000）；
表达式的值：-32640 （对应二进制为10000000 10000000）。

相关知识
为了完成本关任务，你需要掌握：

C语言基本数据类型的长度；
C语言运算符及其优先级。
编程要求
根据提示，在右侧编辑器Begin-End中，使用变量k和p写出一个表达式，表达式的值满足任务要求。

测试说明
平台会对你编写的代码进行测试：

测试输入： 256 1       （输入的是k和p的值）
预期输出： 257        （输出的是计算出的表达式值）

测试输入： 123 321
预期输出： 16640

开始你的任务吧，Showtime！*/

#include <stdio.h>
int main(int argc, char *argv[])
{
    short k, p, result;
    scanf("%hd%hd", &k, &p);
    result = (
#include "expression.h"
    );
    printf("%hd", result);
    return 0;
}