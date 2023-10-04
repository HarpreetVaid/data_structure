#include<iostream>
#include <stdlib.h>
using namespace std;
class queue{
   int size;
    int *arr;
    int f=0,b=-1;
   public:
    queue(int n){
    	 size=n;
    	 arr=new int[n];
    }
 void enqueue(int data)
{
       if( b==( size-1))
       {
           cout<<"Queue Overflow";
       }
       else
       {
            b++;
            arr[b]=data;
       }
}
int isempty()
{
    if( b==-1)
    {
        return 1;
    }  
    return 0;
}
int dequeue()
{
    if(b==-1)
    {
        cout<<"Queue underflow";
    }
    else
    {     
        for(int i=f;i<(b);i++)
        {
            swap(arr[i],arr[i+1]);
        }
         b--;
        return arr[f];
    }
}
int peek()
{
    return(arr[f]);
}
	};
class graph{
	int node;
	int *mat;
	int *val;
	int *v;
	public :
	void create(){
		cout<<"Enter the total no. of node \n";
		cin>>node;
	    mat=new int[node*node];
	    val=new int[node];
	    int k;
	       v= new int[node];
	     for(int i=0;i<node;i++){
             	v[i]=0;
             }
	      for(int i=0;i<node;i++)
    {
        cout<<"\nEnter the  "<<(i+1)<<" Element\n";
        cin>>val[i];
    }
	     for(int i=0;i<node;i++)
        {
        for(int j=0;j<node;j++)
        {
            if(i==j)
            {
                *(mat+(j*node)+i)=0;
            }
            if(i>j)
            {
               cout<<"\nPress 1 if "<<val[i]<<" connected with "<<val[j]<<" else press 0\n";
              cin>>k;
              *(mat+(i*node)+j)= *(mat+(j*node)+i)=k;
              }
          }
      } 
		}
void dfs(int a=0)
{
    v[a]=1;
    cout<<val[a];
    for(int j=0;j<node;j++)
           {
             if(*(mat+(a *node)+j)==1&&v[j]==0)
             {
             this->dfs(j);
             }
           }
}
void bfs()
     {
             for(int i=0;i<node;i++){
             	v[i]=0;
             }
             class queue sp(node);
             int i=0;
            v[i]=1;
         sp.enqueue(i);
         cout<<val[i];
         while(!sp.isempty())
         {
             int p=sp.peek();
         	sp.dequeue();
         	for(int j=0;j<node;j++)
         	{
         		if(*(mat+(node*p)+j)==1&&v[j]==0)
         		{
         		cout<<val[j];
         		v[j]=1;
         		sp.enqueue(j);
         		}
         	}
         }
      for(int i=0;i<node;i++){
             	v[i]=0;
             }
     }
};
int main(	)
{
	graph g1;
	g1.create();
	cout<<"\nThe bfs is : ";
	g1.bfs();
	cout<<"\nThe dfs is :";
	g1.dfs();
}