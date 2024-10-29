#include<stdio.h>

int main(void) {
    int num, index;
    char list[33];
    scanf("%d", &num);

    for (int i = 31; i >= 0; i--)
    {
        // 获取当前位的值，0或1
        list[index++] = (num & (1 << i)) ? '1' : '0';
    };
        list[index] = '\0'; // 添加字符串结束符

    for (int i = 0; i < 32; i++) {
        printf("%c", list[i]);
        if (i % 4 == 3) printf(" ");
    }
    return 0;
}