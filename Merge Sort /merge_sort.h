#ifndef _MERGE_
#define _MERGE_

//prototypes
/*print the integer array*/
void print(int arr[SIZE]);

/*divide and (sort while merging)*/
void mergeSort(int arr[SIZE], int left, int right);

/*merge while sorting*/
void merge(int arr[SIZE], int left, int right);

/*check whether array is sorted
  return 1 is sorted
  0 otherwise*/
int isSorted(int arr[SIZE]);


//Function Implementations
/************************************************************/
void mergeSort(int arr[SIZE], int left, int right)
{
	if(left >= right) // stop when down to 1 element
		return;
	
	int mid = (left + right)/2;

	mergeSort(arr, left, mid);
	mergeSort(arr, mid+1, right);

	merge(arr, left, right);
}

/********************************************************************/
void merge(int arr[SIZE], int left, int right)
{
	int mid = (left + right)/2;
	
	int curr = 0,lRef = left, rRef = mid+1, i,j=0;

	int tmp[right-left+1]; // temporary array to store merged arrays
	
	while(lRef<=mid && rRef<=right)	// merge while 1 part finishes
	{
		if(arr[lRef] > arr[rRef])
		{
			tmp[curr] = arr[rRef];
			curr++;
			rRef++;
		}
		else
		{
			tmp[curr] = arr[lRef];
			curr++;
			lRef++;
		}

	}

	
	if(lRef >mid)//if left part is done copy the right part
	{
		for(i = rRef; i<=right; i++)
		{
			tmp[curr] = arr[i];
			curr++;
		}
	}
	else 
	{
		for(i = lRef; i<=mid; i++)
		{
			tmp[curr] = arr[i];	
			curr++;
		}	
	}

	//copy from temporary array to original
	for(i = left; i<right+1; i++)
	{
		arr[i] = tmp[j];
		j++;	
	}
}

/***************************************/
void print(int arr[SIZE])
{
	int i;
	for(i = 0; i<SIZE; i++)
		printf("%d	",arr[i]);
	printf("\n");
}

/*************************************/
int isSorted(int arr[SIZE])
{
	int i;
	for(i = 1; i<SIZE; i++)
		if(arr[i]<arr[i-1])
			return 0;
	return 1;
}

#endif
