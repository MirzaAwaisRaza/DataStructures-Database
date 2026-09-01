#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;
class Edge{
    public:
    int v; //Destination value or vertex
    int wt; // Weight value
    Edge(int v,int wt){
        this->v=v;
        this->wt=wt;
    }
};

void bellFord(int src,vector<vector<Edge>> &g,int graphSize){
    vector<int> distanceValue(graphSize,INT_MAX);
    distanceValue[src]=0;
    for(int i=0;i<graphSize-1;i++){
        for(int u=0;u<graphSize;u++){
            for(Edge e:g[u]){
                if(distanceValue[e.v]>distanceValue[u]+e.wt){
                    distanceValue[e.v]=distanceValue[u]+e.wt;   
                }
            }
        }
    }

    for(int i=0;i<distanceValue.size();i++){
        cout<<distanceValue[i]<<" ";
    }
    cout<<endl;


}
int main(){
    int graphSize=5;
    vector<vector<Edge>> g(graphSize);
    g[0].push_back(Edge(1,2));
    g[0].push_back(Edge(2,4));

    g[1].push_back(Edge(4,-1));
    g[1].push_back(Edge(2,-4));

    g[2].push_back(Edge(3,2));

    g[3].push_back(Edge(4,4));

    bellFord(0,g,graphSize);

    return 0;
}