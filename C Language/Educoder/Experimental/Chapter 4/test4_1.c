/*斐波那契级数
任务描述
教材P108 跟踪调试第（1）题。
本关任务：求斐波那契级数前n项的和。
题目要求详见教材，线下完成跟踪调试任务后，提交最后一问的程序(去掉原题中的输入提示语句)进行评测,注意题目要求，要用递归，不能用循环，否则计0分。

测试说明
平台会对你编写的代码进行测试：

测试输入：5
预期输出：
12

开始你的任务吧，祝你成功！*/

#include <stdio.h>

unsigned long long fabonacci(int n, unsigned long long first, unsigned long long second);

int main(void)
{
    int i, k;

    unsigned long long sum = 0;
    printf("Input n:");
    scanf("%d", &k);

    for (i = 1; i <= k; i++)
    {
        sum += fabonacci(i, 1, 1);
        printf("i=%d\tthe sum is %llu\n", i, sum);
    }
    return 0;
}

unsigned long long fabonacci(int n, unsigned long long first, unsigned long long second)
{
    if (n <= 1)
        return first;
    else
        return fabonacci(n - 1, second, first + second);
}