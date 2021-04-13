#include <stdio.h>
#include <string.h>

#define N 6
#define K 3

int store[K];

void print_array(int array[],int n);
void combination(int array[],int n, int k);

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
    combination(array,0,K);
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

void combination(int array[],int n, int k)
{
    if (k==0)
    {
        print_array(store,K);
        return;
    }

    for(int i=n;i<N;i++)
    {
        if ((k<K)&&(array[i]>store[K-k-1]))
        {
            store[K-k]=array[i];
            //printf("k=%d i=%d n=%d\n",k,i,n);
            combination(array,n+1,k-1);
        }
        if ((k==K))
        {
            store[K-k]=array[i];
            //printf("k=%d i=%d n=%d\n",k,i,n);
            combination(array,n+1,k-1);
        }
    }
}