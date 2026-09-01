#include<iostream>
using namespace std;
#include<vector>


int Binary(vector<int> vec){
    int n=vec.size();
    int start=0;
    int end=n-1;
    int mid=0;
    int target=9;
    while(start<=end){
        mid=(start+end)/2;
        if(target>vec[mid]){
            start=mid+1;
            
        }
        else if(target<vec[mid]){
            end=mid-1;
            
        }
        else if(target==vec[mid]){
            return vec[mid];
        }
    }
    return -1;

}

int Optimze_Binary(vector<int> vec){
    int n=vec.size();
    int start=0;
    int end=n-1;
    int mid=0;
    int target=9;
    while(start<=end){
        mid=start+(end-start)/2;
        if(target>vec[mid]){
            start=mid+1;
            
        }
        else if(target<vec[mid]){
            end=mid-1;
            
        }
        else if(target==vec[mid]){
            return vec[mid];
        }
    }
    return -1;
}
int main(){
    vector<int> vec={1,3,5,7,9};
    cout<<"UnOptimize Approach:"<<endl;
    cout<<Binary(vec)<<endl;
    cout<<endl;
    cout<<"Optimize Approach in Binary Algorithim:"<<endl;
    // In optimze there is a single difference of mid formula.Formula changed 
    // Because when worst case come the unoptimze formula create lot of errors
    //  and we get a garbage value
    cout<<Optimze_Binary(vec)<<endl;
    cout<<endl;
    return 0;

}