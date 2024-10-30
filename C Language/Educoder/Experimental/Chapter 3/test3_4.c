/*纯粹合数求解器
任务描述
本关任务：实验教材P85 程序修改替换第（3）题
编写一个能求出所有n(2=<n=<4)位数纯粹合数的小程序。

相关知识
一个合数去掉最低位，剩下的数还是合数；再去掉剩下的数的最低位，余留下来的数还是合数，这样反复，一直到最后剩下的一位数仍是合数，这样的数称为纯粹合数。

编程要求
根据提示，在右侧编辑器补充代码，计算并输出所有的n位纯粹合数。

测试说明
平台会对你编写的代码进行测试：

测试输入：2;
预期输出：40 42 44 45 46 48 49 60 62 63 64 65 66 68 69 80 81 82 84 85 86 87 88 90 91 92 93 94 95 96 98 99;

提示：
参考上一题判断合数的方法

开始你的任务吧，祝你成功！*/

#include <stdio.h>
#include <math.h>

int isComposite(int x)
{
    if (x <= 2)
        return 0;
    else
    {
        for (int i = 2; i <= x / 2; i++)
        {
            if (x % i == 0)
                return 1;
        }
        return 0;
    }
}

int main()
{
    int n, temp;
    scanf("%d", &n);
    for (int i = pow(10, n - 1); i < pow(10, n); i++)
    {
        temp = i;
        while (isComposite(temp))
        {
            if (temp / 10 == 0)
            {
                printf("%d ", i);
                break;
            }
            else
            {
                temp /= 10;
            }
        }
    }
    return 0;
}