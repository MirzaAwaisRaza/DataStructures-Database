#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Rectangle{
    public:
    int Largearea=0;
    stack<int> s;
    int LargestArea(vector<int> heights){
        vector<int> right(heights.size(),0);
        vector<int> left(heights.size(),0);

        // right smaller nearest value:
        for(int i=right.size()-1;i>=0;i--){
            while(s.size()>0&&heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                right[i]=heights.size();
            }
            else{
                right[i]=s.top();
            }
            s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }

        // left smaller nearest value:
        for(int i=0;i<=left.size();i++){
            while(s.size()>0&&heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                left[i]=-1;
            }
            else{
                left[i]=s.top();
            }
            s.push(i);
        }

        
        for(int i=0;i<heights.size();i++){
            int width=left[i]-right[i]-1;
            int area=heights[i]*width;
            Largearea=max(Largearea,area);
        }
        return Largearea;
    }
};
int main(){
    vector<int> heights={2,1,5,6,2,3};
    Rectangle r;
    cout<<"Largest Area: "<<r.LargestArea(heights)<<endl;

    return 0;
}