#include<iostream>
#include<vector>
using namespace std;

/*
    Heap have two operations insert into the heap 
    or pop the top element of the heap
*/
class Heap{
    vector<int> arr;

    public:
    void insert(int data){
        
        //when we insert the data we bubble up
        arr.push_back(data);
        bubbleUp();
        
    }

    bool isEmpty(){
        return this -> arr.size() == 0;
    }

    int pop(){
        if(isEmpty()) return -1;
        int size = arr.size()-1;

        int data = arr[0];
        arr[0] = arr[size];
        bubbleDown();
        arr.pop_back();
        return data;
    }

    void print(){
        for(auto i: arr){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    private:
    void swap(int parent, int child){
        int temp = arr[parent];
        arr[parent] = arr[child];
        arr[child] = temp;
    }

    void bubbleUp(){
        int size = arr.size()-1;
        int child = size;
        int parent = size/2;

        while(parent >= 0 && arr[parent] < arr[child]){
            swap(parent, child);
            child = parent;
            parent = parent/2;
        }
    }

    void bubbleDown(){
        int size = arr.size();
        int parent = 0;
        int child1 = 2*parent+1;
        int child2 = 2*parent+2;

        while(child2 < size){
            if(arr[parent] >= arr[child1] && arr[parent] >= arr[child2]) break;

            if(arr[parent] < arr[child1] && arr[child1] > arr[child2]){ //child1 is greatest of parent, child1, child2
                swap(child1, parent);
                parent = child1;
            }
            else{
                swap(child2, parent);
                parent = child2;
            }

            child1 = 2*parent+1;
            child2 = 2*parent+2;
        }
    }
};

int main(){
    Heap h;
    int options;
    while(true){
        cout<<"1.Add element  2.pop  3.Print  4.Pop All"<<endl;
        cout<<"Enter a choice ";
        cin>>options;
        cout<<endl;

        int ele;
        switch(options){
            case 1:
                cout<<"Enter an element ";
                cin>>ele;
                h.insert(ele);
                break;

            case 2:
                cout<<"Top element  = "<<h.pop()<<endl;
                break;

            case 3:
                h.print();
                break;
            case 4:
                while(!h.isEmpty()){
                    cout<<h.pop()<<" ";
                }
                cout<<endl;
                break;
            default:
                cout<<"Enter a valid option"<<endl;
        }

        cout<<"--------------------------------------------------------"<<endl;
    }
}