#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;
class Node{
    public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key ,int val){
        this->key=key;
        this->val=val;
        next=prev=NULL;
    }
    
};
class LRU{
    unordered_map<int,Node*> m;
    public:
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int limit;

    void addNode(Node* newNode){
        Node* oldNext=head->next;
        newNode->next=oldNext;
        newNode->prev=head;
        head->next=newNode;
        oldNext->prev=newNode;

    }

    void delNode(Node* oldNode){
        Node* oldprev=oldNode->prev;
        Node* oldNext=oldNode->next;
        oldprev->next=oldNext;
        oldNext->prev=oldprev;
        

    }

    LRU(int capacity){
        limit=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void put(int key,int val){
        if(m.find(key)!=m.end()){
            Node* oldNode=m[key];
            m.erase(key);
            delNode(oldNode);
        }

        if(m.size()==limit){
            m.erase(tail->prev->key);
            delNode(tail->prev); 
        }

        Node* newNode=new Node(key,val);
        addNode(newNode);
        m[key]=newNode;
    }

    int get(int key){
        int ans=m[key]->val;
        if(m.find(key)!=m.end()){
            return -1;
        }
        Node* ansNode=m[key];
        m.erase(key);
        delNode(ansNode);
        addNode(ansNode);
        m[key]=ansNode;

        return ans;

    }

    
};
int main(){
    return 0;
}