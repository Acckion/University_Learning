/*调试计算圆面积
任务描述
教材P109跟踪调试第（4）题。
本关任务：调试计算圆面积。题目要求详见教材，线下完成跟踪调试任务后，提交满足任务要求程序(去掉原题中的输入提示语句)进行评测。要求必须使用断言，否则计0分。

测试说明
平台会对你编写的代码进行测试：

测试输入：100；
预期输出：
31416

开始你的任务吧，祝你成功！*/

#define R
#include <stdio.h>
#include <assert.h>
int integer_fraction(float x);
int main(void)
{
    float r, s;
    int s_integer = 0;
    int is质数;
    scanf("%f", &r);
#ifdef R
    s = 3.14159 * r * r;
    s_integer = integer_fraction(s);
    if ((s - s_integer) >= 0.5)
        s_integer += 1;
    printf("The integer fraction of area is %d\n", s_integer);
#endif
    return 0;
}

int integer_fraction(float x)
{
    int i = x;
    return i; 
}