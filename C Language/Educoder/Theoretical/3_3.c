#include<stdio.h>

int main()
{
    int x=0, p=0, n=0;
    scanf("%d %d %d", &x, &p, &n);
    int mask = ((1<<n) - 1) << (p-n+1);
    int output = x ^ mask;
    printf("%dAAA", output);
}
