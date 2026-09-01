#include<iostream>
#include<list>
#include<queue>
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

    void BFS(){
        vector<bool> visit(size,false);
        queue<int> q;
        q.push(0);
        visit[0]=true;
        while(q.size()>0){
            int u=q.front();
            q.pop();
            cout<<u<<" ";

            for(int neigbour:l[u]){
                if(!visit[neigbour]){
                    visit[neigbour]=true;
                    q.push(neigbour);
                }
            }
        }
        cout<<endl;
    }

};
int main(){
    Graph g(5);
    g.addEdges(0,1);
    g.addEdges(1,2);
    g.addEdges(1,3);
    g.addEdges(2,4);
    g.addEdges(2,3);

    g.BFS();
    return 0;
}