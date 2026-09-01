#include<vector>
#include<iostream>
#include<algorithm>
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
class List{
    public:
    Node* head;
    Node* tail;
    List(){
        head=tail=NULL;
    }

    void push_front(int data){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        }

    }

    void print(){
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }

    bool DetectCycle(){
        Node* slow=head;
        Node* fast=head;
        
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                return true;
            }
        }
        return false;
    }
// here two problems solved first
//  is if we demand to return the starting node
//  where cycle start then we return that node
//  and the second is remove the cycle 
   Node* FindAndRemoveCycle(){
    Node* slow=head;
    Node* fast=head;
    bool cycleExist=false;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            cycleExist=true;
            break;
        }
    }
    if(!cycleExist){
        return NULL;
    }
    slow=head;
    Node* prev=NULL;
    while(slow!=fast){
        slow=slow->next;
        prev=fast;
        fast=fast->next;
    }

    // for removing cycle 
    prev->next=NULL;
    
    return slow; //here we return the starting node of cycle

   } 
};

int main(){
    List l;
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    l.push_front(4);
    l.print();

    return 0;
}