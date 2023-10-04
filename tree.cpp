#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};
struct node *createtree();
void printinorder(struct node *tree);
void printpostorder(struct node *tree);
void printpreorder(struct node *tree);
struct node *insert(int i);
int checkbst(struct node *root);
int total(struct node *root);
int bstsearch(struct node *root, int data);
int minbst(struct node *root);
int maxbst(struct node *root);
void insertnode(struct node *root,int key);
int delnode(struct node *root,int data);
int predessor(struct node *root);
void printtree(struct node *root);
void print1(struct node *root,int sp);
int main()
{
    struct node *root = createtree();
    cout << "\n Inorder is\n";
    printinorder(root);
    cout << "\n Preorder is\n";
    printpreorder(root);
    cout << "\n Postorder is\n";
    printpostorder(root);
    cout << endl;
    cout << "\ntotal no. node is     " << total(root);
    if (!checkbst(root))
    {
        cout << "\ntree is not bst";
    }
    else
    {
        cout << "\ntree is bst";
         int a;
        cout << "\nEnter the data to search\n";
        cin >> a;
        if (bstsearch(root, a))
        {
            cout << "Element found\n";
        }
        else
        {
            cout << "Element not found\n";
        }
        cout<<"Maximum value in tree is  "<<maxbst(root)<<"  and minimum is  "<<minbst(root)<<endl;
    }
    int a;
     cout << "\nEnter the data to insert\n";
      cin >> a; 
      insertnode(root,a);
      cout<<"\n The data after inserting \n";
      printinorder(root);
      cout << "\nEnter the data to delete\n";
      cin >> a; 
      delnode(root,a);
      cout<<"\n The data after deletion \n";
      printinorder(root);
      printtree(root);
    return 0;
}
struct node *createtree()
{
    struct node *root;
    root = new (struct node);
    cout << "Enter the root data.   ";
    cin >> root->data;
    cout << endl;
    cout << "-------Left sub tree-------\n";
    cout << "Enter the root left data of depth 1   " << endl;
    root->left = insert(2);
    cout << "-------Right sub tree-------\n";
    cout << "Enter the root right data of depth 1 " << endl;
    root->right = insert(2);
    return root;
}
struct node *insert(int i)
{
    int a;
    cout << "Press 1 to Create a Node or 0 to end" << endl;
    cin >> a;
    if (a == 1)
    {
        struct node *ptr;
        ptr = new (struct node);
        cout << "Enter the data" << endl;
        cin >> ptr->data;
        cout << "Enter the left data have depth" << i << endl;
        ptr->left = insert(i + 1);
        cout << "Enter the right data have depth " << i << endl;
        ptr->right = insert(i + 1);
        return ptr;
    }
    else
    {
        return NULL;
    }
}
void printinorder(struct node *tree)
{
    if (tree != NULL)
    {
        printinorder(tree->left);
        cout << "  ";
        printf("%d", tree->data);
        cout << "    ";
        printinorder(tree->right);
    }
}
void printpreorder(struct node *tree)
{
    if (tree != NULL)
    {
        cout << "  ";
        printf("%d", tree->data);
        cout << "    ";
        printpreorder(tree->left);
        printpreorder(tree->right);
    }
}
void printpostorder(struct node *tree)
{
    if (tree != NULL)
    {
        printpostorder(tree->left);
        printpostorder(tree->right);
        cout << "  ";
        printf("%d", tree->data);
        cout << "    ";
    }
}
int checkbst(struct node *root)
{
  static  struct node *pre=NULL;
    if (root == NULL)
    {
        return 1;
    }
    else
    {
        if (!checkbst(root->left))
        {
            return 0;
        }
        if (pre!=NULL&&(root->data <pre->data))
        {
            return 0;
        }
        pre = root;
        return (checkbst(root->right));
    }
}
int total(struct node *root)
{
    int res = 0;
    if (root != NULL)
    {
        res++;
        res += total(root->left);
        res += total(root->right);
    }
            return res;
        }
int bstsearch(struct node * root, int data)
        {
            if (root == NULL)
            {
                return 0;
            }
            else if (root->data == data)
            {
                return 1;
            }
            else if (root->data > data)
            {
                return (bstsearch(root->left, data));
            }
            else
            {
                return (bstsearch(root->right, data));
            }
        }
        int minbst(struct node * root)
        {
            if (root->left == NULL)
            {
                return root->data;
            }
          return minbst(root->left);
        }
        int maxbst(struct node * root)
        {
            if (root->right == NULL)
            {
                return root->data;
            }
            return maxbst(root->right);
        }
void insertnode(struct node *root,int key)
{
  if(!bstsearch(root,key))
  {
    struct node *pre;
    while(root!=NULL)
    {
      pre=root;
      if(root->data>key)
      {
         root=root->left;  
      }
      else
      {
        root=root->right;
      }
    }
  if(pre->data<key)
  {
    root=new (struct node);
    pre->right=root;
    root->data=key;
  }
  else 
  {
    root=new (struct node);
    pre->left=root;
    root->data=key;  
  }
  }
}
int delnode(struct node *root,int data)
{
        while(root->data!=data)
        {
            if(root->data>data)
            {
                root=root->left;
            }
            else if(root->data<data)
            {
                root=root->right;
            }
            else
            {
                break;
            }
    }
    if(root!=NULL)
    {
     if((root->left==NULL)||(root->right==NULL)) 
    {
                struct node *temp;
                temp=root->left;
                if(root->right!=NULL)
                {
                    temp=root->right;
                }
                if(temp==NULL)
                {
                    temp=root;
                    root=NULL;
                }
                else
                  *root=*temp;
                free(temp);
            }
    else
    {
              int pred;
              pred=predessor(root);
              root->data=pred;
             delnode(root->left,pred);
             return 1;   
    }
    }
    return 1;
}
int predessor(struct node *root)
{
    root=root->left;
    while(root->right!=NULL)
    root=root->right;
    return root->data;
}
void printtree(struct node *root)
{
    print1(root,0);
}
void print1(struct node *root,int sp)
{
    sp=sp+2;
    if(root==NULL)
    {
        return;
    }
    print1(root->right,sp);
    for(int i=0;i<sp;i++)
    {
        cout<<"  ";
    }
    cout<<root->data<<"\n\n\n\n";
    print1(root->left,sp);
}