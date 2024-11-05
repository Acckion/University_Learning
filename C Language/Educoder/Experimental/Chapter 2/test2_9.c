/*数据加密
任务描述
本关任务：实验教材P64 程序设计第(13) 题
         输入一行明文字符串，按题中算法进行加密后输出密文。

测试说明
平台会对你编写的代码进行测试：

测试输入：
abcd
预期输出：
dbfp
*/

#include <stdio.h>
#include <math.h>

int main()
{
    char real[100];
    scanf("%s", real);
    for (int i = 0; i <= 101; i++)
    {
        if (real[i] != 0)
        {
            char temp1 = (((real[i] & 0x2a) >> 1) | ((real[i] & 0x15) << 1)); // 0,2,4与1,3,5位交换
            real[i] = (real[i] & 0xc0) | ((temp1 << (int)((real[i] & 0xc0) >> 6) & 0x3f) | (temp1 >> (int)(6 - ((real[i] & 0xc0) >> 6)) & 0x3f));
        }
    }
    printf("%s", real);
    return 0;
}