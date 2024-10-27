/*手机号码的判断
任务描述
本关任务：实验教材P63 程序设计第(4)题
 判断输入的字符串是否符合手机号码的格式。

判断条件的优先级规定为：
长度合法>每一位都是数字>第1位合法>第2位合法。

测试说明
平台会对你编写的代码进行测试：

测试输入：
"1304567854"

预期输出：
长度不合法

测试输入：
"10234567543"

预期输出：
第2位不合法
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main()
{
    char telnum[20];
    scanf("%s", &telnum);

    if (strlen(telnum) != 11)
    {
        printf("长度不合法\n");
        return;
    }

    for (int i = 0; i < 11; i++)
    {
        if (!isdigit(telnum[i]))
        {
            printf("字符串中存在非数字字符\n");
            return;
        }
    }

    // 检查第 1 位是否为 '1'
    if (telnum[0] != '1')
    {
        printf("第1位不合法\n");
        return;
    }

    // 检查第 2 位是否合法
    char second = telnum[1];
    if (second != '3' && second != '4' && second != '5' &&
        second != '6' && second != '7')
    {
        printf("第2位不合法\n");
        return;
    }

    printf("手机号合法\n");
}