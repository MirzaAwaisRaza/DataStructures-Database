#include<iostream>
using namespace std;
#include<vector>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node* next;
    Node(int data){
        this->data=data;
        left=right=next=NULL;
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
Node* populatePointer(Node* root){
    if(root==NULL||root->left==NULL||root->right==NULL){
        return root;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    Node* prev=NULL;
    while(q.size()>0){
    Node* curr=q.front();
    q.pop();
    if(curr==NULL){
        if(q.size()==0){
            break;
        }
        q.push(NULL);
    }
    else{
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
        if(prev!=NULL){
            prev->next=curr;
        }
        }
        prev=curr;
        }
    return root;
}
int main(){
    vector<int> str={1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};
    // Node* root=BuildBST(str);
    Node* root=BuildTree(str);
    // cout<<root->data<<endl;
    // cout<<root->left->data<<endl;
    // cout<<root->right->data<<endl;
    PreOrder(root);
    cout<<endl;
    // InOrder(root);
    Node* PNRP=populatePointer(root);
    cout<<PNRP->next<<endl;
    return 0;
}