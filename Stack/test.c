#define SIZE 10

#include <stdio.h>
#include "stack.h"
#include <string.h>


int main()
{
	int i;
	stack_ref st = stackCreate(); // new double stack

	printf("Size of the double stack - %d\n\n",SIZE);
	printf("Pushing elements to stack A...\n");
	for(i = 0; i<6; i++)
	{	
		printf("Pushing %d to A\n",i);
		if(!stackPushA(st,i))
		{
			printf("Pushing unsuccessful, Memory full!\n\n");
			break;		
		}
	}
	
	printf("\n");
	printf("Pushing elements to stack B...\n");
	for(i = 100; i<106; i++)
	{
		printf("Pushing %d to B\n",i);
		if(!stackPushB(st,i))
		{
			printf("Pushing %d unsuccesful, Memory full!\n\n",i);
			break;		
		}
	}

	printf("\n");
	printf("Last element of: \nstack A - %d \nstack B - %d\n\n",stackPeekA(st),stackPeekB(st));
	printf("Pop stack A\n\n");	
	stackPopA(st);

	printf("Last element of: \nstack A - %d \nstack B - %d\n\n",stackPeekA(st),stackPeekB(st));

	printf("Add 115 to stack B\n\n");
	stackPushB(st,115);
	printf("Last element of: \nstack A - %d \nstack B - %d\n",stackPeekA(st),stackPeekB(st));
	return 0;
}
