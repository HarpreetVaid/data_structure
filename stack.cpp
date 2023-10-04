#include <iostream>

using namespace std;

class stack{
    private:
        struct link
        {
            int data;
            link *next;
        } *first = nullptr;
        int last = 0;

    public:
        void push(int element){
                if(first == nullptr){
                    first = new link;
                    first->data = element;
                    first->next = nullptr;
                    last++;
                }
                else{
                    link *temp=first;
                    while (temp->next != nullptr){
                        temp = temp->next;
                    }
                    temp->next = new link;
                    temp->next->data = element;
                    temp->next->next = nullptr;
                    last++;
                }
            }

        void pop(){
            link *temp;
            temp = first->next;
            delete first;
            first = temp;
            last--;
            }

        int isEmpty(){
            if(first == nullptr){
                return 1;
            }
            return 0;
            }

        int peek(){
            if(first != nullptr){
                return first->data;
            }
            return -1;
            }

        int size(){
            return last;
            }

        void traverse(){
                link *temp = first;
                while (temp != nullptr)
                {
                    cout<<temp->data<<"   ";
                    temp = temp->next;
                }
                cout<<endl;   
            }
        
};


int main() {
    stack obj1;
    for (int i = 0; i < 10; i++){
        obj1.push(i);
    }
    obj1.traverse();
    cout<<obj1.isEmpty()<<endl;
    obj1.pop();
    obj1.traverse();
    cout<<obj1.size()<<endl;
    cout<<obj1.peek()<<endl;
    return 0;
}