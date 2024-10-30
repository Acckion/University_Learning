/*程序修改替换(2)
任务描述
实验课本 P107 程序修改替换第（2）题
本关任务：修改实验教材P96例4.6中的sum和fun函数，使之计算量最小

编程要求
使得修改后的sum函数和func函数计算量最小

测试说明
平台会对你编写的代码进行测试：

测试输入：1 2
预期输出：The result is 2.500000

测试输入：3.5 4
预期输出：The result is 24.023438

提示：

使用局部静态变量
开始你的任务吧，祝你成功！*/

#include<stdio.h>
double mulx(double x);
long fac(int n);
static double z=1.0;

double sum(double x,int n)  //累加求和
{
    double sum;
    for (int i = 1; i <= n; i++)
    {
        sum += (mulx(x))/(fac(i));
    }
    return sum + 1;
}

double mulx(double x) //x的n次方(每次运行乘x)
{
	int i;
	z *= x;
	return z;
}

long fac(int n) // 计算n！(每次运行xn)
{
    static result = 1;
    result *= n;
    return result;
}

int main()
{
	double x;
	int n;
	scanf("%lf%d",&x,&n);
	printf("The result is %lf",sum(x,n));
	return 0;
} 