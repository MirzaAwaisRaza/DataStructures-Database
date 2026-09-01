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

int count=0;
void NodeCount(Node* root){
    if(root==NULL){
        return;
    }
    else{
        count++;
    }
    NodeCount(root->left);
    NodeCount(root->right);

}

int OptimalNodeCount(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftcount=OptimalNodeCount(root->left);
    int rightcount=OptimalNodeCount(root->right);
    return leftcount+rightcount+1;
}

int main(){
    
    vector<int> preOrder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildTree(preOrder);
    
    NodeCount(root);
    // cout<<"Total Nodes in Tree: "<<count<<endl;
    cout<<"Total Nodes in Tree: "<<OptimalNodeCount(root);
    return 0;
}