#include<iostream>
using namespace std;
#include<vector>

int SingleElement(vector<int> vec){
    int end=vec.size()-1;
    int n=vec.size();
    int start=0;
    if(n==1){
        return vec[0];
    }
        
    while(start<=end){
        int mid=start+(end-start)/2;
        if(mid==0&&vec[mid]!=vec[mid+1]){
            return vec[0];
        }
        if(mid==end&&vec[mid]!=vec[mid-1]){
            return vec[mid];
        }
        if(vec[mid-1]!=vec[mid]&&vec[mid]!=vec[mid+1]){
            return vec[mid];
        }

        else if(mid%2==0){
            if(vec[mid-1]==vec[mid]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        else{
            if(vec[mid-1]==vec[mid]){
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
    vector<int> vec={1,1,2,3,3,4,4,5,5};
    vector<int> vec1={1,1,2,2,3,4,5,5};
    cout<<SingleElement(vec1)<<endl;

    return 0;
}