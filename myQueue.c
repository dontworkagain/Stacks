/*	
	Luís Martins
	28-12-2017
	myQueue.c -o myQueue
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue
{
	int inicio;
	int used;
	int size;
	int *vetor;	
};

typedef struct queue* Queue;

Queue initQueue(int size,int inicio)
{
	Queue q=(Queue)malloc(sizeof(struct queue));
	q->size=size;
	q->inicio=inicio;
	q->used=0;
	q->vetor=malloc(sizeof(int)*size);
	return q;
}

int isEmpty(Queue q)
{
	return(q->used==0);
}

int* duplica(Queue q)
{
	int *r=malloc(sizeof(int)*q->size*2);
	int i;
	for(i=0;i<q->used;i++)
	{
		r[(i+q->inicio)%q->size]=q->vetor[(i+q->inicio)%q->size];
	}
	q->size*=2;
	free(q->vetor);
	return r;

}


void addElement(Queue q, int n)
{
	if(q->size==q->used)
	{
		q->vetor=duplica(q);
		q->vetor[(q->inicio+q->used)%q->size]=n;
		q->used++;
	}
	else
	{
		q->vetor[(q->inicio+q->used)%q->size]=n;
		q->used++;
	}
}

int removeElement(Queue q, int *r)
{
	if(isEmpty(q))
	{
		return -1;
	}
	else
	{

		*r=q->vetor[q->inicio%q->size];
		q->inicio++;
		q->used--;
	}
	return 0;

}



int main()
{
Queue q = initQueue(8,2);

addElement(q,2);
addElement(q,3);
addElement(q,4);
addElement(q,5);
addElement(q,6);
addElement(q,7);
addElement(q,8);
addElement(q,9);
addElement(q,10);
addElement(q,11);
addElement(q,12);
addElement(q,13);


int i;
for(i=0;i<q->used;i++)
{
	printf("add: %d\n",q->vetor[(q->inicio+i)%q->size]);
}

int r;
removeElement(q,&r);
printf("removi: %d\n",r);
for(i=0;i<q->used;i++)
{
	printf("restaram: %d\n",q->vetor[(q->inicio+i)%q->size]);
}


printf("so far so good\n");
return 0;
}