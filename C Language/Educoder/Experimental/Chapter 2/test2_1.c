/*程序改错与跟踪调试
任务描述
本关任务：实验教材 2.3.2节 1.程序改错与跟踪调试
认真阅读教材 P60-61 的任务说明和要求，先在本地按步骤编译和单步执行右侧代码框里程序，根据观察结果，分析代码并修改程序，使之能够正确完成指定任务，然后提交平台测试。

测试说明
平台会对你编写的代码进行测试：

测试输入：
59 3.0
预期输出：
Input Fahrenheit:
 59(F)=15.00(C)

input the radius r:
The acreage is 28.27

new int = 0x84a1
*/

#include <stdio.h>
#define PI 3.14159
int main()
{
    int f;
    unsigned short p, k;
    double c, r, s;

    /*任务1*/
    printf("Input Fahrenheit:");
    scanf("%d", &f);
    c = 5.0 / 9.0 * ((float)f - 32);
    printf("\n %d(F)=%.2f(C)\n\n", f, c);
    /*任务2*/
    printf("input the radius r:");
    scanf("%lf", &r);
    s = PI * r * r;
    printf("\nThe acreage is %.2f\n\n", s);
    /*任务3*/
    k = 0xa1b2, p = 0x8423;
    unsigned int newint = p & 0xff00 | k >> 8;
    printf("new int = %x\n\n", newint);
    return 0;
}