/*去掉重复字符（改进）
任务描述
实验指导书 P140~141 程序完善与修改替换第（1）题
请通过空间换时间的方法对第2关去掉重复字符的程序进行改进，使算法的时间复杂度由O(n^2)降低为O(n)。
*/

#include <stdio.h>
#include <string.h>

void RemoveDuplicate(char *s);
int len;
int main()
{
    char str[200];
    while (fgets(str, 200, stdin) != NULL)
    {
        RemoveDuplicate(str);
        for (int i = 0; i < len; i++)
        {
            if (str[i] != '\0')
                putchar(str[i]);
        }
    }
    return 0;
}

void RemoveDuplicate(char *s)
{
    int r, w, i;
    int list[256];
    for (int x = 0; x <= 256; x++)
        list[x] = 0;
    len = strlen(s);
    for (r = 0; r < len; r++)
    {
        if (list[s[r]] == 1)
            s[r] = '\0';
        if (s[r] != '\0')
            list[s[r]] = 1;
    }
}