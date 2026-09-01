#include<iostream>
#include<vector>
#include<string>
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

// Node* TreePath(Node* root){
//     if(root==NULL){
//         return 0;
//     } 
//     Node* lp=TreePath(root->left);
//     Node* rp=TreePath(root->right);
//     cout<<root->data<<"->"<<lp->data<<"->"<<rp->data<<" ";
//     return root;

// }

void helper(Node* root,string path,vector<string>& ans){
    if(root->left==NULL,root->right==NULL){
        ans.push_back(path);
        return;
    }
    if(root->left){
        helper(root->left,path+"->"+to_string(root->left->data),ans);
    }

    if(root->right){
        helper(root->right,path+"->"+to_string(root->right->data),ans);
    }
}
vector<string> path(Node* root){
string path=to_string(root->data);
vector<string> ans;
helper(root,path,ans);
return ans;

}

int main(){
    vector<int> preOrder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildTree(preOrder);
    // TreePath(root);
    vector<string> s=path(root);
    return 0;
}