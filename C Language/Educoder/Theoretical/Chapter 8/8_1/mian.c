#include "func.c"
#define SIZE 100
#define N 10
void bubble_sort(int *a, int n);
int main()
{
    int a[SIZE], i, k;
    
    for (i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    bubble_sort(a, N);
    for (k = 0; k < N; k++)
    {
        printf("%d ", a[k]);
    }
    return 0;
}
