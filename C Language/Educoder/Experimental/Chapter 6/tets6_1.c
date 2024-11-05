#include <stdio.h>
#include <stdlib.h>

char *strcopy(char *, const char *);

int main(void)
{
    char *s1 = (char *)malloc(100 * sizeof(char));
    char *s2 = (char *)malloc(100 * sizeof(char));
    char *s3 = (char *)malloc(100 * sizeof(char));

    if (s1 == NULL || s2 == NULL || s3 == NULL)
    { // 检查内存分配是否成功
        printf("Memory allocation failed\n");
        return 1;
    }

    scanf("%99s", s2);
    strcopy(s1, s2);
    printf("%s\n", s1);

    scanf("%99s", s2);
    strcopy(s3, s2);
    printf("%s", s3);

    free(s1);
    free(s2);
    free(s3);

    return 0;
}

char *strcopy(char *t, const char *s)
{
    while ((*t++ = *s++) != '\0')
    {
        ;
    }
    return t;
}