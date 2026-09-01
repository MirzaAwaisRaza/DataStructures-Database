#include<iostream>
using namespace std;
#include<vector>
bool isValid(vector<int> vec,int n,int m,int maxAllowedPages){
    int students=1;
    int pages=0;
    for(int i=0;i<vec.size();i++){
        if(vec[i]>maxAllowedPages){
            return false;
        }
        if(pages+vec[i]<=maxAllowedPages){
            pages+=vec[i];
        }
        else{
            students++;
            pages=vec[i];
        }

    }
    return students>m?false:true;

}
int BookAllocation(vector<int> vec,int n,int m){
    if(m>n){
        return -1;
    }
    int sum=0;
    for(int i=0;i<vec.size();i++){
        sum+=vec[i];
    }
    int start=0;
    int end=sum;
    int answer=0;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isValid(vec,n,m,mid)){
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
    vector<int> vec={2,1,3,4};
    int m=2;
    int n=4;
    cout<<BookAllocation(vec,n,m)<<endl;
    return 0;
}