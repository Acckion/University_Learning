/*累加求和
任务描述
本关任务：输入正整数n，求s=1+2+3+4+...+n。

测试说明
平台会对你编写的代码进行测试：

测试输入：5
预期输出：15

测试输入：10
预期输出：55

开始你的任务吧，祝你成功！*/

#include <stdio.h>

int main()
{
    /**********  Begin  **********/
    int k = 1, n = 0, sum = 0;
    scanf("%d", &n);
    for (k = 1; k <= n; k++)
    {
        sum = sum + k;
    }
    printf("%d", sum);
    /**********  Begin  **********/
    return 0;
}
