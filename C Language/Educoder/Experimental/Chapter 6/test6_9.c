#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int *, int);
void sort_d(int *p, int n);
int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int *p = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", p + i);
    if (argc > 2) {
        if (strcmp(argv[2], "-d") == 0) 
            sort_d(p, n);
    }
    else
        sort(p, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d", *(p + i));
        if (i != n - 1)
            printf(" ");
    }
    return 0;
}

void sort_d(int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j] < p[j + 1])
            {
                int temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
void sort(int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j] > p[j + 1])
            {
                int temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}