/*插入字符串
任务描述
实验指导书 P143 程序设计第（5）题
本关任务：编写函数strnins(t,s,n),其功能是：将串s插入串t串的第n个字符的后面，编写main函数测试strnins函数的正确性。

示例
输入（依次为t、s、n）：
iyou
love
1
输出：
iloveyou

开始你的任务吧，祝你成功！ */

#include <stdio.h>

int insert(char arr1[], char arr2[], int n);

int main()
{
    char arr1[100];
    char arr2[100];
    int n;
    scanf("%s", arr1);
    scanf("%s", arr2);
    scanf("%d", &n);

    insert(arr1, arr2, n);

    printf("%s", arr1);
    return 0;
}

int insert(char arr1[], char arr2[], int n)
{
    int i = 0, j = 0;
    while (arr1[i] != '\0')
    {
        i++;
    }
    while (arr2[j] != '\0')
    {
        j++;
    }
    if (n > i)
    {
        return 0;
    }
    for (int k = i; k >= n; k--)
    {
        arr1[k + j] = arr1[k];
    }
    for (int k = 0; k < j; k++)
    {
        arr1[n + k] = arr2[k];
    }
    return 1;
}