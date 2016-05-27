#include <stdio.h>

/*return Fibonacci value of n*/
unsigned long MatrixMethodFib(int n);

/*multiply matrices a and b and store the result in a*/
void multiply(unsigned long a[2][2], unsigned long b[2][2]);

int main()
{
	int n, i;

	printf("Enter n: ");
	scanf("%d",&n);
	
	for(i = 1; i<=n; i++)
		printf("F(%d) = %lu\n", i, MatrixMethodFib(i));
	return 0;
}

/***********************************/
unsigned long MatrixMethodFib(int n)
{
    unsigned long matr[2][2] = {{1, 1},{1, 0}};
	unsigned long M[2][2] = {{1, 1},{1, 0}};
	int i, j,k;

	for(i = 0; i<n-1; i++) // multiply n times
		multiply(matr, M);
	
    return matr[0][1];
}

/*********************************************************s**/
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



