#include<stdio.h>
#define size 10


int hash(int key)
{
	return key%size;
}

int probe(int H[],int key)
{
	int i=0;
	while(H[(key+i)%size]!=0)
	{
		i++;
	}
	return ((key+i)%size); 
}

void Insert(int H[],int key)
{
	int index = hash(key);
	if(H[index]!=0)
	{
		index = probe(H,key);
	}
	H[index] = key;
}

int Search(int H[],int key)
{
	int i=0;
	while(H[(key+i)%size]!=key)
	{
		if(H[(key+i)%size]==0)
		{
			return -1;
		}
		i++;
	}
	return ((key+i)%size);
}


int main()
{
	int HT[10]={0};
	Insert(HT,12);
	Insert(HT,5);
	Insert(HT,25);
	Insert(HT,11);
	Insert(HT,22);
	int index = Search(HT,22);
	if(index!=-1)
		printf("\nKey found at index = %d",index);
	else
		printf("\nKey not found!");
}
