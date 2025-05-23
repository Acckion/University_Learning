/*条件编译(1)
任务描述
本关任务：使用条件编译方法编写程序。输入一行英文字符串，使用#define命令控制是否变换字母的大小写。
#define CHANGE 1，则将字符串中的小写英文字母变为大写字母后、大写英文字母变为小写字母后输出；
#define CHANGE 0，则输出原文，本关检测的是当#define CHANGE 1的输出。

编程要求
根据提示，在右侧编辑器编写程序，使用条件编译控制输出，本关完成#define CHANGE 1对应的功能，要求本关和下一关的源程序除宏的定义不同外，其它部分完全相同。

测试说明
平台会对你编写的代码进行测试：

测试输入：hello
预期输出：HELLO

测试输入：I have 30 dollars.
预期输出：i HAVE 30 DOLLARS.

提示：

字符串中可能有空格
请严格按照使用条件编译的要求，否则该题记0分
字符串长度不超过1000
开始你的任务吧，祝你成功！*/

#include <stdio.h>
#define CHANGE 1

int main(void)
{
    char c;
    while ((c = getchar()) != EOF)
    {
#if CHANGE
        if (c >= 'a' && c <= 'z')
        {
            putchar(c + 'A' - 'a');
        }
        else if (c >= 'A' && c <= 'Z')
        {
            putchar(c + 'a' - 'A');
        }
        else
        {
            putchar(c);
        }
#else
        putchar(c);
#endif
    }
    return 0;
}