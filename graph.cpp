#include<iostream>
#include<stdlib.h>
using namespace std;
struct queue
{
    int size;
    int *arr;
    int f=0,b=-1;
};
class graph 
         {
           int *arr,*val,n;
           public :
             void creategraph(int n)
                   {
                 this->n=n;
                 arr=new int[n*n];
                val=new int[n];
                for(int i=0;i<n;i++)
                  {
            cout<<"\nEnter the "<<(i+1)<<"Element\n";
            cin>>val[i];
                  }  
                 int k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>=j)
            {
               cout<<"\nPress 1 if "<<val[i]<<"connected with"<<val[j]<<"else press 0\n";
              cin>>k;
              *(arr+ (i*n)+j) =*(arr+ (j*n)+j)=k;
              }
          }
      }
                   }
           void dfs(int a);
           void bfs(void);          
         };
      void graph :: dfs(int a)
                  {
               static int v[5];
               v[a]=1;
               cout<<a;
        for(int j=0;j<5;j++){
              if(*(arr+a*n+j)==1&&v[j]==0)
              {
              dfs(j);
              }
             }
            };
        void graph :: bfs(void)
        { 
        struct queue *sp;
        sp=new (struct queue);
        int i=1;
        int v[n];
         v[i]=1;
         enqueue(sp,i);
         cout<<i;
         while(!isempty(sp))
         {
         	int node=dequeue(sp);
         	for(int j=0;j<n;j++)
         	{
         		if(a[node][j]==1&&val[j]==0)
         		{
         		cout<<j;
         		val[j]=1;
         		enqueue(sp,j);
         		}
         	}
         }
        };

void create(struct queue  *ptr,int size);
void enqueue(struct queue *ptr,int data);
int isempty(struct queue *ptr);
int dequeue(struct queue *ptr);
int main()
             {
                 graph a;
                 a.creategraph();
                 cout<<"DFS is\n";
                 dfs(arr,val);
                 cout<<endl;
                 cout<<"BFS is\n";
                 dfs(arr,val);
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