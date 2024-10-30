#include <stdio.h>
#include "7_2.c"
#define SIZE 100
void move(int arr[], int n, int k);
int main()
{
    int arr[SIZE];
    int n, i, k;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);

    move(arr, n, k); // 交换

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}