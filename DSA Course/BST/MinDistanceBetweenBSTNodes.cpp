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

int MinDistance(Node* root){
    if(root==NULL){
        return INT_MAX;
    }
    int ans=INT_MAX;
    if(root->left){
        int LM=MinDistance(root->left);
        ans=min(ans,LM);
    }
    if(prev!=NULL){
        ans=min(ans,root->data-prev->data);
    }
    prev=root;
    if(root->right){
        int RM=MinDistance(root->right);
        ans=min(ans,RM);
    }
    return ans;
}

};

int main(){
    vector<int> str={83,62,42,82,52,88};
    Node* root=BuildBST(str);
    // cout<<root->data<<endl;
    // cout<<root->left->data<<endl;
    // cout<<root->right->data<<endl;
    // InOrder(root);
    cout<<endl;
    Solution s;
    cout<<"Minimum Distance between Nodes of BST is: "<<s.MinDistance(root)<<endl;
    return 0;
}