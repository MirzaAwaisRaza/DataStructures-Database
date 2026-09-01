#include<vector>
#include<iostream>
using namespace std;
class Stack{
    public:
    vector<int> v;
    void push(int data){
        v.push_back(data);
    }

    void pop(){
        v.pop_back();
    }

    int top(){
        return v[v.size()-1];
    }

    bool empty(){
        return v.size()==0;
    }


};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout<<"Top element in stack is: "<<s.top()<<endl;

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    cout<<"Stack is Empty or not: "<<s.empty();
    return 0;
}