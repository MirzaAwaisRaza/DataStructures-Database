#include<iostream>
#include<array>
#include<algorithm>
using namespace std;
// class Node{
//     public:
//     int data;
//     Node* front;
//     Node* rear;
//     Node(int data){
//         this->data=data;
//         // front=0;
//         // rear=-1;
//     }

// };
class CircularQueue{
    public:
    int f; // f for front 
    int r; // r for rear;
    int currSize=0;
    int capacity;
    int* arr;

    CircularQueue(int size){
        capacity=size;
        arr=new int(capacity);
        f=0;
        r=-1;
    }

    void push(int value){
        if(currSize==capacity){
            cout<<"Circular queue is full"<<endl;
        }

        r=(r+1)%capacity;
        arr[r]=value;
        currSize++;
    }

    void pop(){
        if(currSize==0){
            cout<<"Circular queue is empty"<<endl;
            return;
        }
        f=(f+1)%capacity;
        currSize--;

    }

    int front(){
        if(currSize==0){
            cout<<"No front because of empty Circular Queue"<<endl;
            return -1;
        }
        return arr[f];
    }

    bool empty(){
        return currSize==0;
    }

    void print(){ //for printing elements in the form of array not in circular queue
        for(int i=0;i<currSize;i++){
            cout<<arr[i]<<endl;
        }
    }

};
int main(){
    CircularQueue cq(3);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.pop();
    cq.push(4);
    // cq.push(4);
    // cq.push(5);
    // cq.push(4);

    // cq.print(); for printing according to array  
    // means not printing according to the front and 
    // the rear pointer which is important in the circular queue
    // cq.print(); for printing according to array 
    
    while(!cq.empty()){
        cout<<cq.front()<<" ";
        cq.pop();
    }
    cout<<endl;
    cout<<"Circular Queue is empty or not: "<<cq.empty()<<endl;

    return 0;
}