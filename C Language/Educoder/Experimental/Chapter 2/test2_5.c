/*取出一个整数的连续若干位
任务描述
本关任务：实验教材P63 程序设计第(5)题
取出x从第ｍ位开始向左的ｎ位。

测试说明
平台会对你编写的代码进行测试：

测试输入：
4 2 1
预期输出：(以十六进制输出)
8000


*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[20];
    unsigned short x; // 输入的无符号短整数
    int m, n;         // 位的位置和提取的位数

    scanf("%s", a);
    scanf("%d", &m);
    scanf("%d", &n);

    x = (unsigned short)strtoul(a, NULL, 16);

    x = ((x >> m) << (16 - n));
    printf("%04X", x);
}