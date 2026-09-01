#include<iostream>
using namespace std;
#include<string>

// Decimal to binary conversion through program
int Decimal(int a){
int place=1;
int binary=0;
int reminder=0;

    while(a>0){
        reminder=a%2;
        binary+=reminder*place;
        place*=10;
        a=a/2;

    }
    return binary;

}

int Binary(int b){
    int decimal=0;
    int power=1;
    int reminder=0;
    while(b>0){
        reminder=b%10;
        decimal+=reminder*power;
        power*=2;
        b/=10;


    }
    return decimal;
}

int main(){

    // Decimal to binary conversion through program
    for(int i=2;i<10;i++){
    cout<<Decimal(i);
    cout<<"\n";
    }

    // Binary to Decimal
    cout<<Binary(101);
    return 0;
}