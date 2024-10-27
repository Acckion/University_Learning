#include<stdio.h>

int main()
{
    short k=0, p=0;
    short output=0;
    scanf("%hd %hd", &k, &p);
    k = (k>>8) & 0x00ff;
    p = (p<<8) & 0xff00;
    output = k | p;
    printf("%hd", output);
    return 0;
}