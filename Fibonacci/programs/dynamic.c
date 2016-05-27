#include <stdio.h>

/*return Fibonacci value of n*/
unsigned long dynamicFib(int n);

int main()
{
	int n, i;

	printf("Enter n: ");
	scanf("%d",&n);
	
	for(i = 1; i<=n; i++)
		printf("F(%d) = %lu\n", i, dynamicFib(i));
	return 0;
}

/*******************************/
unsigned long dynamicFib(int n)
{
	int i;
	unsigned long nthFib;
	unsigned long Fibs[n];

	Fibs[0] = 1;
	Fibs[1] = 1;

	for(i = 2; i<n; i++)
	{	
		Fibs[i] = Fibs[i-1] + Fibs[i-2];//calculate nth fib from previous 2
	}

	return Fibs[n-1];
}
