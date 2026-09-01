#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Span{
    public:
    // vector<int> ans; for my ownlogic
    stack<int> s;
    int span=0;

    vector<int> StockSpan(vector<int> stock){
        vector<int> ans(stock.size(),0);
        for(int i=0;i<stock.size();i++){

            while(s.size()>0&&stock[s.top()]<=stock[i]){
                s.pop();
            }
            //  for my own logic
            // if(s.empty()){
            //     span=i+1;
            //     s.push(i);
            //     ans.push_back(span);
            // }

            // if(stock[s.top()]>stock[i]){
            //     span=i-s.top();
            //     s.push(i);
            //     ans.push_back(span);
            // }
            if(s.empty()){
                ans[i]=i+1;
            }
            else{
                ans[i]=i-s.top();
            }
            s.push(i);
            
            }
            return ans;

        }
        

};
int main(){
    vector<int> stock={100,80,60,70,60,75,85};
    Span sp;

    vector<int> answer=sp.StockSpan(stock);
    for(int val:answer){
        cout<<val<<endl;
    }
    // sp.print();
    
    return 0;
}