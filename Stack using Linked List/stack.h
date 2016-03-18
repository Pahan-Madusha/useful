#ifndef _STACK_
#define _STACK_

#include <stdlib.h>
#include <limits.h>
#include "linked_list.h"

/*functions and data structure are implemented in the header file*/

/*Data structure for stack*/
typedef struct node
{
	node_ref list;
	int size;
	
}stack_node;

typedef stack_node* stack_ref;


//function prototypes

/*Allocate memory and create a stack
  NO arguments
  Returns a reference to the stack*/
stack_ref stackCreate();

/*Free the memory allocated for the stack
  Arguments - Pointer to the stack
  Return 1 on success*/
int stackDestroy(stack_ref st);

/*Insert an element to the stack
  Arguments - pointer to the stack, integer
  Return 1 on success*/
int stackPush(stack_ref st,int el);

/*Remove the last inserted element from the stack
  Arguments - pointer to the stack
  Returns the element on success
  Returns INT_MIN if stack is empty*/
int stackPop(stack_ref st);

/*Arguments - pointer to the stack
  Return the last inserted element of the stack
  Return INT_MIN if stack is empty*/
int stackPeek(stack_ref st);

/*Arguments - Pointer to the stack
  Return 1 if stack is empty
  0 otherwise*/
int StackIsEmpty(stack_ref st);

/*reverse the elements in the stack with recursion
  Arguments - Pointer to the stack and 0
  usage: stackReverseRec(stack_ref,0);
  return 1 on success
  return 0 if stack is empty
*/
int stackReverseRec(stack_ref st, int pos);

/*reverse the elements in the stack without recursion
  Arguments - Pointer to the stack
  return 1 on success
  return 0 if stack is empty
*/
int stackReverseIter(stack_ref st);

/*Swap the elements of the stack in p1 and p2 positions
  Arguments - pointer to the stack, integer(position1), integer(position2)
  Return 1 on success*/
int swap(stack_ref st, int p1, int p2);


/*Function implementations*/
/**********************************************************************************/
//create a new stack
stack_ref stackCreate()
{
	stack_ref ref = malloc(sizeof(stack_node));
	ref -> size = 0;
	return ref;
}

/**********************************************************************************/
//destroy an existing stack
int stackDestroy(stack_ref st)
{
	erase_list(&(st -> list));
	free(st);
	return 1;
}

/**********************************************************************************/
//add a new element
int stackPush(stack_ref st,int el)
{
	add_node(&(st -> list),el);
	(st -> size)++;
	return 1;

}

/**********************************************************************************/
//remove the last element
int stackPop(stack_ref st)
{
	if(StackIsEmpty(st))
	{
		return INT_MIN;
	}	
	int ans = stackPeek(st);
	remove_last_node(&(st -> list));
	(st -> size)--;

	return ans;
}

/**********************************************************************************/
//peek at the top element
int stackPeek(stack_ref st)
{
	if(StackIsEmpty(st))
	{
		return INT_MIN;
	}	
	return peak_last_node(&(st -> list));
}

/**********************************************************************************/
//if stack is empty
int StackIsEmpty(stack_ref st)
{
	if(st -> list == NULL)
		return 1;
	return 0;
}

/**********************************************************************************/
//reverse stack using recursion
//usage: stackReverseRec(stack_ref,0);
int stackReverseRec(stack_ref st, int pos)
{
	if(StackIsEmpty(st))
		return 0;
	int size = st -> size;
	
	if(size/2 == pos)
	{
		swap(st,pos,size-1-pos);
		return 1;
	}
	
	swap(st,pos,size-1-pos);
	pos++;
	stackReverseRec(st,pos);
	
}

/**********************************************************************************/
//reverse stack without recursion
int stackReverseIter(stack_ref st)
{
	if(StackIsEmpty(st))
		return 0;
	int i;
	int size = st -> size;
	for(i = 0; i<size/2; i++)
	{
		swap(st,i,size-1-i);
	}
	return 1;
}


/**********************************************************************************/
//swap the given 2 positions
int swap(stack_ref st, int p1, int p2)
{
	if(p1 == p2)
		return 1;

	int tmp,i;
	node_ref pos1 = st -> list;
	node_ref pos2 = st -> list;

	for(i = 0; i<p1; i++)
	{
		pos1 = pos1 -> next;
	}
	for(i = 0; i<p2; i++)
	{
		pos2 = pos2 -> next;
	}
	
	tmp = pos1 -> data;
	pos1 -> data = pos2 -> data;
	pos2 -> data = tmp;
	
	return 1;
}

#endif





