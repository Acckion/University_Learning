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
    char inputChar;
    printf("请输入一个字符: ");
    scanf("%c", &inputChar);

    // 将字符转换为ASCII码
    unsigned char asciiValue = (unsigned char)inputChar;
    printf("原始ASCII值: %d\n", asciiValue);

    // 对该ASCII值进行加密
    unsigned char encryptedValue = encryptByte(asciiValue);

    // 将加密后的值转换回字符
    char encryptedChar = (char)encryptedValue;

    printf("加密后的ASCII值: %d\n", encryptedValue);
    printf("加密后的字符: %c\n", encryptedChar);

    return 0;
}
