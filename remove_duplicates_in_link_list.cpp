#include<stdio.h>
#include<stdlib.h>

struct node
{
	int daa;
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
void removeduplicate(struct node *p)
{
	struct node *q=p->next;
	 while (q!=NULL)
	 {
	 	if(p->data!=q->data)
	 	{
	 		p=q;
	 		q=q->next;
	
		}
	 	else
	 	{
	 		p->next=q->next;
			free(q);
			q=p->next;
			 	
		}
	 }
}

int main()
{
	int A[]={1,2,3,4,5,6,6};
	create(A,7);
	removeduplicate(first);
	rdisplay(first);
	return 0;
}
