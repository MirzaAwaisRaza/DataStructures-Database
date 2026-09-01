#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> BruteForce(vector<int>& vec){
    int n=vec.size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(vec[i]>vec[j]){
                swap(vec[i],vec[j]);
            }
        }
    }
    return vec;
}

vector<int> OptimzeWay(vector<int>& vec){
    int n=vec.size();
    int count0=0;
    int count1=0;
    int count2=0;
    for(int i=0;i<n;i++){
        if(vec[i]==0){
            count0++;
        }
        else if(vec[i]==1){
            count1++;
        }
        else if(vec[i]==2){
            count2++;
        }
        else{
            cout<<"Invalid Output:"<<endl;
        }

    }
    int index=0;
    for(int i=0;i<count0;i++){
        vec[index++]=0;
    }
    for(int i=0;i<count1;i++){
        vec[index++]=1;
    }
    for(int i=0;i<count2;i++){
        vec[index++]=2;
    }
    cout<<"These are counts for optimize Approach:"<<endl;
    cout<<count0<<endl;
    cout<<count1<<endl;
    cout<<count2<<endl;
    cout<<"Optmize Approach"<<endl;
    return vec;
}

vector<int> DNF(vector<int>& vec){
    int n=vec.size();
    int mid=0;
    int low=0;
    int high=n-1;
    while(mid<=high){
        if(vec[mid]==0){
            swap(vec[mid],vec[low]);
            low++;
            mid++;
        }
        else if(vec[mid]==1){
            mid++;
        }
        else if(vec[mid]==2){
            swap(vec[mid],vec[high]);
            high--;
        }
    }
    return vec;
}


int main() {
    vector<int> vec={2,0,2,1,1,0,1,2,0,0};
    cout<<"Brute Force:"<<endl;
    cout<<""<<endl;
    vector<int> vec2=BruteForce(vec);
    for(int i:vec2){
        cout<<i<<endl;
    }
    cout<<endl<<endl;

    vector<int> vec4={2,0,2,1,1,0,1,2,0,0};
    vector<int> vec3=OptimzeWay(vec4);
    for(int i:vec3){
        cout<<i<<endl;
    }

    cout<<endl<<endl;

    vector<int> vec5={2,0,2,1,1,0,1,2,0,0};
    cout<<"Dutch_National_Flag_Algorithm"<<endl;
    vector<int> vec6=DNF(vec5);
    for(int i:vec6){
        cout<<i<<endl;
    }



    return 0;
}