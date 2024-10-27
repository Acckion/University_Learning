#include <stdio.h>
unsigned long long sum_fac(int n);
int main(void)
{
	int k;
	unsigned long long sum = 0;
	for (k = 1; k <= 20; k++)
	{
		sum += sum_fac(k);
		printf("k=%d the sum is %llu\n", k, sum);
	}
	return 0;
}
unsigned long long sum_fac(int n)
{
	int i;
	unsigned long long fac = 1;
	for (i = 1; i <= n; i++)
		fac *= i;
	return fac;
}