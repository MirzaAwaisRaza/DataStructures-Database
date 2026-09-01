#include<iostream>
#include<list>
#include<queue>
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


    bool Helper(int src,vector<bool> &visit){
        queue<pair<int,int>> q;
        q.push({src,-1});
        visit[src]=true;
        while(q.size()>0){
            int u=q.front().first;
            int par=q.front().second;
            q.pop();

            for(int neighbour:l[u]){
                if(!visit[neighbour]){
                    q.push({neighbour,u});
                    visit[neighbour]=true;
                }
                else if(neighbour!=par){
                    return true;
                }
            }
        }
        return false;
    }


    bool DetectCycleBFS(){
        vector<bool> visit(Gsz,false);
        for(int i=0;i<Gsz;i++){
            if(!visit[i]){
                if(Helper(i,visit)){
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

    cout<<"Cycle detect or not: "<<g.DetectCycleBFS()<<endl;
    return 0;
}