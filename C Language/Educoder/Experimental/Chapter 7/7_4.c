#include <stdio.h>

struct bits {
    unsigned int bit0 : 1;
    unsigned int bit1 : 1;
    unsigned int bit2 : 1;
    unsigned int bit3 : 1;
    unsigned int bit4 : 1;
    unsigned int bit5 : 1;
    unsigned int bit6 : 1;
    unsigned int bit7 : 1;
};
union bitsU {
    unsigned int x;
    struct bits bitS;
};

void fun0(int b) {
    printf("the function %d is called!\n", b);
}
void fun1(int b)
{
    printf("the function %d is called!\n", b);
}
void fun2(int b)
{
    printf("the function %d is called!\n", b);
}
void fun3(int b)
{
    printf("the function %d is called!\n", b);
}
void fun4(int b)
{
    printf("the function %d is called!\n", b);
}
void fun5(int b)
{
    printf("the function %d is called!\n", b);
}
void fun6(int b)
{
    printf("the function %d is called!\n", b);
}
void fun7(int b)
{
    printf("the function %d is called!\n", b);
}

int main(void) {
    void (*p_fun[8])(int) = { fun0, fun1, fun2, fun3, fun4, fun5, fun6, fun7};
    union bitsU bit;
    scanf("%d", &bit.x);

    if (bit.bitS.bit0 != 0)
        fun0(0);
    if (bit.bitS.bit1 != 0)
        fun1(1);
    if (bit.bitS.bit2 != 0)
        fun2(2);
    if (bit.bitS.bit3 != 0)
        fun3(3);
    if (bit.bitS.bit4 != 0)
        fun4(4);
    if (bit.bitS.bit5 != 0)
        fun5(5);
    if (bit.bitS.bit6 != 0)
        fun6(6);
    if (bit.bitS.bit7 != 0)
        fun7(7);

    return 0;
}