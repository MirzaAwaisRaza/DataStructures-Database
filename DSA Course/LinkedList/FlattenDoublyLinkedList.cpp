#include<iostream>
#include<algorithm>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node* child;

    Node(int data){
        this->data=data;
        next=prev=child=NULL;
    }
    
};

class Doublylist{
    public:
    Node* head;
    Node* tail;

    Doublylist(){
        head=tail=NULL;
    }

    Node* FlattenList(Node* head){
        if(head==NULL){
            return head;
        }

        Node* current=head;
        while(current!=NULL){
            if(current->child!=NULL){
                // Flatten the child node
                Node* next=current->next;
                current->next=FlattenList(current->child);
                current->next->prev=current;
                current->child=NULL;

                // Finding the tail
                while(current->next!=NULL){
                    current=current->next;
                }

                // Attach tail with next pointer
                if(next!=NULL){
                    current->next=NULL;
                    next->prev=current;
                }
            }
            current=current->next;

        }
        return head;
    }
};
int main(){


    return 0;
}