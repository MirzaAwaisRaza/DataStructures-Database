#include<iostream>
using namespace std;
#include<vector>
#include <algorithm> 


vector<int> pairsum(vector<int> vec2,int target){
    vector<int> answer;
    for(int i=0;i<vec2.size();i++){
        for(int j=i+1;j<vec2.size();j++){
            int sum=vec2[i]+vec2[j];
            if(sum==target){
                answer.push_back(i);
                answer.push_back(j);
                return answer;

            }
        }
    }
    return answer;

}

vector<int> optimze_sum(vector<int> vec2,int target){
vector<int> ans;
int n=vec2.size();
int i=0;
int j=n-1;
while(i<j){
    int sum=vec2[i]+vec2[j];
    if(sum>target){
        j--;
    }
    else if(sum<target){
        i++;
    }
    else{
        ans.push_back(i);
        ans.push_back(j);
        return ans;
    }
}
return ans;

}

void Majority_BruteForce_LeetCode(vector<int> vec3){
    // Here bool is boolean datatype
    bool found=false;
    int n=vec3.size();
    for(int value:vec3){
        int frequency=0;
        for(int value2:vec3){
            if(value2==value){
                frequency++;
            }
        }
        if(frequency>n/2){
            found=true;
            cout<<value<<endl;
        }
    }
    if(!found){
          cout<<"Frequency is lower than your target";
    }
     
}

void Majority_optimize_LeetCode(vector<int>vec4){
    int n=vec4.size();
    sort(vec4.begin(),vec4.end());
    int frequency=1;
    int ans=vec4[0];
    for(int i=1;i<n;i++){
        if(vec4[i]==vec4[i-1]){
            frequency ++;
        }
        else{
            frequency=1;
            ans=vec4[i];
        }

        if(frequency>n/2){
         cout<<ans<<endl;
    }

    }
}

int  Majority_MoreesAlgorithm_LeetCode(vector<int> vec5){
int n=vec5.size();
int frequency=0;
int answer=0;
for(int i=0;i<n;i++){
    if(frequency==0){
        answer=vec5[i];
    }
    if(answer==vec5[i]){
        frequency++;
    }
    else{
        frequency--;
    }
}
int count=0;
for(int value:vec5){
    if(value==answer){
        count++;
    }
}
if(count>n/2){
    return answer;
}
else{
    return -1;
}
}

int main(){
    vector<int> vec2={2,7,11,13};
    int target=9;
    vector<int> answer=pairsum(vec2,target);

    if(answer.size() == 2) {
        cout << "Indices: " << answer[0] << "," << answer[1] << endl;
        cout << "Values: " << vec2[answer[0]] << "," << vec2[answer[1]] << endl;
    } else {
        cout << "No pair found!" << endl;
    }

    vector<int> answer2=optimze_sum(vec2,target);
    if(answer2.size() == 2) {
        cout << "Indices: " << answer2[0] << "," << answer2[1] << endl;
        cout << "Values: " << vec2[answer2[0]] << "," << vec2[answer2[1]] << endl;
    } else {
        cout << "No pair found!" << endl;
    }

    vector<int> vec3={1,2,2,1,1,};
    Majority_BruteForce_LeetCode(vec3);
    cout<<endl;

    vector<int> vec4={1,2,2,2,1,};

    Majority_optimize_LeetCode(vec4);

    vector<int> vec5={1,3,3,4,3,};
    cout<<endl;

    cout<<Majority_MoreesAlgorithm_LeetCode(vec5)<<endl;


    return 0;
}