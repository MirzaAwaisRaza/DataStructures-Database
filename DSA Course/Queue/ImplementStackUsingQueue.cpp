#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class Stack{
    public:
    queue<int> pq; //primary queue
    queue<int> sq; //secondary queue
    Stack(){

    };
    void push(int data){
        if(pq.empty()){
            pq.push(data);
        }
        else{
            while(!pq.empty()){
                sq.push(pq.front());
                pq.pop();
            }
            pq.push(data);
            while(!sq.empty()){
                pq.push(sq.front());
                sq.pop();
            }
        }

    }

    int top(){
        if(pq.empty()){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return pq.front();
    }
    int pop(){
        if(pq.empty()){
            cout<<"Stack is empty therefore nothing pop"<<endl;
            return -1;
        }
        int ans=pq.front();
        pq.pop();
        return ans;

    }

    bool empty(){
        return pq.empty(); 
    }

};
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<"Top of stack: "<<s.top()<<endl;
    s.pop();
    cout<<"Top of stack: "<<s.top()<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    cout<<"Stack is empty or not: "<<s.empty()<<endl;
    return 0;
}