#ifndef _QUEUE_
#define _QUEUE_

/*data structure for queue*/
typedef struct 
{
	int capacity;
	int size;
	int front;
	int rear;
	int data[SIZE];
}que;

typedef que* que_ref;

/*Function prototypes*/

/*
  Allocate memory and create a new queue
  No arguments
  returns a pointer to a que
*/
que_ref queueCreate();

/*
  Free the memory allocated to queue
  Arguments - pointer to a que
  return 1 if successful
  return 0 otherwise
*/
int queueDestroy(que_ref q);

/*
  Add an element to the queue
  Arguments - pointer to que, integer
  return 1 if successful
  return 0 if queue if full
*/
int enqueue(que_ref q, int el);

/*
  Remove the least recently added element
  Arguments - pointer to a que
  Returns the removed element
  Returns INT_MIN if queue is empty
*/
int dequeue(que_ref q);

/*
  Get the least recently added element
  Arguments - pointer to a que
  Returns the element 
  Returns INT_MIN if queue is empty
*/
int queuePeek(que_ref q);

/*
  Check whether queue is empty
  Arguments - pointer to a que
  Returns 1 if queue is empty
  Returns 0 otherwise
*/
int queueIsEmpty(que_ref q);

/*
  Check whether queue is full
  Arguments - pointer to a que
  Returns 1 if queue is full
  Returns 0 otherwise
*/
int queueIsFull(que_ref q);


/****************************/
que_ref queueCreate()
{
	que_ref ref = malloc(sizeof(que));
	ref -> capacity = SIZE;
	ref -> size = 0;
	ref -> front = 0;
	ref -> rear = 0;

	return ref;
}

/****************************/
int queueDestroy(que_ref q)
{
	free(q);
	return 1;
}

/****************************/
int enqueue(que_ref q, int el)
{
	if(queueIsFull(q))
		return 0;
	
	(q -> size)++;
	(q -> data)[(q -> rear)] = el;
	(q -> rear)++;
	
	if( (q -> rear) == SIZE )
		(q -> rear) = 0;
		
	return 1;
}

/****************************/
int dequeue(que_ref q)
{
	if(queueIsEmpty(q))
		return INT_MIN;

	int val = (q -> data)[q -> front];
	(q -> front)++;

	if( (q -> front) == SIZE)
		q -> front = 0;
	
	(q -> size)--;

	return val;
}

/****************************/
int queuePeek(que_ref q)
{
	if(queueIsEmpty(q))
		return INT_MIN;
	
	return (q -> data)[(q -> front)];
}

/****************************/
int queueIsEmpty(que_ref q)
{
	if(q -> size == 0)
		return 1;
	return 0;
	
}

/****************************/
int queueIsFull(que_ref q)
{
	
	if(q -> size == SIZE)
		return 1;
	return 0;
}

#endif


