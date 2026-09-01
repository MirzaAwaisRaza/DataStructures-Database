#include<iostream>
#include<list>
#include<vector>
using namespace std;
struct Graph{

    int size; // Size for the vertices
    list<int> *l;
    
    Graph(int size){
        this->size=size;
        l=new list<int>[size];
    }

    void addEdges(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int i=0;i<size;i++){
            cout<<i<<" : ";
            for(int neighbour:l[i]){
                cout<<neighbour<<" ";
            }
            cout<<endl;
        }
    }

    void dfsHelper(int u,vector<bool> &visit){
        cout<<u<<" ";
        visit[u]=true;
        for(int neighbour:l[u]){
            if(!visit[neighbour]){
                dfsHelper(neighbour,visit);
            }
        }
    }

    void DFS(){
        int src=0;
        vector<bool> visit(size,false);
        dfsHelper(src,visit);

    }

};
int main(){
    Graph g(5);
    g.addEdges(0,1);
    g.addEdges(1,2);
    g.addEdges(1,3);
    g.addEdges(2,4);
    g.addEdges(2,3);
    
    g.DFS();
    return 0;
}