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
Node* NR=NULL; //NR stands for next right pointer.
void Flatten(Node* root){
    if(root==NULL){
        return;
    }
    Flatten(root->right);
    Flatten(root->left);
    root->left=NULL;
    root->right=NR;
    NR=root;
}
int main(){
    vector<int> preOrder={1,2,3,-1,-1,4,-1,-1,5,-1,6,-1,-1};
    Node* root=BuildTree(preOrder);
    Flatten(root);
    return 0;
}