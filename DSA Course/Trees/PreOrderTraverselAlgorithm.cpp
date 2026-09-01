#include<iostream>
#include<vector>
using namespace std;
// In preorderTraversel algorithm 
// we firstly travese to root and then it left subtree and then right subtree
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

static int idx=-1;
Node* BuildTree(vector<int> preOrder){
    idx++;
    if(preOrder[idx]==-1){
        return NULL;
    }
    Node* root=new Node(preOrder[idx]);
    root->left=BuildTree(preOrder);
    root->right=BuildTree(preOrder);
    return root;
    
}

void preOrderTraversel(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrderTraversel(root->left);
    preOrderTraversel(root->right);

}
int main(){
    vector<int> preOrder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildTree(preOrder);
    preOrderTraversel(root);
    return 0;
}