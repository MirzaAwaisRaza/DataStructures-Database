#include<iostream>
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
class Solution{
    public:
    Node* prev=NULL;
    Node* first=NULL;
    Node* second=NULL;
    void Recovery(Node* root){
        if(root==NULL){
            return;
        }
        if(root->left){
            Recovery(root->left);
        }
        if(prev!=NULL&&prev->data>root->data){
            if(!first){
                first=prev;
            }
            second=root;
        }
        prev=root;
        if(root->right){
            Recovery(root->right);
        }
    }

    void RecoverTree(Node* root){
        Recovery(root);
        int temp=first->data;
        first->data=second->data;
        second->data=temp;
    }
};
int main(){
    vector<int> str={3,2,1,5,6,4};
    Node* root=BuildBST(str);
    // cout<<root->data<<endl;
    InOrder(root);
    return 0;
}