#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<deque>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        next=NULL;
    }
};
// class List{
//     public:
//     Node* head;
//     Node* tail;
//     List(){
//         head=tail=NULL;
//     }

//     void push_front(int data){
//         Node* newNode=new Node(data);
//         if(head==NULL){
//             head=tail=newNode;
//         }
//         else{
//             newNode->next=head;
//             head=newNode;
//         }

//     }

//     void push_back(int data){
//         Node* newNode=new Node(data);
//         if(head==NULL){
//             head=tail=newNode;
//         }
//         else{
//             tail->next=newNode;
//             tail=newNode;
//         }
//     }


//     void print(){
//         Node*temp=head;
//         while(temp!=NULL){
//             cout<<temp->data<<"->";
//             temp=temp->next;
//         }
//         cout<<"NULL"<<endl;
//     }

//     void pop_front(){
//         if(head==NULL){
//             return;
//         }
//         Node* temp=head;
//         head=head->next;
//         temp->next=NULL;
//         delete temp;
//     }

//     void pop_back(){
//         if(head==NULL){
//             return;
//         }
//         Node* temp=head;
//         while(temp->next!=tail){
//             temp=temp->next;
//         }

//         temp->next=NULL;
//         delete tail;
//         tail=temp;

//     }

//     int search(int data){
//         Node* temp=head;
//         int index=0;
//         while(temp!=NULL){            
//             if(temp->data==data){
//                 return index;
//             }
//             temp=temp->next;
//             index++;
//         }
//         return -1;
//     }

//     void insert(int data,int position){
//         if(position<0){
//             return;
//         }
//         if(position==0){
//             push_front(data);
//         }
//         Node* newNode=new Node(data);
//         Node* temp=head;
//         for(int i=0;i<position-1;i++){
//             temp=temp->next;
//         }
//         newNode->next=temp->next;
//         temp->next=newNode;
//     }
// };

class Queue{
    public:
    Node* head;
    Node* tail;
    Queue(){
        head=tail=NULL;
    }

    void push(int data){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }

    }

    void pop(){
        Node* temp=head;
        if(head==NULL){
            return;
        }
        else{
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
    }

    int front(){
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return head->data;
    }

    bool empty(){
        return head==NULL;
    }

    // void print(){
    //     Node* temp=head;
    //     while(temp!=NULL){
    //         cout<<temp->data<<endl;
    //         temp=temp->next;
    //     }
    // }

};

// class Queue{
//     public:
//     List list;
//     int front(){
//         // return ll.head->data;
//         return list.head->data;

//     }

//     void push(int data){
//         // ll.push_back(data);
//         list.push_back(data);
//     }

//     void pop(){
//         // ll.pop_front();
//         list.pop_front();
//     }

//     bool empty(){
//         return list.head==NULL;
//     }

//     void print(){
//         Node* temp=list.head;
//         while(temp!=NULL){
//             cout<<temp->data<<endl;
//             temp=temp->next;
//             list.pop_front();
//         }
//     }
    
// };
int main(){
    // queue<int> q;
    deque<int> dq;

    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_front(4);

    dq.pop_back();
    dq.pop_front();
    // q.print();
    while(!dq.empty()){
        cout<<dq.front()<<endl;
        dq.pop_front();
    }
    cout<<"Deque empty or not: "<<dq.empty()<<endl;

    // Queue q;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);

    // q.pop();
    // // q.print();
    // while(!q.empty()){
    //     cout<<q.front()<<endl;
    //     q.pop();
    // }
    // cout<<"Queue empty or not: "<<q.empty()<<endl;
    return 0;
}