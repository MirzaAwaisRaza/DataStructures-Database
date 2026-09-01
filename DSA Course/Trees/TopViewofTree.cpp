#include<iostream>
#include<map>
#include<queue>
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
void topView(Node* root){
    queue<pair<Node*,int>> q;
    map<int,int> m;
    Node* curr;
    int hd; //Horizontal Distance
    q.push({root,0});
    while(q.size()>0){
        curr=q.front().first;
        hd=q.front().second;
        q.pop();
        if(m.find(hd)==m.end()){
            m[hd]=curr->data;
        }
        // cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push({curr->left,hd-1});
        }
        if(curr->right!=NULL){
            q.push({curr->right,hd+1});
        }

    }
    for(auto it: m){
        cout<<it.second<<" ";
    }
    cout<<endl;

}
int main(){
    vector<int> preOrder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildTree(preOrder);
    topView(root);
    return 0;
}