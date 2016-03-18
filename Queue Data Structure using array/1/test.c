#define SIZE 9
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"


int main()
{
	int i;
	que_ref q = queueCreate();//new queue

	printf("Queue size - %d\n",SIZE);
	printf("Pushing elements to queue\n\n");
	
	for(i = 0; i<10; i++)
		if( enqueue(q,i+1) )
			printf("Pushed %d successfully!\n",i+1);
		else
			printf("Pushing %d unsuccessful. Queue is full!\n",i+1);

	printf("\n");
	
	for(i = 0; i<10; i++)
		if( queuePeek(q) != INT_MIN )
			printf("Dequeue - %d\n",dequeue(q));
		else
			printf("Dequeue unsuccessfull. Queue if empty!\n");

	/************************************************************************/
	printf("\n\n");
	printf("Pushing elements to queue again\n\n");
	
	for(i = 0; i<10; i++)
		if( enqueue(q,i+100) )
			printf("Pushed %d successfully!\n",i+100);
		else
			printf("Pushing %d unsuccessful. Queue is full!\n",i+100);

	printf("\n");
	
	printf("Dequeuing 5 elements\n");
	for(i = 0; i<5; i++)
		if( queuePeek(q) != INT_MIN )
			printf("Dequeue - %d\n",dequeue(q));
		else
			printf("Dequeue unsuccessfull. Queue if empty!\n");

	printf("\n");
	/*push again*/
	printf("Pushing 6 elements again\n");
	for(i = 0; i<6; i++)
		if( enqueue(q,i+200) )
			printf("Pushed %d successfully!\n",i+200);
		else
			printf("Pushing %d unsuccessful. Queue is full!\n",i+200);
	
	
	printf("\n");
	printf("Dequeueing all elements\n");
	/*remove all*/
	for(i = 0; i<9; i++)
		if( queuePeek(q) != INT_MIN )
			printf("Dequeue - %d\n",dequeue(q));
		else
			printf("Dequeue unsuccessfull. Queue if empty!\n");
	return 0;
}
