#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Next{
    public:
    stack<int> s;

    vector<int> nextGreaterElement(vector<int> v){
        int n=v.size();
        vector<int> a(v.size(),0);
        for(int i=2*n-1;i>=0;i--){
            while(s.size()>0&&v[s.top()]<=v[i%n]){
                s.pop();
            }

            if(s.empty()){
                a[i%n]=-1;
            }
            else{
                a[i%n]=v[s.top()];
            }
            s.push(i%n);

        }
        return a;
        
    }
    

};
int main(){
    vector<int> v={3,6,5,4,2};
    Next n;
    vector<int> ans=n.nextGreaterElement(v);
    for(int value:ans){
        cout<<value<<" ";
    }
    return 0;
}