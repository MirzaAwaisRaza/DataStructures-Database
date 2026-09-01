#include<iostream>
#include<vector>
#include<deque>
using namespace std;
class Sliding{
    public:
    vector<int> ans;
    deque<int> dq;
    vector<int> Maximum(vector<int> nums){
        int k=3;
        int n=nums.size();
        for(int i=0;i<k;i++){
            while(dq.size()>0&&nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for(int i=k;i<n;i++){
            ans.push_back(nums[dq.front()]);
            while(dq.size()>0&&nums[dq.front()]<=i-k){
                dq.pop_back();
            }
            while(dq.size()>0&&nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);

        return ans;
    }



};
int main(){
    Sliding s;
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    vector<int> a=s.Maximum(nums);

    for(int val:a){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}