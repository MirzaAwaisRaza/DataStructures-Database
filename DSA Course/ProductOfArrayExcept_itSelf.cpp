#include<iostream>
using namespace std;
#include <vector>

void BruteForce(vector<int> vec){
    int answer=1;
    for(int i=0 ;i<vec.size();i++){
        answer=1;
        for(int j=0;j<vec.size();j++){
            if(vec[i]!=vec[j]){
                // if(i!=j){  this line is for i you have same numbers in vector 
                // mean {1,2,2,4} so it compare indexes not numbers 
                // otherwise we got garbage value 
                answer*=vec[j];
            }
        }
        cout<<answer<<endl;
    }
}

vector<int> OptimizeTimeComplexity_withoutOptimizeSpaceComplexity(vector<int> vec){
    int n=vec.size();
    vector<int> prefix(n,1);
    vector<int> suffix(n,1);

    for(int i=1;i<vec.size();i++){
        prefix[i]=prefix[i-1]*vec[i-1];
    }

    for(int i=n-2;i>=0;i--){
        suffix[i]=suffix[i+1]*vec[i+1];
    }

    for(int i=0;i<vec.size();i++){
        vec[i]=prefix[i]*suffix[i];
    }

    return vec;

}

vector<int> OptimizeTime_SpaceComplexity(vector<int> vec){
     int n=vec.size();
    // vector<int> prefix(n,1);
    // vector<int> suffix(n,1);
    vector<int> answer(n,1);

    for(int i=1;i<vec.size();i++){
        answer[i]=answer[i-1]*vec[i-1];
    }

    int suffixvariable=1;
    for(int i=n-2;i>=0;i--){
        suffixvariable*=vec[i+1];
        answer[i]=answer[i]*suffixvariable;
    }
    return answer;

}

int main(){

    vector<int> vec={1,2,3,4};
    cout<<"BruteForce"<<endl;
    BruteForce(vec);
    cout<<endl;

    cout<<"OptimizeTimeComplexity_withoutOptimizeSpaceComplexity:"<<endl;
    vector<int> result = OptimizeTimeComplexity_withoutOptimizeSpaceComplexity(vec);
for(int x : result){
    cout <<  x << endl;
}
cout<<endl;

cout<<"OptimizeTime_SpaceComplexity:"<<endl;
 vector<int> result1 = OptimizeTime_SpaceComplexity(vec);
for(int x : result1){
    cout <<  x << endl;
}

    return 0;

}