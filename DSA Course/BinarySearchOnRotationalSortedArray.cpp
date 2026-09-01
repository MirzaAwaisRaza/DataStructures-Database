#include<iostream>
using namespace std;
#include<vector>

int RotationalSortedArray(vector<int> vec,int target){
int start=0;
int end=vec.size()-1;
int mid=0;
while(start<=end){
      mid=start+(end-start)/2;

    if(target==vec[mid]){
        return mid;
    }
    if(vec[start]<=vec[mid]){
        if(target>=vec[start]&&target<vec[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        
    }
    else{
        if(target>vec[mid]&&target<=vec[end]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        
    }

}
return -1;
}
int main(){
    vector<int> vec={3,4,5,6,7,0,1,2};
    int target=0;
    cout<<RotationalSortedArray(vec,target)<<endl;
    return 0;
}