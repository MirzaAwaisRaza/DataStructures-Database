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

bool Identical(Node* p,Node* q){
    if(p==NULL||q==NULL){
        return p==q;
    }
        bool isleft=Identical(p->left,q->left);
        bool isright=Identical(p->right,q->right);
        return isleft&&isright&&p->data==q->data;
}
int main(){
    vector<int> preOrder={1,2,-1,-1,3,-1,-1};
    Node* p=BuildTree(preOrder);
    Node* q=BuildTree(preOrder);
    cout<<"Trees are identical or not: "<<Identical(p,q)<<endl;
    return 0;
}