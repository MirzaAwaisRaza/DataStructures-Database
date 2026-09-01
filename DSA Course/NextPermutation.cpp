#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void NextPermutation(vector<int>& vec){
    int n=vec.size();
    int pivot=-1;
    for(int i=n-2;i>=0;i--){
        if(vec[i]<vec[i+1]){
            pivot=i;
            break;
        }
    }
    if(pivot==-1){
            // Two methods for reverse the array;
            // Method 1 using built in function in c++
            reverse(vec.begin(),vec.end());
            return;
            // Method 2 by loop
            // int st=0;
            // int end=n-1;
            // while(st<=end){
            //     swap(vec[st],vec[end]);
            // st++;
            // end--;
            // }
        }

    for(int i=n-1;i>pivot;i--){
        if(vec[i]>vec[pivot]){
            swap(vec[i],vec[pivot]);
            break;
        }
    }

    int i=pivot+1;
    int j=n-1;
    while(i<=j){
        swap(vec[i],vec[j]);
        i++;
        j--;
    }

}
void display(vector<int> A){
    int n=A.size();
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}
int main(){
    vector<int> A={1,2,3};
    NextPermutation(A);
    display(A);
    return 0;
}