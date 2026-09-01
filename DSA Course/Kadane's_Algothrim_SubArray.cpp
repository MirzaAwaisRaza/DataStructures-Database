#include<iostream>
using namespace std;

void Printing_Subarray(){
    // Subarray Printing
    int arr[5]={1,2,3,4,5};
    int size=5;
    int start;
    int end;
    for(start=0;start<size;start++){
        for(end=start;end<size;end++){
            for(int i=start;i<=end;i++){
                cout<<arr[i];
            }
            cout<<" ";
        }
        cout<<endl;
    }
}

void SumMax_Subarray(){
    int arr[7]={3,-4,5,4,-1,7,-8};
    int start;
    int end;
    int maxsum=INT_MIN;
    int size=7;
    for(start=0;start<size;start++){
        int currentsum=0;
        for(end=start;end<size;end++){
            currentsum+=arr[end];
            maxsum=max(currentsum,maxsum);
        }
    }
     cout<<maxsum<<endl;
}

void Kadanes_Algorithim_leetCode(){
    int arr[7]={3,-4,5,4,-1,7,-8};
    int currentsum=0;
    int maxsum=INT_MIN;
    for(int i=0;i<7;i++){
         currentsum+=arr[i];
        maxsum=max(currentsum,maxsum);
        if(currentsum<0){
            currentsum=0;
        }
    }
    cout<<maxsum<<endl;
}

int main(){
    Printing_Subarray();
    cout<<endl;
    SumMax_Subarray();
    cout<<endl;
    Kadanes_Algorithim_leetCode();
    
    return 0;
}