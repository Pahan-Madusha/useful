#include <stdio.h>

/*return Fibonacci value of n*/
unsigned long recursiveFib(int n);

int main()
{
	int n, i;

	printf("Enter n: ");
	scanf("%d",&n);
	
	for(i = 1; i<=n; i++)
		printf("F(%d) = %lu\n", i, recursiveFib(i));
	return 0;
}

/********************************/
unsigned long recursiveFib(int n)
{
	if( n <= 2 )
		return 1;

	return recursiveFib(n-1) + recursiveFib(n-2); // recursive call
}
