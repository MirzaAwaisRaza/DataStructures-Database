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

    Node* SwapNodes(Node* head){
        if(head==NULL||head->next==NULL){
            return head;
        }
        Node* previous=NULL;
        Node* first=head;
        Node* sec=head->next;
        while(first!=NULL&&sec!=NULL){
            Node* third=sec->next;
            sec->next=first;
            first->next=third;
            if(previous!=NULL){
                previous->next=sec;
            }
            else{
                head=sec;
            }

            previous=first;
            first=third;
            if(third!=NULL){
                sec=third->next;
            }
            else{
                sec=NULL;
            }
            
            
        }
        return head;

    }
};
int main(){

    return 0;
}