#include <stdio.h>

// 交换0,2,4与1,3,5位
unsigned char swapBits(unsigned char byte)
{
    byte = ((byte & 0xAA) >> 1) | ((byte & 0x55) << 1); // 0↔1, 2↔3, 4↔5
    return byte;
}

// 根据6,7位决定左移次数
unsigned char encryptByte(unsigned char byte)
{
    // 交换位
    byte = swapBits(byte);

    // 提取6,7位，计算左移次数
    int shift = (byte >> 6) & 0x03; // 提取6,7位（最多值为3）

    // 提取0~5位部分
    unsigned char lowerBits = byte & 0x3F; // 0x3F = 00111111

    // 0~5位循环左移
    lowerBits = (lowerBits << shift) | (lowerBits >> (6 - shift));

    // 将修改后的0~5位和原6,7位合并
    return (byte & 0xC0) | (lowerBits & 0x3F); // 0xC0 = 11000000
}

int main()
{
    unsigned char input = 0x66; // 原始数据，二进制：01100110
    unsigned char encrypted = encryptByte(input);

    printf("加密后: 0x%02X\n", encrypted);

    return 0;
}
