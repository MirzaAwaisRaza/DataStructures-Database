#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Next{
    public:
    stack<int> s;

    vector<int> nextGreaterElement(vector<int> v){
        vector<int> a(v.size(),0);
        for(int i=0;i<=v.size()-1;i++){
            while(s.size()>0&&s.top()>=v[i]){
                s.pop();
            }

            if(s.empty()){
                a[i]=-1;
            }
            else{
                a[i]=s.top();
            }
            s.push(v[i]);

        }
        return a;
        
    }
    

};
int main(){
    vector<int> v={3,1,0,8,6};
    Next n;
    vector<int> ans=n.nextGreaterElement(v);
    for(int value:ans){
        cout<<value<<" ";
    }
    return 0;
}