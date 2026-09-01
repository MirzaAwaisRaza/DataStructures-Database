#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
class Graph{
    public:

    int graphSize=0;
    list<int> *l;
    Graph(int graphSize){
        this->graphSize=graphSize;
        l=new list<int>[graphSize];
    }

    void addEdges(int u,int v){
        l[u].push_back(v); //This is for directed graph
    }

    void kahnAlgorithm(){
        vector<int> ans;
        vector<int> indegree(graphSize,0);
        queue<int> q;

        for(int u=0;u<graphSize;u++){
            for(int neighbour:l[u]){
                indegree[neighbour]++;
            }
        }

        for(int i=0;i<graphSize;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(int neighbour:l[curr]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }

        }

        if(ans.size() != graphSize){
        cout<<"Cycle detected! Topological sort not possible.";
        return;
        }

        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }

};
int main(){
    Graph g(6);
    g.addEdges(3,1);
    g.addEdges(2,3);
    g.addEdges(4,0);
    g.addEdges(4,1);
    g.addEdges(5,0);
    g.addEdges(5,3);

    g.kahnAlgorithm();
    return 0;
}