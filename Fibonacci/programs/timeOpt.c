#include <stdio.h>

/*return nth Fibonacci number*/
unsigned long timeOptFib(int n);

/*multiply matrices a and b and store the result in a*/
void multiply(unsigned long a[2][2], unsigned long b[2][2]);

/*divide recursively and take powers*/
void power(unsigned long F[2][2], int n);

int main()
{
	int n, i;

	printf("Enter n: ");
	scanf("%d",&n);
	
	for(i = 1; i<=n; i++)
		printf("F(%d) = %lu\n", i, timeOptFib(i));
	return 0;
}

/*****************************/
unsigned long timeOptFib(int n)
{
	unsigned long F[2][2] = {{1,1},{1,0}};
	if (n == 0)
		return 0;
	power(F, n-1);
	return F[0][0];
}
 
/**************************************/
void power(unsigned long F[2][2], int n)
{
	if( n == 0 || n == 1)
		return;

	unsigned long M[2][2] = {{1,1},{1,0}};

	power(F, n/2);
	multiply(F, F); 

	if (n%2 != 0) // multiply by M if odd
		multiply(F, M);
}

/************************************************************/
void multiply(unsigned long matr[2][2], unsigned long M[2][2])
{
	unsigned long a =  matr[0][0]*M[0][0] + matr[0][1]*M[1][0];
	unsigned long b =  matr[0][0]*M[0][1] + matr[0][1]*M[1][1];
	unsigned long c =  matr[1][0]*M[0][0] + matr[1][1]*M[1][0];
	unsigned long d =  matr[1][0]*M[0][1] + matr[1][1]*M[1][1];

	matr[0][0] = a;
	matr[0][1] = b;
	matr[1][0] = c;
	matr[1][1] = d;

}


