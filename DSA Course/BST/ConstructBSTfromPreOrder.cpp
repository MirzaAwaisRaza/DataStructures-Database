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
// Node* Helper(Node* root,Node* min,Node* max,int value){
//     if(root==NULL){
//         return new Node(value);
//     }
//     if(value<root->data){
//         root->left=Helper(root->left,min,root,value);
//     }else{
//         root->right=Helper(root->right,root,max,value);
//     }
//     return root;


// }
// Node* BuildBST(vector<int> Tree){
//     Node* root=NULL;
//     for(int value:Tree){
//         root=Helper(root,NULL,NULL,value);
//     }
//     return root;
// }
int val=0;
Node* BuildBST(vector<int>& Tree,int &val,int Limit){
    if(val>=Tree.size()||Tree[val]>Limit){
        return NULL;
    }
    Node* root=new Node(Tree[val++]);
    // val++;
    root->left=BuildBST(Tree,val,root->data);
    root->right=BuildBST(Tree,val,Limit);
    return root;
}
void InOrder(Node* TreeRoot){
    if(TreeRoot==NULL){
        return;
    }
    if(TreeRoot->left){
        InOrder(TreeRoot->left);
    }
    cout<<TreeRoot->data<<" ";
    if(TreeRoot->right){
        InOrder(TreeRoot->right);
    }
}

int main(){
    vector<int> Tree={6,3,1,4,8,9};
    int val=0;
    Node* Treeroot=BuildBST(Tree,val,INT_MAX);
    cout<<Treeroot->data<<endl;
    cout<<Treeroot->left->data<<endl;
    cout<<Treeroot->right->data<<endl;
    InOrder(Treeroot);
    return 0;
}