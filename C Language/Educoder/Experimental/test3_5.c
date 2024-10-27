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

