#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;


// First Approach:
// class Stack{
//     public:
//     stack<pair<int,int>> s;
//     Stack(){

//     }

//     void push(int data){
//         if(s.empty()){
//             s.push({data,data});
//         }
//         else{
//             int MinValue=min(data,s.top().second);
//             s.push({data,MinValue});
//         }
//     }

//     void pop(){
//         s.pop();
//     }

//     int top(){
//         return s.top().first;
//     }

//     int getMin(){
//         return s.top().second;
//     }

// };

// Second Approach:
class Stack{
    public:
    stack<long long int> st;
    long long int minValue=0;
    Stack(){

    }

    void push(int data){
        if(st.empty()){
            st.push(data);
            minValue=data;
        }

        if(data<minValue){
            st.push(2*data-minValue);
            minValue=data;
        }
        else{
            st.push(data);
        }
    }

    void pop(){
        if(st.top()<minValue){
            minValue=2*minValue-st.top();
        }
        st.pop();
    }

    int top(){
        if(st.top()<minValue){
            return minValue;
        }
        else{
            return st.top();
        }
    }

    int getMin(){
        return minValue;
    }

};

int main(){

    Stack ss;
    ss.push(-2);
    ss.push(0);
    ss.push(-3);
    cout<<"Min Value: "<<ss.getMin()<<endl;
    ss.pop();
    cout<<"Top: "<<ss.top()<<endl;
    cout<<"New Min Value: "<<ss.getMin()<<endl;


    return 0;
}