#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void ValidPalidrome(vector<string> str){
    int n=str.size();
    int st=0;
    int end=n-1;
    while(st<=end){
        reverse(str[st],str[end]);
    }

    

}
int main(){

    vector<string> str ={"racecar"};
    ValidPalidrome(str);
    string s="daabcbaabcbc";
    string part="abc";
    int point=s.find(part);
    while(point>0&&point<s.length()){
        point=s.find(part);
    if(s.find(part)<s.length()){
        s.erase(point,part.length());
    }
    }
     
    //  int point1=s.find(part);
    // if(s.find(part)<s.length()){
    //     s.erase(point1,part.length());
    // }
    //  int point2=s.find(part);
    // if(s.find(part)<s.length()){
    //     s.erase(point2,part.length());
    // }

    cout<<"remaining string is:"<<s<<endl;

    return 0;
}