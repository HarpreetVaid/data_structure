#include<iostream>
#include<stdlib.h>
using namespace std;
struct queue
{
    int size;
    int *arr;
    int f=0,b=-1;
};
void create(struct queue  *ptr,int size);
 void enqueue(struct queue *ptr,int data);
int isempty(struct queue *ptr);
int dequeue(struct queue *ptr);
int main()
        {
         struct queue *sp;
         sp=new(struct queue);
         create(sp,5);
         sp->size=5;
       int  a [5][5]=
       {
         {0,1,0,0,1},
         {1,0,1,1,1},
         {0,1,0,1,0},
         {0,1,1,0,1},
         {1,1,0,1,0}
        };
        int i=1;
         int v[5];
         v[i]=1;
         enqueue(sp,i);
         cout<<i;
         while(!isempty(sp))
         {
         	int node=dequeue(sp);
         	for(int j=0;j<5;j++)
         	{
         		if(a[node][j]==1&&v[j]==0)
         		{
         		cout<<j;
         		v[j]=1;
         		enqueue(sp,j);
         		}
         	}
         }
         return(0);
        }
 void enqueue(struct queue *ptr,int data)
{
       if(ptr->b==(ptr->size-1))
       {
           cout<<"Queue Overflow";
       }
       else
       {
           ptr->b++;
           ptr->arr[ptr->b]=data;
       }
}
int isempty(struct queue *ptr)
{
    if(ptr->b==-1)
    {
        return 1;
    }
    
    return 0;
}
void create(struct queue  *ptr,int size1)
{
    ptr->arr=new int[size1];
}
int dequeue(struct queue *ptr)
{
    if(ptr->b==-1)
    {
        cout<<"Queue underflow";
    }
    else
    {     
        for(int i=ptr->f;i<(ptr->b);i++)
        {
            swap(ptr->arr[i],ptr->arr[i+1]);
        }
        ptr->b--;
        return ptr->arr[ptr->f];
    }
}