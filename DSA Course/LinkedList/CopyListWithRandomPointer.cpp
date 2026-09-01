#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* random;

    Node(int data){
        this->data=data;
        next=NULL;
        random=NULL;
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
    Node* copyList(Node* head){
        if(head==NULL){
            return NULL;
        }
        Node* newhead=new Node(head->data);
        unordered_map<Node*, Node*> m;
        m[head]=newhead;
        Node* oldtemp;
        Node* newtemp;
        while(oldtemp!=NULL){
            Node* copyNode=new Node(oldtemp->data);
            m[oldtemp]=copyNode;
            newtemp->next=copyNode;
            oldtemp=oldtemp->next;
            newtemp=newtemp->next;
        }

        oldtemp=head;
        newtemp=newhead;
        while(oldtemp!=NULL){
            newtemp->random=m[oldtemp->random];
            oldtemp=oldtemp->next;
            newtemp=newtemp->next;
        }
        return newhead;
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