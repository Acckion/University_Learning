/*IP地址
任务描述
本关任务：实验教材P63 程序设计第(6)题
读入无符号长整型数表示的互联网IP地址，对其译码，以常见的点分十进制形式输出。

测试说明
平台会对你编写的代码进行测试：

测试输入：
3232235876
1
^Z
预期输出：
192.168.1.100

提示：

程序应能循环接受输入，直至输入Ctrl+Z。
输入为无符号长整形。
*/

#include <stdio.h>

void main()
{
    for (;;)
    {
        unsigned int num, num1, num2, num3, num4;
        if (scanf("%d", &num) != 1)
            break;
        num1 = (num & 0xff000000) >> 24;
        num2 = (num & 0x00ff0000) >> 16;
        num3 = (num & 0x0000ff00) >> 8;
        num4 = num & 0x000000ff;
        printf("%d.%d.%d.%d\n", num1, num2, num3, num4);
    }
}