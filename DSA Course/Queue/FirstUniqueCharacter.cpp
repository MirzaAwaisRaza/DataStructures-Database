#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;
class First{
    public:
    queue<int> q;
    unordered_map<char,int> m;
    int UniqueCharacter(string s){
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])==m.end()){
            q.push(i);
        }
            m[s[i]]++;

        while(q.size()>0&&m[s[q.front()]]>1){
            q.pop();
        }        
    }
    return q.empty()?-1:q.front();
}

};
int main(){
    First f;
    string s="level";
    cout<<"The index of unique character: "<<f.UniqueCharacter(s)<<endl;
    return 0;
}
