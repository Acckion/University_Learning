#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x, y;
    scanf("%d %d", &x, &y);
    int **p = (int **)malloc(x * sizeof(int *));
    for (int i = 0; i < x; i++)
    {
        p[i] = (int *)malloc(y * sizeof(int));
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }

    for (int j = y - 1; j >= 0; j--)
    {
        for (int i = 0; i < x; i++)
        {
            printf("%d", p[i][j]);
            if (i != x - 1)
                printf(" ");
        }
        printf("\n");
    }
    for (int i = 0; i < x; i++)
    {
        free(p[i]);
    }
    free(p);
    return 0;
}