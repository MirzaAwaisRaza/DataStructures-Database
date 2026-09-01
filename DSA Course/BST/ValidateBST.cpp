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
Node* insert(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;
}
Node* BuildTree(vector<int> tree){
    Node* root=NULL;
    for(int val:tree){
        root=insert(root,val);
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
bool helper(Node* root,Node* min, Node* max){
    if(root==NULL){
        return true;
    }
    if(min!=NULL&&root->data<=min->data){
        return false;
    }
    if(max!=NULL&&root->data>=max->data){
        return false;
    }
    return helper(root->left,min,root)&&helper(root->right,root,max);
}
bool IsValid(Node* root){
    // Node* min;
    // Node* max;
    // min=max=NULL;
    return helper(root,NULL,NULL);

}
int main(){
    vector<int> tree={3,2,1,5,6,4};
    Node* root=BuildTree(tree);
    // InOrder(root);
    cout<<endl;
    // cout<<"Valid BST or not: "<<ValidBST(root)<<endl;
    cout<<"Valid BST or not: "<<IsValid(root)<<endl;
    return 0;
}