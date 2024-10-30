/*输出abcde/fghij=x表达式
任务描述
本关任务：实验课本P86  程序设计第（12）题
输入正整数x(2≤x≤79)，输出所有形如abcde/fghij=x的表达式，其中a-j由不同的数字0~9组成。

编程要求
在右侧编辑器补充代码，输入x后输出形如abcde/fghij=x的表达式。

测试说明
平台会对你编写的代码进行测试：

测试输入：32；
预期输出：75168/02349=32

测试输入：12；
预期输出：
45792/03816=12
73548/06129=12
89532/07461=12
91584/07632=12

开始你的任务吧，祝你成功！*/

#include <stdio.h>
#include <stdbool.h>

int list[10];  // 存储 0~9 的数字
bool used[10]; // 标记数组，记录数字是否已使用

// 初始化数组为 0~9
void init()
{
    for (int i = 0; i < 10; i++)
    {
        list[i] = i;
        used[i] = false; // 初始时所有数字未使用
    }
}

// 构造前5位和后5位的数字
void generate(int index, int num1, int num2, int x)
{
    if (index == 10)
    { // 当所有10位数都被使用时
        if (num2 != 0 && num1 % num2 == 0 && num1 / num2 == x)
        {
            printf("%05d/%05d=%d\n", num1, num2, x);
        }
        return;
    }

    // 遍历所有可能的数字
    for (int i = 0; i < 10; i++)
    {
        if (!used[i])
        {                   // 如果该数字未被使用
            used[i] = true; // 标记为已使用

            if (index < 5)
            { // 前5位数
                generate(index + 1, num1 * 10 + i, num2, x);
            }
            else
            { // 后5位数
                generate(index + 1, num1, num2 * 10 + i, x);
            }

            used[i] = false; // 回溯，恢复标记状态
        }
    }
}

int main()
{
    int x;
    scanf("%d", &x); // 输入x的值

    init();               // 初始化数组和标记数组
    generate(0, 0, 0, x); // 开始生成排列并检查条件

    return 0;
}