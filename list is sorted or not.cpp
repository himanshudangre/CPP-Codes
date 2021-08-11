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

int issorted(struct node *p)
{
	int x= -65536;
	while(p!=NULL)
	{
		if(p->data < x)
			return 0;
		x=p->data;
		p=p->next;
	}	
	return 1;
}
int main()
{
	int A[]={3,8,7,9,15};
	create(A,5);
	
	printf("%d\n",issorted(first));
	if(issorted(first))
	{
		printf("sorted\n");;
	}
	else
	{
		printf("not sorted\n");
	}
	
	rdisplay(first);
	return 0;
}
