#include<stdio.h>
#define size 10
int hash1(int key)
{
	return key%size;
}

int hash2(int H[],int key)
{
	int i=0;
	while(H[(hash1(key)+(i*(7-(key%7))))%size]!=0)
	{
		i++;
	}
	return (hash1(key)+(i*(7-(key%7))))%size;
}

void Insert(int H[], int key)
{
	int index;
	index = hash1(key);
	if(H[index]!=0)
	{
		index = hash2(H,key);
	}
	H[index] = key;
}

int Search(int H[],int key)
{
	int i=0;
	while(H[(hash1(key)+(i*(7-(key%7))))%size]!=key)
	{
		if(H[(hash1(key)+(i*(7-(key%7))))%size]==0)
		{
			return -1;
		}
		i++;
	}
	return (hash1(key)+(i*(7-(key%7))))%size;
}

int main()
{
	int HT[10]={0};
	Insert(HT,5);
	Insert(HT,25);
	Insert(HT,15);
	Insert(HT,35);
	Insert(HT,95);
	
	int index = Search(HT,35);
	if(index!=-1)
	{
		printf("Element found at %d",index);
	}
	else
	{
		printf("Element not found");
	}
	return 0;
}
