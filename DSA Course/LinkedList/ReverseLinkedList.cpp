#include<vector>
#include<list>
#include<iostream>
using namespace std;
#include<algorithm>
class Node{
    public:
    int data;
    Node* next;
    public:
     Node(int data){
        this->data=data;
        next=NULL;
    }
};
class ReverseC{
    public:
    Node* reverse(Node* head){
        Node* previous;
        Node* current;
        Node* nextNodePointer;

        previous=NULL;
        current=head;
        nextNodePointer=NULL;

        while(current!=NULL){
            nextNodePointer=current->next;
            current->next=previous;
            previous=current;
            current=nextNodePointer;

        }
        return previous;

    }
    // void print(){
    //     Node* temp;
    //     while(temp!=NULL){
    //         cout<<temp->data<<"<-";
    //         temp=temp->next;
    //     }
    //     cout<<endl;
    // }


};
int main(){
    ReverseC r;
    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    for(int value:l1){
        cout<<value<<"->";
    }
    cout<<endl;

    // r.reverse(head);
    return 0;
}