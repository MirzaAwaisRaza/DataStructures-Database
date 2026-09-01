#include<iostream>
#include<vector>
#include<list>
#include<stack>
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

    void dfs(int u,vector<bool> &visit,stack<int> &s){
        visit[u]=true;
        for(int neighbour:l[u]){
            if(!visit[neighbour]){
                dfs(neighbour,visit,s); 
            }
        }
        s.push(u);
    }

    void TopologicalSorting(){
        stack<int> s;
        vector<bool> visit(graphSize,false);
        for(int i=0;i<graphSize;i++){
            if(!visit[i]){
                dfs(i,visit,s);
            }
        }

        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
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

    g.TopologicalSorting();
    return 0;
}