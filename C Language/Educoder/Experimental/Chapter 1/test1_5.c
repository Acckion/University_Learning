/*最大的数字
任务描述
本关任务：实验教材  1.5 实验一 第5题
输入一个正整数，统计该数各位数字中零的个数，以及找出最大的数字。（P38）

编程要求
按教材 P38 的要求调试右侧代码框里程序，找出程序中的错误，使之输出正确结果。
*/

#include <stdio.h>
int main()
{
    int count, max, x, t;
    scanf("%d", &x);
    count = max = 0;
    while (x)
    {
        t = x % 10;
        if (t == 0)
            count++;
        if (t > max)
            max = t;
        x = x / 10;
    }
    printf("该数有%d个零,最大数字是%d\n", count, max);
    return 0;
}