#include <stdio.h>

void fillInNumbers(int arr[][100], int x, int y, int n, int *num)
{
    int left = 0, right = n - 1;
    int top = 0, bottom = n - 1;

    while (*num <= n * n)
    {
        // 从左到右
        for (int i = left; i <= right; i++)
        {
            arr[top][i] = (*num)++;
        }
        top++;

        // 从上到下
        for (int i = top; i <= bottom; i++)
        {
            arr[i][right] = (*num)++;
        }
        right--;

        // 从右到左
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                arr[bottom][i] = (*num)++;
            }
            bottom--;
        }

        // 从下到上
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                arr[i][left] = (*num)++;
            }
            left++;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[100][100]; // 定义最大 100x100 的矩阵
    int num = 1;

    // 初始化数组
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    // 填充螺旋矩阵
    fillInNumbers(arr, 0, 0, n, &num);

    // 输出结果
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", arr[i][j]); 
            if (j<n-1)
                printf(" "); // 用空格分隔
        }
        printf("\n"); // 每行换行
    }

    return 0;
}