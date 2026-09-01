#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
class Queue{
    public:
    stack<int> ps; //primary stack
    stack<int> ss; //secondary stack

    Queue(){

    }

    void push(int data){
        if(ps.empty()){
            ps.push(data);
        }
        else{
            while(!ps.empty()){
                ss.push(ps.top());
                ps.pop();
            }
            ps.push(data);
            while(!ss.empty()){
                ps.push(ss.top());
                ss.pop();
            }
        }
    }

    int pop(){
        if(ps.empty()){
            cout<<"Queue is empty nothing pop";
            return -1;
       }
       else{
        int ans=ps.top();
        ps.pop();
        return -1;
       }
    }

    int front(){
        return ps.top();
    }

    bool empty(){
        return ps.empty();
    }
};
int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    cout<<"Front of Queue: "<<q.front()<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    cout<<"Queue is empty or not: "<<q.empty()<<endl;
    
    return 0;
}
