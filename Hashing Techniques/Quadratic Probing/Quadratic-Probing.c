#include<stdio.h>
#define size 10


int hash(int key)
{
	return key%size;
}

int probe(int H[],int key)
{
	int i=0;
	while(H[(key+i*i)%size]!=0)
	{
		i++;
	}
	return ((key+i*i)%size); 
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
	while(H[(key+i*i)%size]!=key)
	{
		if(H[(key+i*i)%size]==0)
		{
			return -1;
		}
		i++;
	}
	return ((key+i*i)%size);
}


int main()
{
	int HT[10]={0};
	Insert(HT,23);
	Insert(HT,43);
	Insert(HT,13);
	Insert(HT,17);
	int index = Search(HT,43);
	if(index!=-1)
		printf("\nKey found at index = %d",index);
	else
		printf("\nKey not found!");
}
