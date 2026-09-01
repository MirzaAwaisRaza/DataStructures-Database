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

Node* Helper(vector<int>& sort,int st,int end){
    if(st>end){
        return NULL;
    }
    int mid=st+(end-st)/2;
    Node* root=new Node(sort[mid]);
    root->left=Helper(sort,st,mid-1);
    root->right=Helper(sort,mid+1,end);
    return root;
}
Node* ConvertSorted(vector<int>& sort){
    return Helper(sort,0,sort.size()-1);
}
void InOrder(Node* root){
    if(root==NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}
int main(){
    vector<int> sort={-10,-3,0,5,9};
    Node* root=ConvertSorted(sort);
    InOrder(root);
    return 0;
}