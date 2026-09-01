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
bool Search(Node* root,int key){
    if(root==NULL){
        return false;
    }

    if(root->data==key){
        return true;
    } 
    
    if(key>root->data){
        return Search(root->right,key);
    }
    else{
        return Search(root->left,key);
    }
       

}
int main(){
    vector<int> str={3,2,1,5,6,4};
    Node* root=BuildBST(str);
    // cout<<root->data<<endl;
    InOrder(root);
    cout<<endl;
    cout<<"Node exist in BST or not: "<<Search(root,6);
    return 0;
}