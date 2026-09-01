#include<iostream>
#include<list>
#include<vector>
using namespace std;
struct Graph{
    list<int> *l;
    int Gsz; //Graph size
    Graph(int Gsz){
        this->Gsz=Gsz;
        l=new list<int>[Gsz];
    }

    void addEdges(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }


    bool Helper(int u,int par,vector<bool> &visit){
        visit[u]=true;
        for(int neighbour:l[u]){
            if(!visit[neighbour]){
                if(Helper(neighbour,u,visit)){
                    return true;
                }
            }
            else if(neighbour!=par){
                return true;
            }
        }
        return false;
    }


    bool DetectCycleDFS(){
        vector<bool> visit(Gsz,false);
        for(int i=0;i<Gsz;i++){
            if(!visit[i]){
                if(Helper(i,-1,visit)){
                    return true;
                }
            }
        }
        return false;
    }


};
int main(){
    Graph g(5);
    g.addEdges(0,1);
    g.addEdges(0,2);
    g.addEdges(0,3);
    g.addEdges(1,2);
    g.addEdges(3,4);

    cout<<"Cycle detect or not: "<<g.DetectCycleDFS()<<endl;
    return 0;
}