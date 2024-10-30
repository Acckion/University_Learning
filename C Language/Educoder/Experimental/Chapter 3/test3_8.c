/*去除重复空格
任务描述
本关任务：实验课本P85  程序设计第（4）题
将输入的正文复制到输出，复制过程中将每行一个以上的空格字符用一个空格代替。

编程要求
在右侧编辑器补充代码

测试说明
平台会对你编写的代码进行测试：

测试输入：I  love     hust!
预期输出：I love hust!

开始你的任务吧，祝你成功！*/

#include <stdio.h>
int main()
{
    char c;
    char last = 'a';
    while ((c = getchar()) != EOF)
    {
        if (last != ' ')
        {
            if (c == ' ')
                last = c;
            else
            {
                putchar(c);
            }
        }
        else
        {
            if (c != ' ')
            {
                putchar(' ');
                putchar(c);
            }
        }
        last = c;
    }
    if (last == ' ')
        putchar(' ');
    return 0;
}