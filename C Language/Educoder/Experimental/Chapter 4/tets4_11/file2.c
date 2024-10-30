#include <stdio.h>
#include "file.h"

extern int x, y;
extern char ch;
void func1(void)
{
    x++;
    y++;
    ch++;
    printf("in file2 x=%d,y=%d,ch is %c\n", x, y, ch);
}