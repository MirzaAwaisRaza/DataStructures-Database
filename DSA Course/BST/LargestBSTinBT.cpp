#include<iostream>
using namespace std;
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
void InOrder(Node* root){
    if(root==NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);

}
// int leftsize=0;
// int rightsize=0;
// int maxsize=0;
// int ans=0;
// int Largest(Node* root){
//     int size=0;
//     if(root==NULL){
//         return 0;
//     }
//     if(root->left->data<root->data&&root->right->data>root->data){
//         if(root!=NULL){
//         size++;
//     }
//         leftsize=LargestBST(root->left);
//         rightsize=LargestBST(root->right);

//     maxsize=leftsize+rightsize+size;
//     ans=max(ans,maxsize);
//     return ans;
//     }
//     return 0;
// }
bool isValidate(Node* root,Node* min,Node* max){
    if(root==NULL){
        return true;
    }
    if(min!=NULL&&root->data<=min->data){
        return false;
    }
    if(max!=NULL&&root->data>=max->data){
        return false;
    }

    return isValidate(root->left,min,root)&&isValidate(root->right,root,max);
}
// int maxsize=0;
// int ans=0;
// int lsize=0;
// int rsize=0;
// int LargestBSTinBT(Node* root){
//     if(root==NULL){
//         return 0;
//     }
//     isValidate(root,NULL,NULL);
    
//         lsize=LargestBSTinBT(root->left);
//         rsize=LargestBSTinBT(root->right);
//         if(isValidate){
//         maxsize=lsize+rsize+1;
//         ans=max(ans,maxsize);
//         return ans;
//     }
//     if(!isValidate){
//         return -1;
//     }
// }
static int idx=-1;
Node* BuildTree(vector<int> str){
    idx++;
    if(str[idx]==-1){
        return NULL;
    }
    Node* root=new Node(str[idx]);
    root->left=BuildTree(str);
    root->right=BuildTree(str);
    return root;
}
void PreOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
class Info{
    public:
    int min,max,size;
    Info(int min,int max,int size){
        this->min=min;
        this->max=max;
        this->size=size;
    }

};
Info helper(Node* root){
    if(root==NULL){
        return Info(INT_MAX,INT_MIN,0);
    }
    Info left=helper(root->left);
    Info right=helper(root->right);
    if(root->data>left.max&&root->data<right.min){
        int currMin=min(root->data,left.min);
        int currMax=max(root->data,right.max);
        int currSize=left.size+right.size+1;
        return Info(currMin,currMax,currSize);
    }
    return Info(INT_MAX,INT_MIN,max(left.size,right.size));
}
int LargestBST(Node* root){
    Info info=helper(root);
    return info.size;
}
int main(){
    vector<int> str={10,5,1,-1,-1,8,-1,-1,15,-1,20,-1,-1};
    // Node* root=BuildBST(str);
    Node* root=BuildTree(str);
    // cout<<root->data<<endl;
    // cout<<root->left->data<<endl;
    // cout<<root->right->data<<endl;
    PreOrder(root);
    cout<<endl;
    cout<<"Valid BST or not: "<<isValidate(root,NULL,NULL)<<endl;
    cout<<"Largest BST: "<<LargestBST(root)<<endl;
    // InOrder(root);
    return 0;
}