#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL;

void sortedInsert(struct Node **H,int key)
{
	struct Node *temp,*q=NULL,*p=*H;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = key;
	temp->next = NULL;
	if(*H==NULL)
	{
		*H = temp;
	}
	else
	{
		while(p && key>p->data)
		{
			q = p;
		    p = p->next;
		}
		if(p==*H)
		{
			temp->next = *H;
			*H = temp;
		}
		else
		{
			temp->next = q->next;
			q->next = temp;
		}
	}
}

void display(struct Node **H)
{
	struct Node *p=*H;
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
}

int hashfunction(int key)
{
	return key%10;
}

void Insert(struct Node *HT[],int key)
{
	int index = hashfunction(key);
	sortedInsert(&HT[index],key);
}

struct Node * Search(struct Node *p, int key)
{
	while(p)
	{
		if(key==p->data)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

int main()
{
	struct Node *HT[10];
	int i;
	for(i=0;i<10;i++)
	{
		HT[i] = NULL;
	}
	
	Insert(HT,12);
	Insert(HT,155);
	Insert(HT,5);
	Insert(HT,11);
	struct Node *temp;
	temp = Search(HT[hashfunction(155)],155);
	if(temp->data)
	{
		printf("%d ",temp->data);
	}
	else
	{
		printf("Element not found");
	}
	return 0;
}
