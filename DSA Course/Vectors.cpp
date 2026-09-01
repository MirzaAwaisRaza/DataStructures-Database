#include<iostream>
// must import vector library
#include<vector>
using namespace std;


// Here " ^ " is XOR operator and & symbol is used 
// to pass by reference.Also used to change 
// original value of vector 
int single(vector<int>& vec1){
    int result=0;
    for(int value:vec1){
        result^=value;
    }
    return result;
}

int main(){
    
    vector<int> vec;
    
    // vector<int> vec={1,2,3};
    
    // vector<int> vec(3,2);

    cout<<"Before pushing Size:"<<endl;
    cout<<"Size of Vector: "<<vec.size()<<endl;

    vec.push_back(25);
    vec.push_back(35);
    vec.push_back(45);


    vec.pop_back();


    for(int value:vec){
        cout<<value<<endl;
    }
    

    cout<<"After pushing Size:"<<vec.size()<<endl;

    
    cout<<vec.front()<<endl;
    cout<<vec.back()<<endl;
    cout<<vec.at(1)<<endl;

    cout<<"Leet Code Problem:"<<endl;
    // Single Number Its a leet Problem;
    vector<int> vec1={4,1,2,1,2};
    // In this we find the unique value 
    // and we are only allow to use or declare one variable.
    // The values are 4 ,1,2,1,2 and our task is to print
    //  unique value which is 4. for this purpose i use 
    // XOR operator " ^ " and use property of XOR
    //  0^0=0 , 0^1=1 so same for result= result^ vec1.
    //  same same give zero means they are cancel out
    //  and we get our result by cancelling all of these value 
    // 1,2,1,2

    cout << single(vec1) << endl;
    return 0;
}