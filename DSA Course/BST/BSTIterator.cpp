#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};
Node* Insert(Node* root,int value){
    if(root==NULL){
        return new Node(value);
    }
    if(value<root->data){
        root->left=Insert(root->left,value);
    }
    else{
        root->right=Insert(root->right,value);
    }
    return root;
}

Node* BuildBST(vector<int> structure){
    Node* root=NULL;
    for(int value:structure){
        root=Insert(root,value);
    }
    return root;
    
}
void InOrder(Node* root){
    if(root==NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);

}
void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    InOrder(root->left);
    InOrder(root->right);

}
class Solution{
    public:
    stack<Node*> s;
    Solution(Node* root){
        addLeftNodes(root);
    }
    int next(){
        Node* curr=s.top();
        s.pop();
        if(curr->right){
            addLeftNodes(curr->right);
        }
        return curr->data;
    }
    bool hasNext(){
        return s.size()>0;
    }
    void addLeftNodes(Node* root){
        while(root!=NULL){
            s.push(root);
            root=root->left;
        }

    }

};
int main(){
    vector<int> str={7,3,15,9,20};
    Node* root=BuildBST(str);
    // cout<<root->data<<endl;
    // InOrder(root);
    // preOrder(root);
    return 0;
}