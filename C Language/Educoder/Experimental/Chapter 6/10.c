#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int delSubStr(char *, const char *);

int main(void)
{
    char str[100], substr[100];

    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';

    fgets(substr, 100, stdin);
    substr[strcspn(substr, "\n")] = '\0';

    int n = delSubStr(str, substr);
    printf("%s\n", str);
    printf("%d\n", n);

    return 0;
}

int delSubStr(char *str, const char *substr)
{
    int count = 0;
    int substr_len = strlen(substr);

    for (char *pos = strstr(str, substr); pos != NULL; pos = strstr(str, substr))
    {
        // 删除找到的子串
        memmove(pos, pos + substr_len, strlen(pos + substr_len) + 1);
        count++;
    }
    return count; // 返回删除子串的次数
}