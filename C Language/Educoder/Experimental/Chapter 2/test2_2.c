/*各位数字之和
任务描述
本关任务：：**实验教材P63 程序设计第(2)题
输入一个十进制正整数n，求它是几位数并计算各位数字之和。

测试说明
平台会对你编写的代码进行测试：

测试输入：20190223；
预期输出：
20190223是8位数，且各位数字之和为19。
*/

#include <stdio.h>

int main(void)
{
   int n_input;
   int count = 0;
   int sum = 0;

   scanf("%d", &n_input);
   int temp = n_input;

   while (temp > 0)
   {
      count++;
      sum += temp % 10;
      temp /= 10;
   }
   printf("%d是%d位数，且各位数字之和为%d。", n_input, count, sum);
   return 0;
}
