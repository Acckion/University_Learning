/*折点
任务描述
本关任务：实验教材P63 程序设计第(3)题
给定n个整数表示一个商店连续n天的销售量，计算出这些天总共有多少个折点。

测试说明
平台会对你编写的代码进行测试：

测试输入：
7
6 3 1 4 5 8 6
预期输出：
2
*/

#include <stdio.h>

int main(void)
{
    int numbers, current_n, previous_n, current_state, previous_state = 0, peak = 0;
    scanf("%d", &numbers);
    scanf("%d", &previous_n);

    for (int i = 1; i < numbers; i++)
    {
        scanf("%d", &current_n);
        if (current_n > previous_n)
            current_state = 1;
        else if (current_n < previous_n)
            current_state = -1;
        else
            current_state = 0;
        if (current_state != previous_state && previous_state != 0)
            peak++;
        previous_state = current_state;
        previous_n = current_n;
    }
    printf("%d", peak);
    return 0;
}