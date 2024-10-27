/*第几天
任务描述
本关任务：实验教材 1.5 实验一 第3题
输入某年某月某日，判断这一天是这一年的第几天（ P34）。

编程要求
认真阅读教材 P35 的实验步骤，学习断点调试和单步跟踪、观察变量值等程序调试方法。按步骤调试右侧代码框里程序，找出程序中的错误，使之输出正确结果。

测试说明
平台会对你编写的代码进行测试：

测试输入：
2000 3 1
预期输出：
It is the 61th day
*/

#include <stdio.h>

int main()
{
    int day, month, year, sum, leap, i;
    int mdays[12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    scanf("%d %d %d", &year, &month, &day);
    sum = 0;
    for (i = 0; i < month; i++)
    {
        sum += mdays[i];
    }
    sum = sum + day;

    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        leap = 1;
    else
        leap = 0;
    if (leap == 1 && month > 2)
        sum++;
    printf("It is the %dth day.", sum);
    return 0;
}