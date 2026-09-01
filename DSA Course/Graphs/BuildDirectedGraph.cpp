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

};
int main(){
    Graph g(6);
    g.addEdges(3,1);
    g.addEdges(2,3);
    g.addEdges(4,0);
    g.addEdges(4,1);
    g.addEdges(5,0);
    g.addEdges(5,3);
    return 0;
}