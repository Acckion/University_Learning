#include<stdio.h>

int tail(int x, int n) {
    int result=0;
    int multiplier=1;
    for (int i=0; i<n; i++) {
        result += (x % 10)*multiplier;
        multiplier *= 10;
        x /= 10;
    }
    return result;
}

int main() {
    int x,n;
    scanf("%d %d", &x, &n);
    printf("%d", tail(x, n));
    return 0;
}