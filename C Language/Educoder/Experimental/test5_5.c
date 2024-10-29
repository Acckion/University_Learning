#include<stdio.h>

int main(void) {
    int m, n;
    scanf("%d %d", &m, &n);
    int a[m], b[m];
    int i, j, k;
    for (i = 0; i < m; i++) 
        a[i] = i + 1;
    for (i = m, j = 0; i > 1; i--) {
        for (k = 1; k <= n; k++)
            if (++j > i - 1)
                j = 0;
        b[m - i] = a[j];
        if (j)
            for (k = --j; k < i; k++)
                a[k] = a[k + 1];
    }
    for (i = 0; i < m; i++)
        printf("%6d ", b[i]);
    printf("%6d\n", a[0]);
    return 0;
}



