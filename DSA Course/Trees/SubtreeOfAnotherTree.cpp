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

bool IdenticalCheck(Node* p,Node* q){
    if(p==NULL||q==NULL){
        return p==q;
    }
    return p->data==q->data&&IdenticalCheck(p->left,q->left)&&IdenticalCheck(p->right,q->right);

}

bool Subtree(Node* root,Node* subtree){
    if(root==NULL||subtree==NULL){
        return root==subtree;
    }
    if(root->data==subtree->data&&IdenticalCheck(root,subtree)){
        return true;
    }
    return Subtree(root->left,subtree)||Subtree(root->right,subtree);
}
int main(){
    vector<int> preOrder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildTree(preOrder);
    vector<int> another={3,4,-1,-1,5,-1,-1};
    Node* subtree=BuildTree(another);
    cout<<"Is it is Subtree of another tree: "<<Subtree(root,subtree)<<endl;
    return 0;
}