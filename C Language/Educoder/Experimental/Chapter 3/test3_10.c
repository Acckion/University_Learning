/*梅森素数
任务描述
本关任务：实验课本P86  程序设计第（6）题
梅森数是形如2n-1的正整数，其中指数n是素数，记为M(n)。如果一个梅森数是素数，则称为梅森素数。例如，M(2)=22-1=3是梅森素数，而M(11)=211-1=2047=23×89不是梅森素数。
输入一个大于3的长整数m，输出不大于m的所有梅森素数。

编程要求
在右侧编辑器编辑代码，计算并输出不大于m的所有梅森素数。

测试说明
平台会对你编写的代码进行测试：

测试输入：97；
预期输出：
M(2)=3
M(3)=7
M(5)=31

开始你的任务吧，祝你成功！*/

#include <stdio.h>

int isPrime(int x);
int power(int x, int y);

int main()
{
    int max, result;
    scanf("%d", &max);

    for (int i = 1; (result = (power(2, i) - 1)) <= max; i++)
    {
        if (isPrime(i))
        {
            if (isPrime(result))
            {
                printf("M(%d)=%d\n", i, result);
            }
        }
    }
    return 0;
}

int isPrime(int x)
{
    if (x <= 1)
        return 0;
    else if (x == 2)
        return 1;
    else
    {
        for (int i = 2; i < x / 2; i++)
        {
            if (x % i == 0)
                return 0;
        }
        return 1;
    }
}

int power(int x, int y)
{
    int result = 1;
    for (int i = 0; i < y; i++)
    {
        result *= x;
    }
    return result;
}