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
    int preOrder=0;
    int KthSmallest(Node* root,int K){
        if(root==NULL){
            return -1;
        }
        if(root->left){
            int ls=KthSmallest(root->left,K);
            if(ls!=-1){
                return ls;
            }
        }
        
        if(preOrder+1==K){
            return root->data;
        }
        preOrder++;

        if(root->right){
            int rs=KthSmallest(root->right,K); 
            if(rs!=-1){
                return rs;
            } 
            
        }
        return -1;
    }
};

int main(){
    vector<int> str={1,2,3,4,5,6};
    Node* root=BuildBST(str);
    cout<<root->data<<endl;
    // InOrder(root);
    cout<<endl;
    Solution s;
    cout<<"Kth Smallest Element: "<<s.KthSmallest(root,4)<<endl;
    return 0;
}