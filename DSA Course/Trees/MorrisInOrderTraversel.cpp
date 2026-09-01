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
Node* IpPre(Node* Ip,Node* curr){
    while(Ip->right!=NULL&&Ip->right!=curr){
        Ip=Ip->right;
    }
    return Ip;
}
vector<int> MorrisInOrder(Node* root){
    vector<int> ans;
    Node* curr=root;
    
    while(curr!=NULL){
        if(curr->left==NULL){
            // cout<<curr->data<<" ";
            ans.push_back(curr->data);
            curr=curr->right;
        }
        else{
            Node* Ip=curr->left;
            IpPre(Ip,curr);
            if(Ip->right==NULL){
            Ip->right=curr; //Create Thread
            curr=curr->left;
        }else{
            Ip->right=NULL; //Break Thread;
            // cout<<curr->data<<" ";
            ans.push_back(curr->data);
            curr=curr->right;
        }

    }
}
    return ans;
    

}
int main(){
    vector<int> preOrder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildTree(preOrder);
    vector<int> v=MorrisInOrder(root);
    for(int val:v){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}