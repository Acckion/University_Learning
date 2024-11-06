#include <stdio.h>
#include <string.h>
void remove_extra_spaces_and_newline(char *str) // 用来处理多余的空格，否则educoder测试不通过
{
    char temp[80];
    int j = 0;

    while (*str == ' ')
        str++;

    while (*str)
    {
        if (*str != ' ')
        {
            temp[j++] = *str;
        }
        else if (j > 0 && temp[j - 1] != ' ')
        {
            temp[j++] = ' ';
        }
        str++;
    }
    temp[j] = '\0';

    if (temp[j - 1] == '\n')
    {
        temp[j - 1] = '\0';
    }

    strcpy(str - j, temp);
}
int main(void)
{
    char *(*p[4])(char *, const char *) = {strcpy, strcat, strtok};
    char a[80], b[80], *result;
    int choice;
    while (1)
    {
        do
        {
            /*
            printf("1 copy\n");
            printf("2 connect\n");
            printf("3 parse\n");
            printf("4 exit\n");  
            */
            scanf("%d", &choice);
        } while (choice < 1 || choice > 4);

        if (choice == 4)
            return 0;
        getchar();
        // printf("input first\n");
        fgets(a, 80, stdin);
        remove_extra_spaces_and_newline(a);
        // printf("input scecond\n");
        fgets(b, 80, stdin);
        remove_extra_spaces_and_newline(b);
        result = p[choice-1](a, b);
        printf("%s\n", result);
    }
    return 0;
}
