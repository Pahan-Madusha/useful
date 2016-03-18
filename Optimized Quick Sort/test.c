//define array size here
#define SIZE 1000000

#include <stdio.h>
#include <time.h>
#include "quickInSort.h"

#define ARRAYS 30

/*populate the array with random numbers*/
void generate_array(int array[SIZE]);

/*return the time taken to sort if sorting is successful
  return -1.0 otherwise*/
double time_for_sorting(int arr[SIZE]);

/********************************************************/
int main()
{
	srand(time(NULL));//seed random num generator with time
	int arr[SIZE];
	int i;
	double total = 0;
	
	for(i = 0; i<ARRAYS; i++)
	{
		generate_array(arr);
		total+=time_for_sorting(arr);		
	}

	printf("Average time taken : %f\n",total/ARRAYS);
	return 0;
}

/*****************************************/
void generate_array(int array[SIZE])
{
	int i;

	for(i = 0; i<SIZE; i++)
		array[i] = rand();

}

/********************************************/
double time_for_sorting(int arr[SIZE])
{
	clock_t start, end;
	
	start = clock();
	quickInSort(arr,0,SIZE-1); // sort with quick_sort
	end = clock();
	
	if(isSorted(arr))
	{
		return (double)(end - start)/CLOCKS_PER_SEC;
	}

	return -1.0; // if sorting is unsuccessful
}
