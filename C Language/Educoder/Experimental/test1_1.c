/*完全平方数
任务描述
本关任务：实验教材 1.5 实验一 第1题
         若一个数能表示成某个数的平方的形式，这个数即为完全平方数。有一种数，它加上100后是一个完全平方数，
         再加上268后也是一个完全平方数，找出100000内满足该条件的所有数.

编程要求:
认真阅读教材 P31 的实验步骤，按步骤编辑、编译和运行右侧代码框里程序，使之输出正确结果。
*/

#include <math.h> /* 数学函数库的头文件 */
#include <stdio.h>
int main()
{
    long x, y;

    int i;
    for (i = 1; i < 100000; i++)
    {
        x = sqrt(i + 100); /* sqrt是求平方根的函数 */
        y = sqrt(i + 268);
        if ((x * x == i + 100) && (y * y == i + 268))
        {
            printf("\n%d", i);
        }
    }
    return 0;
}