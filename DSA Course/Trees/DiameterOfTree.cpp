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

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    // int leftHeight=height(root->left);
    // int rightHeight=height(root->right);
    // return max(leftHeight,rightHeight)+1;
    return max(height(root->left),height(root->right))+1;
}

int diameter(Node* root){
    if(root==NULL){
        return 0;
    }
    int ldiameter=diameter(root->left);
    int rdiameter=diameter(root->right);
    int currdiameter=height(root->left)+height(root->right);
    return max(currdiameter,max(ldiameter,rdiameter));
}

int ans=0;
int OptimalDiameter(Node* root){
    int curr=height(root->left)+height(root->right);
    return max(ans,curr);
}
int main(){
    vector<int> preOrder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildTree(preOrder);
    // cout<<"Diameter of tree: "<<diameter(root);
    cout<<"Diameter of tree: "<<OptimalDiameter(root);
    return 0;
}