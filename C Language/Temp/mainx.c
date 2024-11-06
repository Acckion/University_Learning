#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, int **argv)
{
    double x;
    int n = 1;
    x = atof(argv[1]);
    int count = atoi(argv[2]);
    while (--count >= 0)
    {
        n *= x;
    }
    printf("%d", n);
    return 0;
}