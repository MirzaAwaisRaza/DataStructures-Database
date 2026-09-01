#include<iostream>
#include<list>
using namespace std;
class Stack{
    list<int> ll;
    public:
    void push(int data){
        ll.push_front(data);
    }

    void pop(){
        ll.pop_front();
    }
    int top(){
        return ll.front();
    }
    bool empty(){
        return ll.size()==0;
    }

};
int main(){

    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout<<"Top: "<<s.top()<<endl;

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}