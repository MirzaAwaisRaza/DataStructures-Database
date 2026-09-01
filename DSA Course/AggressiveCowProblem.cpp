#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
bool isPossible(int mindistance,int stalls,int Cows,vector<int> vec){
    int cow=1;
    int lastPosition=vec[0];
    for(int i=1;i<vec.size();i++){
        if(vec[i]-lastPosition>=mindistance){
            cow++;
            lastPosition=vec[i];
        }
        if(cow==Cows){
            return true;
        }
    }
    // return cow<Cows;
    return false;
}
int Aggressive(vector<int> vec){
    int n=5; //Stalls
    int c=3; // Cows
    sort(vec.begin(),vec.end());
    int s=vec.size();
    // int findmax=0;
    // int findmin=0;
    int ans=0;
    // for(int i=0;i<vec.size();i++){
    //     findmax=max(findmax,vec[i]);
    //     findmin=min(findmin,vec[i]);
    // }
    int start=1,end=vec[s-1]-vec[0];
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isPossible(mid,n,c,vec)){
            ans=mid;
           start=mid+1;
        }
        else{
            end=mid-1;
        }

    }
    return ans;
}
int main(){
    vector<int> vec={1,2,8,4,9};
    cout<<Aggressive(vec)<<endl;
    return 0;

}