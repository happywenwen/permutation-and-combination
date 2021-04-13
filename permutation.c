#include <stdio.h>
#include <string.h>

#define N 5
#define K 3

int store[K];

void permutation(int array[],int n,int k);
void print_array(int array[],int n);

int main()
{
	int array[N];

    for(int i=0;i<N;i++)
    {
        array[i]=i;
    }
	for(int i=0;i<K;i++)
	{
		store[i]=-1;
	}
    permutation(array,N,K);
	return 0;
}

void print_array(int a[],int n)
{
    for(int i =0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}

void permutation(int array[],int n,int k)
{
    if (k==0)
    {
        print_array(store,K);
        return;
    }

    for(int i=0;i<n;i++)
    {
		for(int p=K-k;p<K;p++)
		{
			store[p]=-1;
		}
		
		int check=0,checkk=0;
		for(int j=0;j<K;j++)
		{
			if (array[i]==store[j])
			{
				check++;
			}
			else
			{
				checkk++;
			}
			//printf("n=%d k=%d i=%d j=%d check=%d checkk=%d\n",n,k,i,j,check,checkk);
		}
		if (check==0)
		{
			store[K-k]=array[i];
			permutation(array,n,k-1);
		}
    }
    return ;
}