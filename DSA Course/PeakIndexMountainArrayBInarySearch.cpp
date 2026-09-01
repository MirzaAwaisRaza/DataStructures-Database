#include<iostream>
using namespace std;
#include<vector>

int OptimizeMountainArray(vector<int> vec){
    int end=vec.size()-2;
    int start=1;
    while(start<=end){
        int mid=start+(end-start)/2;
            if(vec[mid-1]<vec[mid]&&vec[mid]>vec[mid+1]){
                return mid;
            }
            else if(vec[mid-1]<vec[mid]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
    }
    return -1;

}

int main(){
    vector<int> vec={0,3,8,9,5,2};
    cout<<OptimizeMountainArray(vec)<<endl;

    return 0;
}