#include<iostream>
#include<stdlib.h>
using namespace std;
void dfs(int a,int arr[][5])
{
  static int v[5];
  v[a]=1;
  cout<<a;
    for(int j=0;j<5;j++)
           {
             if(arr[a][j]==1&&v[j]==0)
             {
             dfs(j,arr);
             }
             }
         }    
int main()
        {
int a [5][5]={
//int *a= new int[5*5];
  //    a= { 
         {0,1,0,0,1},
         {1,0,1,1,1},
         {0,1,0,1,0},
         {0,1,1,0,1},
         {1,1,0,1,0}
        };
        dfs(4,a);
         return(0);
        }