/*反转字符串
任务描述
本关任务：实验教材 1.5 实验一 第6题
输入一个字符串s，统计字符串的长度，并将字符串反转后输出。。

编程要求
按教材 P38 的要求调试右侧代码框里程序，找出程序中的错误，使之输出正确结果。

测试说明
平台会对你编写的代码进行测试：

测试输入：
your

预期输出：
串your的长度为:4
反转后:ruoy
*/

#include <stdio.h>
void strReverse(char s[]);
int strLength(char s[]);
int main()
{
    char s[1000];
    scanf("%s", s);
    printf("串%s的长度为:%d\n", s, strLength(s));
    strReverse(s);
    printf("反转后:%s", s);
    return 0;
}

int strLength(char s[]) /* 返回字符串的长度（不含串尾）*/
{
    int i = 0;
    while (s[i++])
        ;
    return i - 1;
}

void strReverse(char s[]) /* 反转串s */
{
    int i, j;
    for (i = 0, j = strLength(s) - 1; i < j; i++, j--) /* 从两头遍历s */
    {
        char t;
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}