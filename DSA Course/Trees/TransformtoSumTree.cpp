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

void pO(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    pO(root->left);
    pO(root->right);
}
int SumTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftsum=SumTree(root->left);
    int rightsum=SumTree(root->right);
    root->data=root->data+leftsum+rightsum;
    return root->data;
}
int main(){
    vector<int> preOrder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildTree(preOrder);
    // cout<<root->data<<endl;
    cout<<"Before Conversion:"<<endl;
    pO(root);
    cout<<endl;
    SumTree(root);
    cout<<"After Conversion:"<<endl;
    pO(root);
    return 0;
}