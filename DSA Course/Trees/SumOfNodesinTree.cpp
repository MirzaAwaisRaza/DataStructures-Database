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

int sum=0;
void SumNodes(Node* root){
    if(root==NULL){
        return;
    }
    else{
        sum+=root->data;
    }
    SumNodes(root->left);
    SumNodes(root->right);

}

int OptimalSumNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    int lsum=OptimalSumNodes(root->left);
    int rsum=OptimalSumNodes(root->right);
    return lsum+rsum+root->data;
}
int main(){
    vector<int> preOrder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildTree(preOrder);
    // SumNodes(root);
    // cout<<"Sum of Nodes of Tree: "<<sum<<endl;
    cout<<"Sum of Nodes of Tree: "<<OptimalSumNodes(root)<<endl;
    return 0;
}