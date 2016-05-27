#include <stdio.h>

/*return nth Fibonacci number*/
unsigned long spaceOptFib(int n);

int main()
{
	int n, i;

	printf("Enter n: ");
	scanf("%d",&n);
	
	for(i = 1; i<=n; i++)
		printf("F(%d) = %lu\n", i, spaceOptFib(i));
	return 0;
}

/******************************/
unsigned long spaceOptFib(int n)
{
	unsigned long a = 1, b = 1, c, i;

	for (i = 3; i <= n; i++) 
	{
		c = a + b;
		a = b;
		b = c;
	}           
	return b;
}
