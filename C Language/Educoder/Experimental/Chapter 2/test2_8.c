/*文本统计
任务描述
本关任务：实验教材P64 程序设计第(10)题
输入一段含西文字符和中文字符的正文，统计字数、字符数和行数。

注意
 在本实验环境中，一个中文字符需要三个字节的存储空间

测试说明
平台会对你编写的代码进行测试：

测试输入：
你好
hello Hello     HELLO
^Z

预期输出：
字数 5
字符数 17   (字符数不计空白符)
行数 2
*/

#include <stdio.h>

int main()
{

    char currentChar;    // 当前字符
    int charCount = 0;   // 字符数
    int wordCount = 0;   // 字(英文词)数
    int lineCount = 0;   // 行数
    int chineseChar = 0; // 用于处理中文占三字符
    int isSpace = 1;     // 默认第一个字为空格（第一个为英文的情况处理）

    while ((currentChar = getchar()) != EOF)
    {
        if (chineseChar > 0)
        {
            chineseChar--;
            continue;
        } // 跳过中文字符的后两个

        /*if (lineCount == 0)
            lineCount++; // 首行+1*/
        if (currentChar == '\n')
        {
            lineCount++; // 换行+1
            isSpace = 1;
            continue;
        }

        if (currentChar == ' ' || currentChar < 0)
        {
            if (currentChar < 0)
            {
                wordCount++;
                charCount++;
                chineseChar = 2;
                isSpace = 0;
            } // 中文字符的第一个+1

            if (currentChar == ' ')
            {
                isSpace = 1;
            }

            continue;
        }

        charCount++;
        if (isSpace == 1)
        {
            wordCount++;
            isSpace = 0;
        }
    }

    if (currentChar == '\n')
        lineCount--;

    printf("字数 %d\n字符数 %d\n行数 %d", wordCount, charCount, lineCount);
    return 0; // 退出循环
}
