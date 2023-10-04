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
void dequeue(struct queue *ptr);
void enqueue(struct queue *ptr,int data);
int peek(struct queue *ptr);
int isempty(struct queue *ptr);
int isfull(struct queue *ptr);
int main()
        {
         struct queue sp;
         int size;
         cout<<"Enter the size of queue";
         cin>>size;
         create(&sp,size);
         sp.size=size;
         enqueue(&sp,3);
          cout<<sp.b;      
          peek(&sp);
          cout<<endl;
          cout<<isempty(&sp)<<endl<<isfull(&sp);
         return(0);
        }
void create(struct queue  *ptr,int size1)
{
    ptr->arr=new int[size1];
}
void dequeue(struct queue *ptr)
{
    if(ptr->b==-1)
    {
        cout<<"Queuw underflow";
    }
    else
    {
        for(int i=ptr->f;i<(ptr->b);i++)
        {
            swap(ptr->arr[i],ptr->arr[i+1]);
        }
    }
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
int peek(struct queue *ptr)
{
 return(ptr->arr[0]);   
}
int isempty(struct queue *ptr)
{
    if(ptr->b==-1)
    {
        return 1;
    }
    
    return 2;
}
int isfull(struct queue *ptr)
{
    if((ptr->b)==(ptr->size))
    {
        return 1;
    }
    
    return 0;
}