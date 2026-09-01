#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Celebrity{
    public:
    stack<int> s;
    int CelebrityFinding(vector<vector<int>> v){
        int n=v.size();
        for(int i=0;i<n-1;i++){
            s.push(i);
        }
        while(s.size()>1){
            int i=s.top();
            s.pop();
            int j=s.top();
            s.pop();
            if(v[i][j]==0){
                s.push(i);
            }
            else{
                s.push(j);
            }
        }

        int celebrity=s.top();
        for(int i=0;i<n;i++){
            if(i!=celebrity&&v[i][celebrity]==0||v[celebrity][i]==1){
                return -1;
            }
            else{
                return celebrity;
            }
        }
        return celebrity;
    }
};
int main(){
    vector<vector<int>> v={{0,1,0},{0,0,0},{0,1,0}};
    Celebrity c;
    cout<<"Celebrity: "<<c.CelebrityFinding(v)<<endl;
    return 0;
}