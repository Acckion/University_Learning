/*字符转换
任务描述
本关任务：实验教材P63 程序设计第(8)题
输入一个仅有英文大写字母、逗号、句点和空格符组成的英文句子（字符数不超过80个）和正整数k（1<=k<=26），将其中的大写英文字母替换成字母表中该字母开始的第k个字母，其它字符保持不变.

测试说明
平台会对你编写的代码进行测试：

测试输入：
ON A CLEAR DAY,YOU CAN SEE FOREVER
9
预期输出：
VWI K MTZIL GIG,CWK VIA MMN ZWDMZM
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char n[80];
    int k;
    fgets(n, sizeof(n), stdin);
    scanf("%d", &k);
    int len = strlen(n);

    for (int i = 0; i < len; i++)
    {
        if (n[i] >= 65 && n[i] <= 90)
        {
            n[i] = ((n[i] - 65 + k) % 26) + 65;
        }
    }
    printf("%s", n);
    return 0;
}