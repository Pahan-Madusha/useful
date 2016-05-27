#include <stdio.h>

unsigned long intelRecursiveFib2(int n, unsigned long n_1, unsigned long n_2);
unsigned long intelRecursiveFib(int n);

int main()
{
	int n, i;

	printf("Enter n: ");
	scanf("%d",&n);
	
	for(i = 1; i<=n; i++)
		printf("F(%d) = %lu\n", i, intelRecursiveFib(i));
	return 0;
}

/*************************************/
unsigned long intelRecursiveFib(int n)
{
	if( n == 0)
		return 0;

    return intelRecursiveFib2(n, 0, 1);
}

/****************************************************************************/
unsigned long intelRecursiveFib2(int n, unsigned long n_2, unsigned long n_1)
{
	if( n == 1 )
		return n_1;
	
	return intelRecursiveFib2(n-1, n_1, n_1 + n_2);
}


