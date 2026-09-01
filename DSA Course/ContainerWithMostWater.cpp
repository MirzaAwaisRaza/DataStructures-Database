#include <iostream>
using namespace std;
#include <vector>

int BruteForceMostWater(vector<int> vec2){
    int size=vec2.size();
    int width=0;
    int height=0;
    int area=0;
    int MaxWater=0;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            width=j-i;
            height=min(vec2[i],vec2[j]);
            area=width*height;
            MaxWater=max(MaxWater,area);
        }
    }
    return MaxWater;
}

int OptimizeTwoPointerApproach_MostWater(vector<int> vec2){
    int leftPointer=0;
    int RightPointer=vec2.size()-1;
    int MaxWater=0;
    while(leftPointer<RightPointer){
        int width=RightPointer-leftPointer;
        int heigth=min(vec2[leftPointer],vec2[RightPointer]);
        int CurrentWater=width*heigth;
        MaxWater=max(MaxWater,CurrentWater);
        vec2[leftPointer]<vec2[RightPointer]?leftPointer++:RightPointer--; //it used instead of if_else
        // if(leftPointer<RightPointer){
        //     leftPointer++;
        // }
        // else{
        //     RightPointer--;
        // }
    }
    return MaxWater;

}

int main(){
    vector<int> vec={1,8,6,2,5,4,8,3,7};
    cout<<BruteForceMostWater(vec)<<endl;
    cout<<OptimizeTwoPointerApproach_MostWater(vec)<<endl;
    return 0;
}