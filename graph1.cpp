#include<iostream>
#include<stdlib.h>
using namespace std;
struct queue
{
    int size;
    int *arr;
    int f=0,b=-1;
};
int *creategraph(int n,int *val);
int *getnodeval(int elem);
void dfs(int *arr,int *val,int v[],int a=0);
void bfs(int*arr,int *val,int n);
void create(struct queue  *ptr,int size);
void enqueue(struct queue *ptr,int data);
int isempty(struct queue *ptr);
void dequeue(struct queue *ptr);
int peek(struct queue *ptr);
int main()
             {
                 int *arr,*val,node;
                 cout<<"Enter the total no.of node\n";
                 cin>>node;
                 val=getnodeval(node);
                 arr=creategraph(node,val);
                   for(int i=0;i<node;i++)
                 {
                     for(int j=0;j<node;j++)
                     {
                         cout<<*(arr+(i*node)+j)<<" ";
                     }
                     cout<<endl;
                 }
                 cout<<"DFS is\n";
                 int *v;
                 v=new int[node];
                 dfs(arr,val,v);
                 free(v);
                 cout<<endl;
                 cout<<"BFS is\n";
                 bfs(arr,val,node);
                 cout<<endl;
                 return 0;
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
int peek(struct queue *ptr)
{
    return(ptr->arr[ptr->f]);
}
void dequeue(struct queue *ptr)
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
    }
}
int *creategraph(int n,int *val)
{
    int *arr=new int[n*n];
    int k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                *(arr+(j*n)+i)=0;
            }
            if(i>j)
            {
               cout<<"\nPress 1 if "<<val[i]<<"connected with "<<val[j]<<" else press 0\n";
              cin>>k;
              *(arr+(i*n)+j)= *(arr+(j*n)+i)=k;
              }
          }
      }  
    return arr;
}
int *getnodeval(int n)
{
    int *val;
    val=new int[n];
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter the  "<<(i+1)<<" Element\n";
        cin>>val[i];
    }
    return val;
}
void dfs(int *arr,int *val,int v[],int a)
{
    int l=sizeof(arr)/sizeof(val);
    v[a]=1;
    cout<<val[a];
    for(int j=0;j<5;j++)
           {
             if(*(arr+(a*l)+j)==1&&v[j]==0)
             {
             dfs(arr,val,v,j);
             }
            }
}
void bfs(int*arr,int *val,int l)
     {
             struct queue *sp;
             sp=new (struct queue); 
             int v[l];
             int i=0;
            v[i]=1;
            create(sp,l);
         enqueue(sp,i);
         cout<<val[i];
         while(!isempty(sp))
         {
         	int node=peek(sp);
         	dequeue(sp);
         	for(int j=0;j<5;j++)
         	{
         		if(*(arr+(node*l)+j)==1&&v[j]==0)
         		{
         		cout<<val[j];
         		v[j]=1;
         		enqueue(sp,j);
         		}
         	}
         }
     }