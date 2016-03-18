#ifndef _QUICK_
#define _QUICK_

#define TRESHOLD 14	

//prototypes
/*recursively sort the array by partitioning*/
void quickInSort(int arr[SIZE], int left, int right);

/*sort while partitioning using a pivot
  return the position of pivot used for parition*/
int partition(int arr[SIZE] , int left, int right);

/*Swap the 2 elements in pos1 and pos2 in the given array*/
void swap(int arr[SIZE], int pos1, int pos2);

/*print the elements*/
void print(int arr[SIZE]);

/*return a suitable pivot*/
int pivot(int array[SIZE], int left, int right);

/*check whether array is sorted
  return 1 is sorted
  0 otherwise*/
int isSorted(int arr[SIZE]);

/*Sort using iterative algorithm*/
void insertionSort(int arr[SIZE], int left, int right);


//Implementations
/**************************************************************/
void quickInSort(int arr[SIZE], int left, int right)
{

	if(left>=right)	
		return;

	if( (right - left) < TRESHOLD)// do insertionSort if less than treshold
	{
		insertionSort(arr, left, right);
		return;
	}

	int piv_pos = partition(arr, left, right); // get pivot position after partitioning

	quickInSort(arr, left, piv_pos);//Sort left part
	quickInSort(arr, piv_pos+1, right); //Sort right part

}

/************************************************************/
int partition(int arr[SIZE] , int left, int right)
{
	int piv_pos = pivot(arr, left, right);//get pivot
	int pos = left+1, to_be_swapped = left+1;

	//bring pivot to left
	swap(arr,piv_pos, left);
	piv_pos = left;
	
	while(1)
	{
		if(pos>right)
		{
			swap(arr, to_be_swapped-1, piv_pos);// put pivot to right place
			return to_be_swapped-1;
		}
	
		if(arr[pos]<arr[piv_pos])
		{
			swap(arr, pos, to_be_swapped);//swap if smaller elements found
			to_be_swapped++;
		}
		pos++;

		
	}

} 

/*******************************************/
void swap(int arr[SIZE], int pos1, int pos2)
{
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}

/********************************************/
int pivot(int array[SIZE], int left, int right)
{
	return left;
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

/***************************************/
void insertionSort(int arr[SIZE], int left, int right)
{
	int i, key, j;
	for (i = left+1; i <=right; i++)
	{
		key = arr[i];
		j = i-1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
}

#endif
