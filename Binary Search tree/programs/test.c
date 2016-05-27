#include <stdio.h>
#include "BST.h"

void printArray(int arr[30]);
void populate(bst* tree, int arr[30]);

/*********/
int main()
{
	int randomNos[30];
	int num;
	bst* tree = createBST();
	bst* copy = createBST();
	
	printf("Adding random numbers to BST\n");
	populate(tree, randomNos);	

	printf("Populated order..\n");
	printArray(randomNos);

	printf("Printing ordered list from tree\n");
	printOrderedList(tree);
	printf("\n");
	printf("\n");
	
	printf("Copying BST to another BST..\n Printing it..\n");
	copyBST(tree, copy);
	printOrderedList(copy);
	printf("\n");
	printf("\n");

	printf("Max in the tree : %d \n",findMax(tree));
	printf("Min in the tree : %d \n",findMin(tree));
	printf("\n");

	printf("Enter a number find in the tree : \n");
	scanf("%d",&num);
	
	if(findBST(tree, num))
		printf("%d is in the tree\n",num);
	else
		printf("%d is not in the tree\n",num);

	printf("\n");

	printf("Removing %d from the tree..\n",randomNos[5]);
	tree = deleteBST(tree, randomNos[5]);
	printf("After removal\n");
	printOrderedList(tree);
	printf("\n");
	
	printf("Destroying BST...\n");
	destroyBST(tree);

	printf("\nPrinting tree after destroy..\n\n");
	printOrderedList(tree);
	

	return 0;
}

/************************************/
void populate(bst* tree, int arr[30])
{
	int i;
	srand(time(NULL));

	for(i = 0; i<30; i++)
	{
		arr[i] = rand()%50;
		addBST(tree, arr[i]);
	}
}

/****************************/
void printArray(int arr[30])
{
	int i;
	
	for(i = 0; i<30; i++)
		printf("%d ",arr[i]);
	printf("\n");
}




