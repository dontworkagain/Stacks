/*	
	Luís Martins
	29-12-2017
	myMiniHeap.c -o myMiniHeap
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAI(i) (i-1)/2
#define ESQ(i) (2*i)+1
#define DIR(i) (2*i)+2

struct heap
{
	int size;
	int used;
	int *vetor;
};

typedef struct heap* Heap;

Heap initHeap(int size)
{
	Heap h = malloc(sizeof(struct heap));
	h->size=size;
	h->used=0;
	h->vetor=malloc(sizeof(int)*size);
	return h;
}

void swap(int n[],int i, int pos)
{
	int temp;
	temp=n[i];
	n[i]=n[pos];
	n[pos]=temp;
}

int* duplica(Heap h)
{
	int *r=malloc(sizeof(int)*2*h->size);
	int i;
	for(i=0;i<h->size;i++)
	{
		r[i]=h->vetor[i];
	}
	h->size*=2;
	free(h->vetor);
	return r;
}

int bubbleUp(int v[], int pos)
{
	while(pos!=0 && v[pos]<v[PAI(pos)])
	{
		swap(v,pos,PAI(pos));
		pos=PAI(pos);
	}

return 0;
}

int bubbleDown(int v[], int inicio, int fim )
{
	int f = ESQ(inicio);
	while(f<fim)
	{
		if((f+1<fim)&&((v[f+1]<v[f])))
		{
			f=f+1;
		}
		if(v[f]>=v[inicio]) break;
		swap(v,inicio,f);
		inicio=f;
		f=2*inicio+1;
	}

}

int addElement(Heap h, int valor)
{
	if(h->size==h->used)
	{
		h->vetor=duplica(h);
		h->vetor[h->used]=valor;
		int pos = h->used++;
		bubbleUp(h->vetor,pos);
	}
	else
	{
		h->vetor[h->used]=valor;
		int pos = h->used++;
		bubbleUp(h->vetor,pos);
	}
	return 0;
}

int removeElement(Heap h, int *valor)
{
	if(h->used==0)
	{
		return -1;
	}
	else
	{
		*valor=h->vetor[0];
		swap(h->vetor,0,h->used-1);
		h->used--;
		bubbleDown(h->vetor,0,h->used);
	}
return 0;
}

int miniHeapOK(Heap h)
{
	int i;
	for(i=0;i<h->used;i++)
	{
		if(h->vetor[i]<h->vetor[PAI(i)])
		{
			return -1;
		}
	}
return 0;
}


int main()
{

	Heap h = initHeap(2);
	int r;
	addElement(h,3);
	addElement(h,5);
	addElement(h,7);
	addElement(h,10);
	addElement(h,11);
	addElement(h,8);
	addElement(h,15);
	addElement(h,20);
	addElement(h,17);
	addElement(h,2);

	
	int i;
	int n = h->used;
	int ord[n];
	printf("%d\n",n);
	for(i=0;i<h->used;i++)
	{
		printf("add: %d\n",h->vetor[i]);
	}

	printf("a ok esta OK\n");
	printf("%d\n",miniHeapOK(h));
	
	for(i=0;i<n;i++)
	{
		removeElement(h,&r);
		ord[i]=r;
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",ord[i]);
	}

printf("so far so good\n");
return 0;
}