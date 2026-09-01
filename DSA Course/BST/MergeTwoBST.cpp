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
Node* Insert(Node* root,int value){
    if(root==NULL){
        return new Node(value);
    }
    if(value<root->data){
        root->left=Insert(root->left,value);
    }
    else{
        root->right=Insert(root->right,value);
    }
    return root;
}

Node* BuildBST(vector<int> structure){
    Node* root=NULL;
    for(int value:structure){
        root=Insert(root,value);
    }
    return root;
    
}
void InOrder(Node* root,vector<int> &ans){
    if(root==NULL){
        return;
    }
    InOrder(root->left,ans);
    ans.push_back(root->data);
    InOrder(root->right,ans);
}
Node* MergeTwoBST(vector<int> final,int st,int end){
    if(st>end){
        return NULL;
    }
    int mid=st+(end-st)/2;
    Node* root=new Node(final[mid]);
    
    root->left=MergeTwoBST(final,st,mid-1);
    root->right=MergeTwoBST(final,mid+1,end);
    return root;
}
Node* merge(Node* r1,Node* r2){
        vector<int> rt1;
        vector<int> rt2;
        InOrder(r1,rt1);
        InOrder(r2,rt2);
        vector<int> final;
        int i=0;
        int j=0;
        while(i<rt1.size()&&j<rt2.size()){
            if(rt1[i]<rt2[j]){
                final.push_back(rt1[i++]);
            }else{
                final.push_back(rt2[j++]);
            }
        }
        while(i<rt1.size()){
            final.push_back(rt1[i++]);
        }
        while(j<rt2.size()){
            final.push_back(rt2[j++]);
        }
        return MergeTwoBST(final,0,final.size()-1);
}



int main(){
    vector<int> tree1={8,2,1,10};
    Node* root1=BuildBST(tree1);
    // cout<<root1->data<<endl;
    // cout<<root1->left->data<<endl;
    // cout<<root1->right->data<<endl;
    vector<int> tree2={5,3,0};
    Node* root2=BuildBST(tree2);
    // cout<<root2->data<<endl;
    // cout<<root2->left->data<<endl;
    // cout<<root2->right->data<<endl;
    // InOrder(root);
    Node* mergeRoot=merge(root1,root2);
    vector<int> mergeVector;
    InOrder(mergeRoot,mergeVector);
    for(int i:mergeVector){
        cout<<i<<" ";
    }
    cout<<endl;
    // cout<<mergeroot->data<<endl;
    // InOrder(mergeroot);
    return 0;
}