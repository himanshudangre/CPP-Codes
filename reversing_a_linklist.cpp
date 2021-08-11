#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*first = NULL;

//fun for creating a lik=nked list

void create ( int A[],int n)
{
	int i;
	struct node *t,*last;
	first = (struct node*)malloc(sizeof(struct node));
	first->data=A[0];
	first ->next=NULL;
	last =first;
	
	for(i=1;i<n;i++)
	{
		t=(struct node*)malloc(sizeof(struct node));
		t->data=A[i];
		t->next = NULL;
		last->next=t;
		last=t;

	}
}	
void rdisplay(struct node *p)
{
	if(p!=NULL)
	{
		printf("%d ",p->data);
		rdisplay(p->next);
	}
}

int count(struct node *p)
{
	int l=0;
	while(p)
	{
		l++;
		p=p->next;
	}
	return 1;
}

void reverse1(struct node *p)
{
	int *A ,i=0;
	struct node *q;
	
	A=(int *)malloc(sizeof (int )*count(p));
	
	while(q!=NULL)
	{
		A[i]=q->data;
		q=q->next;
		i++;
	}
	q=p;
	i--;
	while(q!=NULL)
	{
		q->data=A[i];
		q=q->next;
		i--;
	}
}

int main()
{
	int A[]={1,2,3,4,5,8,6};
	create(A,7);
	reverse1(first);
	rdisplay(first);
	return 0;
}
