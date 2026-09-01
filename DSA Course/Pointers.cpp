#include<iostream>
using namespace std;

//Details are available on register

void ByValue(int x){
     x=20;
}

void ByReferencePointer(int* ptr){
    *ptr=20;
}

void ByReferenceAlias(int &z){

}

int main(){
    int a=10;
    int* ptr=&a; 
    int** ptr2=&ptr;

    cout<<&a<<endl;
    cout<<ptr<<endl; //this gives value means address  not its own address
    cout<<&ptr<<endl; //this gives address of ptr
    cout<<ptr2<<endl; //this gives ptr address 
    cout<<&ptr2<<endl; //this gives ptr2 address
    cout<<endl;

    // Deference Operator "*" All topics Detail in register
    cout<<*(&a)<<endl;
    cout<<*(ptr)<<endl;
    cout<<**(ptr2)<<endl;
    cout<<endl;

    // Null pointer
    int* ptr3;
    cout<<ptr3<<endl; //Its refer any address or give garbage address
    //  That's why we set it to null
     ptr3=NULL;
    cout<<ptr3<<endl;
    // cout<<&ptr3<<endl;
    cout<<endl; 


    // Practice Question
    int c=5;
    int* p=&c;
    int** q=&p;

    cout<<*p<<endl;
    cout<<**q<<endl;
    cout<<p<<endl;
    cout<<*q<<endl;
    cout<<endl;

    // Pass by value 
    int x=10;
    ByValue(x);
    cout<<"Pass by value"<<x<<endl;

    // Pass by Reference (by pointer)
    ByReferencePointer(&x);
    cout<<"Pass by Reference(pointer)"<<x<<endl;

    // Pass by Reference (by References(alias))  alias means "&" this is and symbol
    ByReferenceAlias(x);
    cout<<"Pass by reference(alias)"<<x<<endl;

    // Array Pointers (Arrays also known as array pointers)
    int arr[]={1,2,3,4};
    cout<<"Address: "<<arr<<endl;
    cout<<*arr<<endl;
    // int z=10;
    // arr=&z;  this is not possible because array can't store 
    // another variable address therefore array pointers are (constants pointers)
    // if array take another variable address then what happen with array stored data
    //who refer array stored data. Therefore it is not possible.
    cout<<*(arr+1)<<endl;
    cout<<*(arr+2)<<endl;
    cout<<*(arr+3)<<endl;
    cout<<endl;

    // Pointers addition:
    //Increament 
    int m=20;
    int* pr=&m;
    cout<<"Before adding: "<<pr<<endl;
    pr++;
    cout<<"After adding: "<<pr<<endl;
    //Same for decreament

    //Adding number in pointer
    pr=pr+4;
    cout<<"Adding a number: "<<pr<<endl;

    //Adding or subtracting two pointers
    int n=100;
    int* po=&n;
    int** po2=&po;
    cout<<((**po2+2)-*po)<<endl;

    //Comparing two pointers
    int* pointer1;
    int* pointer2=pointer1;
    cout<<(pointer1==pointer2)<<endl;
    cout<<(pointer1<pointer2)<<endl;
    cout<<endl;

    // Practice Question:
    int array[]={10,20,30,40};
    int *poi=array;

    cout<<*(poi + 1)<<endl;
    cout<<*(poi + 3)<<endl;
    poi++;
    cout<<*poi<<endl;
    return 0;
}