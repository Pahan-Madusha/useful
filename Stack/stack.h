#ifndef _STACK_
#define _STACK_

#include <stdlib.h>
#include <limits.h>

/*functions and data structure are implemented in the header file*/

typedef struct node
{
	int fwd_pos;
	int bck_pos;
	int data[SIZE];
	
}stack_node;

typedef stack_node* stack_ref;

//create a new stack
stack_ref stackCreate()
{
	stack_ref ref = malloc(sizeof(stack_node));
	(*ref).fwd_pos = 0;
	(*ref).bck_pos = SIZE-1;
	return ref;
}

//destroy an existing stack
int stackDestroy(stack_ref st)
{
	if(st != NULL)
	{
		free(st);
		return 1;
	}
	return 0;
}

//add a new element to stack A (forward)
int stackPushA(stack_ref st,int el)
{
	if(!StackIsFull(st))
	{		
		(*st).data[(*st).fwd_pos] = el;
		(*st).fwd_pos++;
		return 1;
	}

	return 0;
}


//add a new element to stack B (backward)
int stackPushB(stack_ref st,int el)
{
	if(!StackIsFull(st))
	{		
		(*st).data[(*st).bck_pos] = el;
		(*st).bck_pos--;
		return 1;
	}

	return 0;
}

//remove the last element of stack A
int stackPopA(stack_ref st)
{
	if(StackIsEmptyA(st))
	{
		return INT_MIN;
	}	
	(*st).fwd_pos--;
	return (*st).data[(*st).fwd_pos];
}

//remove the last element of stack B
int stackPopB(stack_ref st)
{
	if(StackIsEmptyB(st))
	{
		return INT_MIN;
	}	
	(*st).bck_pos++;
	return (*st).data[(*st).fwd_pos];
}

//peek at the top element of stack A
int stackPeekA(stack_ref st)
{
	if(StackIsEmptyA(st))
	{
		return INT_MIN;
	}	
	return (*st).data[(*st).fwd_pos-1];
}

//peek at the top element of stack B
int stackPeekB(stack_ref st)
{
	if(StackIsEmptyB(st))
	{
		return INT_MAX;
	}	
	return (*st).data[(*st).bck_pos+1];
}

//if stack A is empty 
int StackIsEmptyA(stack_ref st)
{
	if((*st).fwd_pos == 0)
		return 1;
	return 0;
}

//if stack B is empty 
int StackIsEmptyB(stack_ref st)
{
	if((*st).bck_pos == SIZE-1)
		return 1;
	return 0;
}

//if stack is full
int StackIsFull(stack_ref st)
{
	if((*st).fwd_pos > (*st).bck_pos)
		return 1;
	return 0;
}

#endif
