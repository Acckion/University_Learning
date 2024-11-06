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
    printf("%d", n);

    return 0;
}

int delSubStr(char *str, const char *substr)
{
    int count = 0;
    int substr_len = strlen(substr);
    int str_len = strlen(str);

    for (int i = 0; i <= str_len-substr_len;)
    {
        int found = 1;
        for (int j = 0; j < substr_len; j++)
        {
            if (*(str + i + j) != *(substr + j)) {
                found = 0;
                break;
            }
        }
        if (found) {
            for (int k = i; k < str_len - substr_len; k++) {
                *(str + k) = *(str + k + substr_len);
            }
            str_len -= substr_len;
            count++;
        }
        else {
            i++;
        }
    }
    *(str + str_len) = '\0';
    if (count >=1)
        return 1;
    else
        return 0;
}