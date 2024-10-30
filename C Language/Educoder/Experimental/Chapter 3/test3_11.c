/*孪生素数
任务描述
本关任务：实验课本P86  程序设计第（10）题

用筛法构造素数表，输入m(4≤m≤1000000)，查表找出m之前的所有孪生素数。

相关知识
孪生素数
孪生素数是指距离为2的相邻素数，例如（3，5），（5，7）

筛法
筛法又称筛选法，具体做法是：先把N个自然数按次序排列起来。1不是质数，也不是合数，要划去。第二个数2是质数留下来，而把2后面所有能被2整除的数都划去。2后面第一个没划去的数是3，把3留下，再把3后面所有能被3整除的数都划去。3后面第一个没划去的数是5，把5留下，再把5后面所有能被5整除的数都划去。这样一直做下去，就会把不超过N的全部合数都筛掉，留下的就是不超过N的全部质数。

筛法程序步骤
<1> 先将1挖掉(因为1不是素数)。
<2> 用2去除它后面的各个数，把能被2整除的数挖掉，即把2的倍数挖掉。
<3> 用3去除它后面的各数，把3的倍数挖掉。
<4> 分别用5…各数作为除数去除这些数以后的各数。

编程要求
在右侧编辑器编辑程序代码，找出m之前所有的孪生素数。

测试说明
平台会对你编写的代码进行测试：

测试输入：50；
预期输出：(3,5) (5,7) (11,13) (17,19) (29,31) (41,43)

开始你的任务吧，祝你成功！*/

#include <stdio.h>

int main()
{
    int m;
    scanf("%d", &m);

    int primeList[m];
    for (int i = 0; i <= m; i++)
    {
        primeList[i] = 1;
    } // 初始化质数列表，默认都是质数
    primeList[0] = primeList[1] = 0;

    for (int i = 2; i <= m / 2; i++)
    { // 循环，控制素数
        if (primeList[i])
        {
            for (int k = 2; k * i <= m; k++)
            { // 循环，控制倍数
                primeList[i * k] = 0;
            }
        }
    }

    int lastPrime = 2;
    for (int i = 2; i <= m; i++)
    { // 循环，检测孪生素数
        if (primeList[i])
        {
            if (i - lastPrime == 2)
            {
                printf("(%d,%d) ", lastPrime, i);
            }
            lastPrime = i;
        }
    }

    return 0;
}