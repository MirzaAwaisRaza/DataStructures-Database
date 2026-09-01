#include<iostream>
using namespace std;

// There are also other concepts of operator precedence
//  and scope of variable and datatype modifiers
//  (Detail in register)


int main(){
    int a=7, b=3;
    cout<<(a & b)<<endl;
    cout<<(a | b)<<endl;
    cout<<(a ^ b)<<endl;

    cout<<(a<<b)<<endl; //left Shifting
    cout<<(a>>b)<<endl; //Right shifting
    return 0;
}