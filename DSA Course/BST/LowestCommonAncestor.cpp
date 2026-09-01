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
Node* helper(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=helper(root->left,val);
    }
    else{
        root->right=helper(root->right,val);
    }
    return root;
}
Node* TreeBuild(vector<int> Tree){
    Node* root=NULL;
    for(int val:Tree){
        root=helper(root,val);
    }
    return root;
}
Node* LCA(Node* root,int p,int q){
    if(root==NULL){
        return NULL;
    }
    // if(p==root->data||q==root->data){
    //     return root;
    // }
    if(p<root->data&&q<root->data){
        return LCA(root->left,p,q);
    }
    else if(p>root->data&&q>root->data){
        return LCA(root->right,p,q);
    }
    else{
        return root;
    }
}
int main(){
    vector<int> Tree={3,2,1,4,5,6};
    Node* TreeNode=TreeBuild(Tree);
    // cout<<TreeNode->data<<endl;
    // cout<<TreeNode->left->data<<endl;
    // cout<<TreeNode->right->data<<endl;
    // cout<<endl;
    Node* Ancestor=LCA(TreeNode,5,6);
    cout<<"Lowest Common Ancestor: "<<Ancestor->data<<endl;
    return 0;
}