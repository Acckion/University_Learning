/*整数的二进制表示
任务描述
实验指导书 P142 程序设计第（1）题
本关任务：输入一个整数，将它在内存中的二进制表示的每一位转换成对应的数字字符并且存放到一个字符数组中，然后输出该整数的二进制表示（32位有符号整数，输出每4位用空格分隔）。

示例
输入：
1
输出：
0000 0000 0000 0000 0000 0000 0000 0001

开始你的任务吧，祝你成功！*/

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