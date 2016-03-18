#define SIZE 1000

#include <stdio.h>
#include "stack.h"
#include <string.h>

//define the stack size here


int main()
{
	int i;
	
	stack_ref a = stackCreate();
	
	printf("Pushing elements to the stack\n");
	stackPush(a,1);
	stackPush(a,2);
	stackPush(a,3);
	stackPush(a,4);
	stackPush(a,5);
	stackPush(a,6);
	stackPush(a,7);
	stackPush(a,8);
	stackPush(a,9);
	stackPush(a,10);

	printf("Popping elements from the stack\n");
	for(i = 0; i<10; i++)
	{
		printf("%d\n",stackPop(a));
	}

	printf("Pushing same elements to the stack\n");
	stackPush(a,1);
	stackPush(a,2);
	stackPush(a,3);
	stackPush(a,4);
	stackPush(a,5);
	stackPush(a,6);
	stackPush(a,7);
	stackPush(a,8);
	stackPush(a,9);
	stackPush(a,10);

	printf("Reversing the stack..\n");
	stackReverseIter(a); // Calling iterative function

	printf("Popping elements from the stack\n");
	for(i = 0; i<10; i++)
	{
		printf("%d\n",stackPop(a));
	}

	return 0;
}
