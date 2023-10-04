#include <iostream>

using namespace std;

class binarytree {

    private:
        struct link{
            int data;
            link *left,*right;
        }*root = nullptr;
        
    public:
        binarytree(){
            cout<<"Enter the root data"<<endl;
            cin>>root->data;
            cout<<"-----Left Tree-----"<<endl;
            root->left = create_tree(2);
            cout<<"-----Right Tree-----"<<endl;
            root->right = create_tree(2);
        }

        link * create_tree(int level){
            int i;
            link * temp;
            cout<<"Press 1 to enter the data";
            cin>>i;
            if(i == 1){
                temp = new link;
                cout<<"Enter the data";
                cin>>temp->data;
                cout<<"Enter the left  data of level"<<level<<endl;    
                temp->left = create_tree(level+1);
                cout<<"Enter the right data of level"<<level<<endl;    
                temp->right = create_tree(level+1);
            }
            else{
                temp = nullptr;
            }
            return nullptr;

        }

};

int main() {

    return 0;
}