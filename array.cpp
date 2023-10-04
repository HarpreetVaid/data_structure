#include<iostream>
using namespace std;

class Arrayds  { 
    private:
        int array[30];
        int last;

    public:
        Arrayds(){
            last=0;
        }
        int update(int index, int element){
            if(index<last){
                array[index] = element;
                return 1;
            }
            return 1;
        }

        int search(int element){
            for(int i=0;i<last;i++){
                if(array[i]==element){
                return i;
                }
            }

            return -1;
        }

        void traverse(){
            for(int i=0;i<last;i++){
                cout<<array[i];
                cout<<"  ";
            } 
            cout<<endl; 
        }

        int get_element(int index){
            return array[index];
        }

        int insert_element(int element){
            if(last<30){
                array[last]= element;
                last +=1;
                return 1;
            }
            return 0;
        }

        int delete_element(int element){
            int index =search(element);
            if(index!= -1){
                for(int i = index; i<last;i++){
                    array[i]= array[i+1];
                }
                last -= 1;
                return 1; 
            }
            return 0;
        }

};

int main(){

    Arrayds obj1;
    for(int i=0; i<25;i++){
        obj1.insert_element(i);
    }
    obj1.traverse();
    cout<<endl;
    obj1.delete_element(20);
    obj1.traverse();
    cout<<obj1.search(10)<<endl;
    obj1.update(0,10);
    obj1.traverse();
    cout<<endl<<obj1.get_element(2)<<endl;
    obj1.traverse();
}