/*税金计算
任务描述
实验课本P85 程序设计第（1）题
假设工资税金按以下方法计算：x<1000元，不收取税金；1000≤x<2000，收取5%的税金；2000≤x<3000,收取10%的税金；3000≤x<4000，收取15%的税金；4000≤x<5000，收取20%的税金；x>5000，收取25%的税金。

输入工资金额（单位：元），输出应收取的税金额度（设税金为整数）。

编程要求
在右侧编辑器补充代码，计算出相应的税金。

测试说明
平台会对你编写的代码进行测试：

测试输入：1000；
预期输出：0;

测试输入：2500；
预期输出：100

提示：
当输入2500时，1000内是不收取税金的，1000-2000元部分收取5%的税金，超出2000元的部分收取10%的税金，即：
(2000-1000)*5%+(2500-2000)*10%=100元

开始你的任务吧，祝你成功！*/

#include<stdio.h>
unsigned long long sum_fac(int n);

int main(void)
{
	int k;
	for(k=1; k<=20; k++)
		printf("k=%d the sum is %llu\n",k,sum_fac(k));
	return 0;
}


unsigned long long sum_fac(int n)
{
    static unsigned long long fact = 1;
    static unsigned long long sum = 0; 

    fact *= n;
    sum += fact;
    
    return sum;
}

