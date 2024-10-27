#include <stdio.h>
#include <math.h>

int isComposite(int x)
{
    if (x <= 2)
        return 0;
    else
    {
        for (int i = 2; i <= x / 2; i++)
        {
            if (x % i == 0)
                return 1;
        }
        return 0;
    }
}

int main()
{
    int n, temp;
    scanf("%d", &n);
    for (int i = pow(10, n - 1); i < pow(10, n); i++)
    {
        temp = i;
        while (isComposite(temp))
        {
            if (temp / 10 == 0)
            {
                printf("%d ", i);
                break;
            }
            else
            {
                temp /= 10;
            }
        }
    }
    return 0;
}