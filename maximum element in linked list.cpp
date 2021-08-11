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




int max(struct node *p)
{
	int max = -327888;
	while(p)
	{
		if(p->data>max)
			max=p->data;
		p=p->next;
	}
	return max;
}
int rmax(struct node *p)
{
	int x=0;
	if(p==0)
		return -32768; //INT32_MIN;
	x=rmax(p->next);
	if (x > p->data)
		return x;
	else 
		return p->data;
}

int main()
{
	int A[]={3,5,7,10,15};
	
	create(A,5);
	rdisplay(first);
	printf("max is %d\n",max(first));
	printf("max is %d\n",rmax(first));
	return 0;
}
