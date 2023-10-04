#include <iostream>
using namespace std;

class queue{
    private :
      struct link
        {
            int data;
            link *next;
        } *first = nullptr,*last;
    
    public:
        void enqueue(int element){
            if(first == nullptr){
                first = new link;
                first->next = nullptr;
                first->data = element;
                last = first;
            }
            else{
                link *temp = last;
                last = new link;
                temp->next = last;
                last->next = nullptr;
                last->data = element;
            }
        }

        void dequeue(){
            if (first == nullptr){
                return;
            } 
            link *temp = first;
            first = first->next;
            delete temp;
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
        
        int isEmpty(){
            if(first == nullptr){
                return 1;
            }
            return 0;
            }
    
};

int main() {
    queue obj1;
    for (int i = 0; i < 10; i++){
        obj1.enqueue(i);
    }
    obj1.traverse();
    cout<<obj1.isEmpty()<<endl;
    obj1.dequeue();
    obj1.dequeue();
    obj1.dequeue();
    obj1.dequeue();
    obj1.traverse();
    return 0;
}