/*程序改错与跟踪调试
任务描述
实验指导书 P139~140 程序改错与跟踪调试题，请按书中的步骤调试程序，找出函数strncate(t,s)和strdelc(s,c)中的错误并改正。

本任务改用在main函数中输入串a、串b以及待删除字符。

输入输出示例
输入：
Programming
Language
a
输出：
ProgrammingLanguage
ProgrmmingLnguge
*/

#include <stdio.h>

void strcate(char t[], char s[]);
void strdelc(char s[], char c);

int main(void)
{
    char a[100] = "Lamguage", b[100] = "Programming", c = 'a';
    scanf("%s", a);
    scanf("%s", b);
    scanf(" %c", &c);
    strcate(a, b);
    printf("%s\n", a);
    strdelc(a, c);
    printf("%s\n", a);
    return 0;
}

void strcate(char t[], char s[])
{
    int i = 0, j = 0;
    while (t[i] != '\0')
        i++;
    while (s[j] != '\0')
        t[i++] = s[j++];
    t[i] = '\0';
}

void strdelc(char s[], char c)
{
    int j, k;
    for (j = k = 0; s[j] != '\0'; j++)
    {
        if (s[j] == c)
        {
            for (int i = j; s[i] != '\0'; i++)
            {
                s[i] = s[i + 1];
            }
        }
    }
}