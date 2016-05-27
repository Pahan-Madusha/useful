#ifndef _BST_
#define _BST_
#define SIZE 100

#include <stdlib.h>
#include <limits.h>

/*data structure binary search tree*/
typedef struct bst_node
{
	int data;
	struct bst_node* left;
	struct bst_node* right;	
}bst;

/*
  allocate memory for a single
  node
  return the node
*/
bst* createBST();

/*
  add the given data to the 
  given tree
*/
void addBST(bst* tree, int data);

/*
  print the tree in sorted
  order
*/
void printOrderedList(bst* tree);

/*
  free the memory allocated 
  for the bst
*/
void destroyBST(bst* tree);

/*
  Delete the node with
  the given value from
  given bst
*/
bst* deleteBST(bst* tree, int data);

/*
  return 1 if given data is
  present in the given bst
  0 otherwise
*/
int findBST(bst* tree, int data);

/*
  copy the bst given in tree
  to bst given as copy
*/
void copyBST(bst* tree, bst* copy);

/*
  find the node with min value 
  and return it
*/
bst* minValueNode(bst* tree);


/*Implementations*/

/**********************/
bst* createBST()
{
	bst* tree = malloc(sizeof(bst)); // allocate memory
	tree -> data = INT_MIN;
	tree -> left = NULL;
	tree -> right = NULL;
	return tree;
}

/**************************/
void destroyBST(bst* tree)
{
	if(tree == NULL)
		return;

	if(tree -> left != NULL) 	
		destroyBST(tree -> left);
	
	if(tree -> right != NULL)
		destroyBST(tree -> right);
	
	free(tree);
}

/*********************************/
void copyBST(bst* tree, bst* copy)
{
	if(tree == NULL)
		return;
	
	addBST(copy, tree -> data);

	if(tree -> left != NULL)
		copyBST(tree -> left, copy);

	if(tree -> right != NULL)
		copyBST(tree -> right, copy);

	
}

/*******************************/
void addBST(bst* tree, int data)
{
	bst* node = malloc(sizeof(bst));
	node -> data = data;
	node -> right = NULL;
	node -> left = NULL;	

	if(tree -> data == INT_MIN) // if root is not entered yet
	{
		tree -> data = data;
		return;
	}

	if( (tree -> data) <= data) // if data should go to left
	{
		if( tree -> right == NULL)
		{
			tree -> right = node;
		}	
		else
			addBST(tree -> right, data);
	}
	else
	{
		if( tree -> left == NULL)
		{
			tree -> left = node;
		}	
		else
			addBST(tree -> left, data);
	}
	
	
}

/*********************************/
bst* deleteBST(bst* tree, int data)
{
	bst* tmp;
	if(tree == NULL)
		return tree;

	if(tree -> data > data)
		deleteBST(tree -> left, data);
	else if(tree -> data < data)
		deleteBST(tree -> right, data);
	else
	{
		if(tree -> left == NULL)
		{
			tmp = tree -> right;
			free(tree);
			return tmp;
		}
		else if(tree -> right == NULL)
		{
			tmp = tree -> left;
			free(tree);
			return tmp;
		}
		tmp = minValueNode(tree -> right); // find min node from right children
		tree -> data = tmp -> data;

		tree -> right = deleteBST(tree -> right, tmp -> data);//remove min node from right children
	}
	return tree;
}

/*********************************/
int findBST(bst* tree, int data)
{
	if(tree == NULL)
		return;

	if(tree -> left != NULL) 
	{	
		if(findBST(tree -> left, data))
			return 1;
	}
	
	if(tree -> right != NULL)
	{
		if(findBST(tree -> right, data))
			return 1;
	}

	if(tree -> data == data)
	{
		return 1;
	}
	else
		return 0;
}

/************************/
int findMax(bst* tree)
{
	bst* tmp = tree;
	int val;

	while(tmp != NULL)
	{
		val = tmp -> data;
		tmp = tmp -> right;
	}
	return val;
}

/************************/
int findMin(bst* tree)
{
	bst* tmp = tree;
	int val;

	while(tmp != NULL)
	{
		val = tmp -> data;
		tmp = tmp -> left;
	}
	return val;
}

/*******************************/
void printOrderedList(bst* tree)
{
	if(tree == NULL)
		return;
	if(tree -> left == NULL && tree -> right == NULL)
	{
		printf("%d ",tree -> data);
		return;
	}
	
	if(tree -> left != NULL)
		printOrderedList(tree -> left);

	printf("%d ",tree -> data);
	if(tree -> right != NULL)
		printOrderedList(tree -> right);
	
}

/***************************/
bst* minValueNode(bst* tree)
{
    bst* tmp = tree;
 
    while (tmp -> left != NULL)
        tmp = tmp -> left;
 
    return tmp;
}


#endif
