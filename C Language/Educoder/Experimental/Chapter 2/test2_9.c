/*数据加密
任务描述
本关任务：实验教材P64 程序设计第(13) 题
         输入一行明文字符串，按题中算法进行加密后输出密文。

测试说明
平台会对你编写的代码进行测试：

测试输入：
abcd
预期输出：
dbfp
*/

#include <stdio.h>

    int main()
{

    for (int i = 0; i < 4; i++)
    {
        char c = getchar();
        c = ((c << 1) & 0x2A | (c >> 1) & 0x15) & 0x3F | (c & 0xC0);

        switch (c >> 6)
        {
        case 0:
            printf("%c", c);
            break;
        case 1:
            printf("%c", (((c << 1) & 0x1E | (c >> 4) & 0x01) & 0x3F) | (c & 0xC0));
            break;
        case 2:
            printf("%c", (((c << 2) & 0x1C | (c >> 3) & 0x03) & 0x3F) | (c & 0xC0));
            break;
        case 3:
            printf("%c", (((c << 3) & 0x18 | (c >> 2) & 0x07) & 0x3F) | (c & 0xC0));
            break;
        }
    }

    printf("\n");
    return 0;
}