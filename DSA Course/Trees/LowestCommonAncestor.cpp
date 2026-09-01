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
Node* LCA(Node* root,Node* p,Node* q){
    if(root==NULL){
        return NULL;
    }
    if(root->data==p->data||root->data==q->data){
        return root;
    }
    Node* leftLCA=LCA(root->left,p,q);
    Node* rightLCA=LCA(root->right,p,q);
    if(leftLCA==NULL&&rightLCA==NULL){
        return NULL;
    }
    else if(leftLCA!=NULL&&rightLCA!=NULL){
        return root;
    }
    else if(leftLCA!=NULL&&rightLCA==NULL){
        return leftLCA;
    }
    else{ //leftLCA is NULL and rightLCA is not NULL
        return rightLCA;
    }
    

}
int main(){
    vector<int> preOrder={1,2,7,-1,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildTree(preOrder);
    return 0;
}