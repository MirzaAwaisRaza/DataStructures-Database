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
Node* getInOrderSuccessor(Node* root){
    while(root!=NULL&&root->left!=NULL){
        root=root->left;
    }
    return root;

}
Node* DeleteNode(Node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(key>root->data){
        root->right=DeleteNode(root->right,key);
    }
    else if(key<root->data){
        root->left=DeleteNode(root->left,key);
    }
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else{
            //Inorder Successor
            Node* IS=getInOrderSuccessor(root->right);
            root->data=IS->data;
            root->right=DeleteNode(root->right,IS->data);
        }
    }
    return root;
}
int main(){
    vector<int> str={3,2,1,5,6,4};
    Node* root=BuildBST(str);
    // cout<<root->data<<endl;
    cout<<"Before:"<<" ";
    InOrder(root);
    cout<<endl;
    DeleteNode(root,2);
    cout<<"After:"<<" ";
    InOrder(root);
    cout<<endl;
    return 0;
}