// InOrderTraversel we visit(traverse) our whole left subtree 
// and then root and then the whole right subtree#include<iostream>
#include<vector>
#include<iostream>
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
void PostOrderTraversel(Node* root){
    if(root==NULL){
        return;
    }
    PostOrderTraversel(root->left);
    PostOrderTraversel(root->right);
    cout<<root->data<<" ";
}


int main(){
    vector<int> preOrder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildTree(preOrder);
    PostOrderTraversel(root);
    
    return 0;
}