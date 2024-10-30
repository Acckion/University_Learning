/*程序修改替换（2）
任务描述
本关任务：实验教材P85 程序修改替换第（2）题
修改第一关的代码，将for循环改用do-while循环

编程要求
根据提示，在右侧编辑器按要求修改代码。

测试说明
平台会对你编写的代码进行测试：

测试输入：4；
预期输出：4是合数

测试输入：5；
预期输出：5不是合数

开始你的任务吧，祝你成功！*/

#include <stdio.h>
int main()
{
    int i, x, k, flag = 0;
    //	printf("本程序判断合数，请输入大于1的整数，以Ctrl+Z结束\n");
    while (scanf("%d", &x) != EOF)
    {
        flag = 0;
        if (x <= 2)
            ;
        else
        {
            i = 2, k = x / 2;
            do
            {
                if (x % i == 0)
                {
                    flag = 1;
                    break;
                }
                i++;
            } while (i <= k);
        }
        if (flag == 1)
            printf("%d是合数", x);
        else
            printf("%d不是合数", x);
    }
    return 0;
}