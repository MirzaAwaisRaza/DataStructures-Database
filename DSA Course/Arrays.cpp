#include<iostream>
using namespace std;

int find(int num[]){
    int search=8;
    for(int i=0;i<5;i++){
        if(num[i]==search){
            return i;
        }
    }
    return -1;
}

void reverseArray(int reverse[]){
    int temp[5];  // extra array to hold reversed values

    for(int i=0;i<5;i++){
        if(reverse[i]==4){
            temp[4]=reverse[i];
        }
        else if(reverse[i]==5){
            temp[3]=reverse[i];
        }
        else if(reverse[i]==8){
            temp[2]=reverse[i];
        }
        else if(reverse[i]==2){
            temp[1]=reverse[i];
        }
        else if(reverse[i]==1){
            temp[0]=reverse[i];
        }
    }

    // print reversed array
    for(int i=0;i<5;i++){
        cout<<temp[i]<<endl;
    }
}

void originalReverse(int originalArray[]){
    int s=0;
    int e=4;

    while(s<e){
        swap(originalArray[s],originalArray[e]);
        s++;
        e--;
    }
    for(int i=0;i<5;i++){
        cout<<originalArray[i]<<endl;
    }

}

int main(){
    int marks[5]={99,98,10,44,22};
    for(int i=0;i<5;i++){
        cout<<marks[i]<<endl;
    }
    
    int num[5]={4,5,8,2,1};
    cout<<"Index of finding number"<<endl;
    cout<<find(num)<<endl;

    int reverse[5]={4,5,8,2,1};
    cout<<"After Reversing Array:"<<endl;
    reverseArray(reverse);

    int original[5]={1,2,3,4,5};
    cout<<"reversing original array"<<endl;
    originalReverse(original);
    
    return 0;
}
