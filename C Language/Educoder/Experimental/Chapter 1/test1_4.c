/*完数
任务描述
本关任务：实验教材  1.5 实验一 第4题
找出1000内的所有完数（P36）。

编程要求
认真阅读教材 P37 的实验步骤，学习跟踪进函数、观察变量值等程序调试方法。按步骤调试右侧代码框里程序，找出程序中的错误，使之输出正确结果。
*/

#include <stdio.h>

int isPerfect(int x)
{
    int y, sum;
    for (sum = 0, y = 1; y <= x / 2; y++)
    {
        if ((x % y) == 0)
            sum += y;
    }
    if (sum == x)
        return 1;
    return 0;
}

int main()
{
    int a;
    for (a = 1; a <= 1000; a++)  
        if (isPerfect(a))
            printf("%d\n", a);
    return 0;
}
