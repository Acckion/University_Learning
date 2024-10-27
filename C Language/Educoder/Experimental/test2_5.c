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

int main()
{
    unsigned short x; // 输入的无符号短整数
    int m, n;         // 位的位置和提取的位数

    scanf("%hu", &x);
    scanf("%d", &m);
    scanf("%d", &n);

    // 检查 m 和 n 的范围
    if (m < 0 || m > 15 || n < 1 || n > 16 - m)
    {
        printf("m 和 n 的值超出范围！\n");
        return 1;
    }

    // 提取从第 m 位开始的 n 位
    unsigned short mask = ((1 << n) - 1) << m; // 创建掩码
    unsigned short result = (x & mask) >> m;   // 提取指定位并右移

    // 确保高位保持齐
    result |= (1 << (n - 1)); // 将高位设置为 1

    // 输出结果
    printf("结果: 0x%04X\n", result);

    return 0;
}