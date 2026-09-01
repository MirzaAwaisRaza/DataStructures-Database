#include<iostream>
using namespace std;
#include<vector>
bool isPossible(int maxAllowedTime,int painters,vector<int> vec){
    int painter=1;
    int time=0;
    for(int i=0;i<vec.size();i++){
        if(time+vec[i]<=maxAllowedTime){
            time+=vec[i];
        }
        else{
            painter++;
            time=vec[i];
        }
    }
    return painter<=painters;
}
int Painter(vector<int> vec){
    int painters=2;
    int board=4;
    int findmax=0;
    int sum=0;
    int answer=INT_MIN;
    for(int i=0;i<vec.size();i++){
        sum+=vec[i];
        findmax=max(findmax,vec[i]);
    }
    int start=findmax;
    int end=sum;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isPossible(mid,painters,vec)){
            answer=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return answer;
}
int main(){
    vector<int> vec={40,30,10,20};
    cout<<Painter(vec)<<endl;
    return 0;
}