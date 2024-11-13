#include <stdio.h>

void cmpPrint(int *, int count, int compared, int (*func)(int, int));
int bigOrEqual(int, int);
int small(int, int);
int main() {
    int (*funcp[])(int, int) = {small, bigOrEqual};
    int n;
    scanf("%d", &n);
    int score[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &score[i]);
    }

    cmpPrint(score, n, 60, funcp[1]);
}
void cmpPrint(int *n, int count, int compared, int (*func)(int, int))
{
    for (int i = 0; i < count; i++) {
        if (func(n[i], compared))
            printf("%d", n[i]);
    }
}
int bigOrEqual(int x, int y) {
    if (x>=y)
        return 1;
    else
        return 0;
}
int small(int x, int y) {
    if (x<y)
        return 1;
    else
        return 0;
}