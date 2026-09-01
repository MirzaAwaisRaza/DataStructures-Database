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

    Node* merge(Node* h1,Node* h2){
        if(h1==NULL||h2==NULL){
            return h1==NULL?h2:h1;
        }
        if(h1->data<=h2->data){
            h1->next=merge(h1->next,h1);
            return h1;
        }
        else{
            h2->next=merge(h1,h2->next);
            return h2;
        }
    }
};

int main(){
    List l;
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    l.push_front(4);

    List l1;
    l1.push_front(5);
    l1.push_front(6);
    l1.push_front(7);
    l1.push_front(8);

    l1.print();

    return 0;
}