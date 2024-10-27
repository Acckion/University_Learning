#include <stdio.h>

unsigned long long fabonacci(int n, unsigned long long first, unsigned long long second);

int main(void)
{
    int i, k;

    unsigned long long sum = 0;
    printf("Input n:");
    scanf("%d", &k);

    for (i = 1; i <= k; i++)
    {
        sum += fabonacci(i, 1, 1);
        printf("i=%d\tthe sum is %llu\n", i, sum);
    }
    return 0;
}

unsigned long long fabonacci(int n, unsigned long long first, unsigned long long second)
{
    if (n <= 1)
        return first;
    else
        return fabonacci(n - 1, second, first + second);
}