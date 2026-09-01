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
    Node* previous;
    List(){
        head=tail=NULL;
    }

    Node* ReverseNode(Node* head,int k){
        Node* temp=head;
        int count=0;
        while(count<k){
            if(temp==NULL){
                return temp;
            }
            temp=temp->next;
            count++;
        }
        previous=ReverseNode(temp,k);

        temp=head;
        count=0;
        while(count<k){
            Node* next=temp->next;
            temp->next=previous;
            previous=temp;
            temp=next;
        }
        return previous;
    }
};
int main(){
    return 0;
}