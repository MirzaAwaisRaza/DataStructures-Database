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
void InOrder(Node* root){
    if(root==NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);

}
class Solution{
    public:
Node* pred=NULL; //Inorder predecessor
Node* succ=NULL; //Inorder Successor
vector<int> IPAndIS(Node* root, int key){
    while(root!=NULL){
        if(root==NULL){
            break;
        }
        if(key<root->data){
        succ=root;
        root=root->left;
        }
        
        else if(key>root->data){
            pred=root;
            root=root->right;
        }
        else{
            if(root->left!=NULL){
                pred=rightMostInLeftSubtree(root->left);
            }
            if(root->right!=NULL){
                succ=leftMostInRightSubtree(root->right);
            }
            break;
        }
        
    }
    return {pred->data,succ->data};
}
Node* rightMostInLeftSubtree(Node* root){
    Node* ans=NULL;
    while(root!=NULL){
        ans=root;
        root=root->right;
    }
    return ans;
}

Node* leftMostInRightSubtree(Node* root){
    Node* ans=NULL;
    while(root!=NULL){
        ans=root;
        root=root->left;
    }
    return ans;
}
};
void PreOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);

}
int main(){
    vector<int> str={6,4,8,1,5,7,9};
    Node* root=BuildBST(str);
    // cout<<root->data<<endl;
    // InOrder(root);
    PreOrder(root);
    cout<<endl;
    Solution s;
    vector<int> ans=s.IPAndIS(root,7);
    cout<<"Predecessor: "<<ans[0]<<endl;
    cout<<"Successor: "<<ans[1]<<endl;
    cout<<endl;
    return 0;
}