#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;
struct node
{
    int data, height;
    struct node *left, *right;
};
struct node *createtree();
struct node *insert(int i);
int getheight(struct node *root);
int maxheight(int a, int b)
{
    return (a > b) ? a : b;
}
struct node *getbalance(struct node *root);
struct node *leftrotate(struct node *root);
struct node *rightrotate(struct node *root);
int assignheight(struct node *root);
struct node *dobalance(struct node *root);
int getheight(struct node *root);
int baf(struct node *root);
void printtree(struct node *root);
void print1(struct node *root, int sp);
void printTree(struct node *root, string indent, bool last);
int checkavl(struct node *root);
int main()
{
    struct node *root;
    root = createtree();
    root->height = assignheight(root);
    cout << endl;
    printTree(root, "", true);
    cout << "\n";
    printtree(root);
    while(checkavl(root)!=1)
    {
    root = dobalance(root);
    }
    cout << endl;
    printTree(root, "", true);
    cout << "\n";
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
    root->left = insert(1);
    cout << "-------Right sub tree-------\n";
    cout << "Enter the root right data of depth 1 " << endl;
    root->right = insert(1);
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
struct node *getbalance(struct node *root)
{
    int a;
    a = baf(root);
    if (a > 1)
    {
        if (baf(root->left) == -1)
        {
            root->left = rightrotate(root->left);
            root = leftrotate(root);
            return root;
        }
        else
        {
            root = leftrotate(root);
            return root;
        }
    }
    if (a < -1)
    {
        if (baf(root->right) == 1)
        {
            root->right = leftrotate(root->right);
            root = rightrotate(root);
            return root;
        }
        else
        {
            root = rightrotate(root);
            return root;
        }
    }
    return root;
}
struct node *leftrotate(struct node *x)
{
    struct node *y, *t;
    y = x->left;
    t = y->right;
    x->left = t;
    y->right = x;
    x->height = maxheight(getheight(x->left), getheight(x->right)) + 1;
    y->height = maxheight(getheight(y->left), getheight(y->right)) + 1;
    return y;
}
struct node *rightrotate(struct node *x)
{
    struct node *y, *t;
    y = x->right;
    t = y->left;
    y->left = x;
    x->right = t;
    x->height = maxheight(getheight(x->left), getheight(x->right)) + 1;
    y->height = maxheight(getheight(y->left), getheight(y->right)) + 1;
    return y;
}
int assignheight(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int a, b;
        a = assignheight(root->left);
        b = assignheight(root->right);
        if (a <= b)
        {
            b++;
            root->height = b;
            return b;
        }
        else
        {
            a++;
            root->height = a;
            return a;
        }
    }
}
int getheight(struct node *root)
{
    if (root != NULL)
    {
        return root->height;
    }
    return 0;
}
int baf(struct node *root)
{
return (getheight(root->left)-getheight(root->right));
}
struct node *dobalance(struct node *root)
{
    if (root->left != NULL)
    {
        root->left = dobalance(root->left);
    }
    if (root->right != NULL)
    {
        root->right = dobalance(root->right);
    }
    root = getbalance(root);
    return root;
}
void printtree(struct node *root)
{
    print1(root, 0);
}
void print1(struct node *root, int sp)
{
    if (root == NULL)
    {
        return;
    }
    sp = sp + 2;
    print1(root->right, sp);
    for (int i = 0; i < sp; i++)
        cout << "   ";
    cout << root->data << endl;
    print1(root->left, sp);
}
void printTree(struct node *root, string indent, bool last)
{
    if (root != nullptr)
    {
        cout << indent;
        if (last)
        {
            cout << "R----";
            indent += "   ";
        }
        else
        {
            cout << "L----";
            indent += "|  ";
        }
        cout << root->data<<endl;
        printTree(root->left, indent, false);
        printTree(root->right, indent, true);
    }
}
int checkavl(struct node *root)
{
    if(root==NULL)
    {
        return 1;
    }
    if((checkavl(root->left)==0)||(checkavl(root->right)==0))
    {
        return 0;
    }
    if((baf(root)!=0)&&(baf(root)!=1))
    {
        return 0;
    }
    return 1;
}