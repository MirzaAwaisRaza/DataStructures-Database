#include<iostream>
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
int MaxWidthTree(Node* root){
    queue<pair<Node*,int>> q;
    int maxWidth=0;
    q.push({root,0});
    while(q.size()>0){
        int stIdx=q.front().second;
        int endIdx=q.back().second;
        int maxWidth=max(maxWidth,endIdx-stIdx+1);
        for(int i=0;i<q.size();i++){
            auto currNode=q.front();
            q.pop();
            if(currNode.first->left){
                q.push({currNode.first->left,currNode.second*2+1});
            }
            if(currNode.first->right){
                q.push({currNode.first->right,currNode.second*2+2});
            }
        }
    }
    return maxWidth;


}
int main(){
    vector<int> preOrder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=BuildTree(preOrder);
    return 0;
}