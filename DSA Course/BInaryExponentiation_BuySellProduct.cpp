#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

double Binary(int n){
    double answer=1;
    double x=3;  //power calculating

    if(n<0){
        n=-n;
    }
    
    while(n>0){
        if(n%2==1){
            answer*=x;
        }
        x*=x;
        n/=2;
    }
    return answer;

}

int Profit_Loss(vector<int> vec2){
    int maxProfit=0;
    int bestBuy=vec2[0];
    int s=vec2.size();
    for(int i=0;i<s;i++){
        if(vec2[i]>bestBuy){
            maxProfit=max(maxProfit,vec2[i]-bestBuy);
        }
            bestBuy=min(bestBuy,vec2[i]);

    }
    return maxProfit;
}

int main(){

    vector<int> vec={7,1,3,6,4};

    cout<<"Binary Exponentiation:"<<endl;
    cout<<Binary(5)<<endl;  //Here 5 is power of 3 means 3 range power 5  "3^5" 
    // it is equal to 243
    cout<<Profit_Loss(vec)<<endl;
    return 0;
}