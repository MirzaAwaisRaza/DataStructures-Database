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

void Dijkstra(int src,vector<vector<Edge>> &g,int graphSize){
    priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>> > pq;
    vector<int> distanceValue(graphSize,INT_MAX);
    distanceValue[src]=0;

    pq.push({0,src});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        for(Edge e:g[u]){
            if(distanceValue[e.v]>distanceValue[u]+e.wt){
                distanceValue[e.v]=distanceValue[u]+e.wt;
                pq.push({distanceValue[e.v],e.v});
            }
        }
    }

    for(int i=0;i<distanceValue.size();i++){
        cout<<distanceValue[i]<<" ";
    }
    cout<<endl;


}
int main(){
    int graphSize=6;
    vector<vector<Edge>> g(graphSize);
    g[0].push_back(Edge(1,2));
    g[0].push_back(Edge(2,4));

    g[1].push_back(Edge(2,1));
    g[1].push_back(Edge(3,7));

    g[2].push_back(Edge(4,3));

    g[3].push_back(Edge(5,1));

    g[4].push_back(Edge(3,2));
    g[4].push_back(Edge(5,5));

    Dijkstra(0,g,graphSize);

    return 0;
}