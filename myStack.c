/*	
	Luís Martins
	28-12-2017
	myStack.c -o myStack
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
	int size;
	int used;
	int *vetor;	
};
typedef struct stack* Stack;

Stack initStack(int size)
{
	Stack s = malloc(sizeof(struct stack));
	s->size=size;
	s->used=0;
	s->vetor=malloc(sizeof(int)*size);
	return s;
}

int isEmpty(Stack s)
{
	return(s->size==s->used);
}


int* duplica(Stack s)
{
	int *r=malloc(sizeof(int)*s->size*2);
	s->size*=2;
	int i;
	for(i=0;i<s->size;i++)
	{
		r[i]=s->vetor[i];
	}
	free(s->vetor);
	return r;
}

void addElement(Stack s,int n)
{
	if(s->used==s->size)
	{
		s->vetor=duplica(s);
		s->vetor[s->used++]=n;
	}
	else
	{
		s->vetor[s->used++]=n;
	}

}

int removeElement(Stack s, int *r)
{
	if(isEmpty(s))
	{
		return -1;
	}
	else
	{
		int i;
		/*for(i=0;i<s->used;i++)
		{
			printf("existem: %d\n",s->vetor[i]);
		}
		*/
		*r=s->vetor[--s->used];
		/*printf("removemos: %d\n",*r);
		for(i=0;i<s->used;i++)
		{
			printf("restaram: %d\n",s->vetor[i]);
		}
		*/
	}
	return 0;
}


int main()
{
	int e;
	Stack s = initStack(2);
	addElement(s,2);
	addElement(s,3);
	addElement(s,4);
	addElement(s,5);
	addElement(s,6);
	addElement(s,7);
	addElement(s,8);
	addElement(s,9);
	addElement(s,10);
	
	int i;
	printf("Adicionamos: \n");
	for(i=0;i<s->used;i++)
	{
		printf("add: %d\n",s->vetor[i]);
	}
	printf("eliminamos: \n");
	for(i=0;i<5;i++)
	{
		removeElement(s,&e);
		printf("removidos: %d\n",e);
	}
	printf("Actualizados \n");
	for(i=0;i<s->used;i++)
	{
		printf("%d\n",s->vetor[i]);
	}

printf("so far so good\n");
	return 0;
}