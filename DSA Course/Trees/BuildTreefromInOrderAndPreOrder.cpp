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
int search(vector<int> Inorder,int val,int left,int right){
    for(int i=left;i<=right;i++){
        if(val==Inorder[i]){
            return i;
        }
    }
    return -1;
}
Node* TreeBuild(vector<int>& preOrder,vector<int>& Inorder,int& preIdx,int left, int right){
    Node* root=new Node(preOrder[preIdx]);
    if(left>right){
        return NULL;
    }
    int InorderIdx=search(Inorder,preOrder[preIdx],left,right);
    preIdx++;
    root->left=TreeBuild(preOrder,Inorder,preIdx,left,InorderIdx-1);
    root->right=TreeBuild(preOrder,Inorder,preIdx,InorderIdx+1,right);
    return root;

}
int main(){
    int preIdx=0;
    vector<int> preOrder={3,9,20,15,7};
    vector<int> Inorder={9,3,15,20,7};
    Node* root=TreeBuild(preOrder,Inorder,preIdx,0,Inorder.size()-1);
    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;
    return 0;
}