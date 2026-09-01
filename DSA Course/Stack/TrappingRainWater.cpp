#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Trapping{
    public:
    int TrappingRainWater(vector<int> v){
        int n=v.size();
        vector<int> left(n,0);
        vector<int> right(n,-0);
        left[0]=v[0];
        right[n-1]=v[n-1];
        // for(int i=0;i<n-1;i++){
        //     int maxVal=0;
        //     if(v[i]>maxVal){
        //         maxVal=v[i];
        //         left[i]=maxVal;
        //     }
        //     left[i]=maxVal;
        // }

        // for(int i=n-1;i>0;i--){
        //     int maxVal=0;
        //     if(v[i]>maxVal){
        //         maxVal=v[i];
        //         right[i]=maxVal;
        //     }
        //     right[i]=maxVal;
        // }

        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],v[i]);
        }

        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],v[i]);
        }

        int totalWaterStored=0;
        for(int i=0;i<n;i++){
            int val=min(left[i],right[i])-v[i];
            totalWaterStored+=val;
        }

        return totalWaterStored;

    }


};
int main(){
    vector<int> v={4,2,0,3,2,5};
    Trapping t;
    cout<<"Total Stored water: "<<t.TrappingRainWater(v);
    return 0;
}