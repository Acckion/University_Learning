#include <stdio.h>

int power(int);
int main() {
    int a, sum, n;
    scanf("%d %d", &a, &n);
    for (int i = 0; i < n; i++)
        sum += power(a);
    printf("%d", sum);
    return 0;
}

int power(int a) {
    static int x = 0;
    x = x * 10 + a;
    return x;
}