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