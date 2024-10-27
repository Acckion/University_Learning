#define R
#include <stdio.h>
#include <assert.h>
int integer_fraction(float x);
int main(void)
{
    float r, s;
    int s_integer = 0;
    int is质数;
    scanf("%f", &r);
#ifdef R
    s = 3.14159 * r * r;
    s_integer = integer_fraction(s);
    if ((s - s_integer) >= 0.5)
        s_integer += 1;
    printf("The integer fraction of area is %d\n", s_integer);
#endif
    return 0;
}

int integer_fraction(float x)
{
    int i = x;
    return i; 
}