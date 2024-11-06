#include <stdio.h>
#include <stdlib.h>

int removeSame(int *, int n );

int main(void) {
    int n;
    scanf("%d", &n);
    int *p = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", p + i);
    }

    int x = removeSame(p, n);

    for (int i = 0; i < x; i++) {
        printf("%d", *(p + i));
        if (i != x-1)
            printf(" ");
    }
    printf("\n%d", x);
    return 0;
}

int removeSame(int *arr, int n) {
    int list[10] = {0};
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (list[*(arr+i)] == 0) {
            list[*(arr + i)] = 1;
            arr[count++] = arr[i];
        }
    }
    return count;
}