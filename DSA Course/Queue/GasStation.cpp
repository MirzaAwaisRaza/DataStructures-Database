#include<iostream>
#include<vector>
using namespace std;
class Gas{
    public:
    int GasStation(vector<int> gas,vector<int> cost){
        int totalgas=0,totalcost=0;
        int currentgas=0,start=0;
        // for(int val:gas){
        //     totalgas+=val;
        // }
        // for(int value:cost){
        //     totalcost+=value;
        // }
        // if(totalgas<totalcost){
        //     return -1;
        // }
        for(int i=0;i<cost.size();i++){
            totalgas+=gas[i];
            totalcost+=cost[i];
            
            currentgas+=(gas[i]-cost[i]);
            if(currentgas<0){
                start=i+1;
                currentgas=0;
            }
            
        }
        return totalgas<totalcost?-1:start;
        // return start;
    }


};
int main(){
    vector<int> gas={1,2,4,5,9};
    vector<int> cost={3,4,1,10,1};
    Gas g;
    cout<<g.GasStation(gas,cost)<<endl;
    return 0;
}



