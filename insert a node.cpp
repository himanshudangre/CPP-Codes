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


int count(struct node *p)
{
	int l=0;
	while(p)
	{
		l++;
		p=p->next;
	}
	return l;
}

int Rcount(struct node*p)
{
	if(p!= NULL)
		return Rcount(p->next)+1;
		
	else
		return 0;
}

void display(struct node *p)
{
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}


void insert(struct node *p,int index,int x)
{
	struct node *t;
	int i;
	if (index <0 || index > count(p))
		return;
	t=(struct node *)malloc(sizeof(struct node));
	t->data =x;
	if(index ==0)
	{
			t->next = first;
		first =t;
	}
		
	else
		for(i=0;i<index-1;i++)
			p=p->next;
		t->next =p->next;
		p->next=t;
}
int main()
{
	int A[]={3,5,7,10,15};
	
	create(A,5);
	insert(first,3,33);
	display(first);

	
	return 0;
}
