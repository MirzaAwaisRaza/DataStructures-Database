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

    void push_back(int data){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }


    void print(){
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void pop_front(){
        if(head==NULL){
            return;
        }
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

    void pop_back(){
        if(head==NULL){
            return;
        }
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }

        temp->next=NULL;
        delete tail;
        tail=temp;

    }

    int search(int data){
        Node* temp=head;
        int index=0;
        while(temp!=NULL){            
            if(temp->data==data){
                return index;
            }
            temp=temp->next;
            index++;
        }
        return -1;
    }

    void insert(int data,int position){
        if(position<0){
            return;
        }
        if(position==0){
            push_front(data);
        }
        Node* newNode=new Node(data);
        Node* temp=head;
        for(int i=0;i<position-1;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
};

int main(){
    List l;
    // l.push_front(1);
    // l.push_front(2);
    // l.push_front(3);
    // l.push_front(4);
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.print();
    l.insert(5,1);
    l.print();
    cout<<l.search(3)<<endl;

    return 0;
}