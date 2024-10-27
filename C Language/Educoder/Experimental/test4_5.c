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