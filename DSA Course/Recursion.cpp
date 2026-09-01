#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#include<string>

class A{
    public:
    int fib(int n){
        if(n==0||n==1){
            return n;
        }
        else{
            return fib(n-1)+fib(n-2);
        }
    }

    bool isSorted(vector<int> vec,int n){
        if(n==0||n==1){
            return true;
        }
        else{
            return vec[n-1]>=vec[n-2]&&isSorted(vec,n-1);
        }

    }

    int Search(int key,int st,int end,vector<int> vec){
        if(st<=end){

            int mid=st+(end-st)/2;

        if(key==vec[mid]){
            return mid;
        }

         if(key>vec[mid]){
            st=mid+1;
            return Search(key,st,end,vec);
        }
        else{
            end=mid-1;
            return Search(key,st,end,vec);
        }

        }
        return -1;
        
    }
};
class FindingSubset{
    public:
    void printSubset(vector<int>& v,vector<int>& subset,int i){
        int n=v.size();
        if(i==n){
            for(int value:subset){
                cout<<value<<" ";
            }
            cout<<endl;
            return;
        }
        subset.push_back(v[i]);
        printSubset(v,subset,i+1);
        subset.pop_back();
        printSubset(v,subset,i+1);
    }

};

int main(){
    vector<int> vec={1,2,3,4,5};
    int n=vec.size();

    vector<int> s={1,2,3,4,5};
    int ns=s.size();
    int st=0;
    int end=ns-1;

    vector<int> sub={1,2,3};
    vector<int> subset;
    A a;
    cout<<"Fibonacci: "<<a.fib(6)<<endl;
    cout<<" "<<endl;
    cout<<"Vector Sorting (1 for true OR 0 for false): "<<a.isSorted(vec,n)<<endl;
    cout<<" "<<endl;
    cout<<"Binary Search: "<<a.Search(5,st,end,vec)<<endl;
    cout<<" "<<endl;

    FindingSubset finding_subset;
    finding_subset.printSubset(sub,subset,0);
    return 0;
}