#include<iostream>
#include<stdlib.h>
struct node{      
          int data;
          struct node *next;
          };
struct node * create();
void printlinkedlist(struct node *ptr);
struct node * reverse(struct node *ptr);
         int main()
                   {
                struct node *start;
                start=create();
                printlinkedlist(start);
               start= reverse(start);
                printlinkedlist(start);
                return 0;
                   }
       struct node * create()
                    {
      struct node *start,*p,*q;
      int i=0;
      p=(struct node *)malloc(sizeof(struct node));
      start=p;
      printf("Enter the data   ");
      scanf("%d",&p->data);
      printf("Press 1 for enter another no. and 0 for exit");
      scanf("%d",&i);
      while(i!=0)
      {
       q=(struct node *)malloc(sizeof(struct node));
       printf("Enter the data   ");
       scanf("%d",&q->data);
       p->next=q;
       p=q;
       printf("Press 1 for enter another no. and 0 for exit");
       scanf("%d",&i);
      }
      p->next=NULL;
       return(start);
                    }
void printlinkedlist(struct node *ptr)
                        {
                   printf("\nThe data is\n");
                   while(ptr!=NULL)
                        {
                      printf("\n %d",ptr->data);
                      ptr=ptr->next;
                         }
                         }
 struct node * reverse(struct node *ptr)
 {
     struct node *prev=NULL,*currentnode,*nextnode;
     currentnode=nextnode=ptr;
     while(nextnode!=NULL)
     {
         nextnode=nextnode->next;
         currentnode->next=prev;
         prev=currentnode;
         currentnode=nextnode;
     }
     return(prev);
 }
 
   