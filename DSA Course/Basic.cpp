# include<iostream>
// if we need string datatype we need to import this datatype
//  from the library as i done below. otherwise compiler gives error.
# include <string>
using namespace std;
// We must make function outside the main. 
// Recommendation is to create function before the main and
//  then call it inside the main otherwise
//  if you make function after the main() function
//  you must need to create its prototype for avoiding errors
//  protype means before main we write int add(int a,int b). and
//  then write main() function after this we make the overall function 
int  sum(int a , int b){
int add=a+b;
return add;
}

// In this function i use for loop for practice
void wins(string country){
    for(int i=0;i<10;i++){
        cout<<country<<"\n";
    }
}


// One thing important we only declare variable outside the function.
//  We can't use cout<< for printing and cin>> for taking input
//  from the user otherwise we get error

// This function is for if else practice
void grades(int marks){
    if(marks>90){
        cout<<"Grade: A";
    }
    else if(marks>80){
        cout<<"Grade: B";
    }
    else if(marks>70){
        cout<<"Grade: C";
    }
    else if(marks>60){
        cout<<"Grade: D";
    }
    else if(marks>50){
        cout<<"Grade: E";
    }
    else{
        cout<<"Legend is born";
    }
}

// I declare and initialize the variables outside the main function 
// for make them globally accessable.
//  we also declare them inside the main but it is not globally used.

float gpa=3.77;
string name="ScarFace";
string country="Pakistan Wins the World Cup";

//Type casting
// implicit type casting this is done automatically 
char grade='a'; //ASCII value of small a is 97 
// when i typecast it. It give me value 
// according to datatype i changed.
int implicit=grade;

// Explicit typeCasting This is done by programmer
double mysize=99.22;
int changesize=(int)mysize;
// i convert double to integer forcefully


char findingchar(char c1){
        if(c1=='a'||c1=='A'){
            return c1;
        }
        else if(c1=='b'||c1=='B'){
            return c1;
        }
        else if(c1=='c'||c1=='C'){
            return c1;
        }
        else if(c1=='d'||c1=='D'){
            return c1;
        }
        else if(c1=='e'||c1=='E'){
            return c1;
        }
        else if(c1=='f'||c1=='F'){
            return c1;
        }
        else if(c1=='g'||c1=='G'){
            return c1;
        }
        else if(c1=='h'||c1=='H'){
            return c1;
        }
        else if(c1=='i'||c1=='I'){
            return c1;
        }
        else if(c1=='j'||c1=='J'){
            return c1;
        }
        else if(c1=='k'||c1=='K'){
            return c1;
        }
        else if(c1=='l'||c1=='L'){
            return c1;
        }
        else if(c1=='m'||c1=='M'){
            return c1;
        }
        else if(c1=='n'||c1=='N'){
            return c1;
        }
        else if(c1=='o'||c1=='O'){
            return c1;
        }
        else if(c1=='p'||c1=='P'){
            return c1;
        }
        else if(c1=='q'||c1=='Q'){
            return c1;
        }
        else if(c1=='r'||c1=='R'){
            return c1;
        }
        else if(c1=='s'||c1=='S'){
            return c1;
        }
        else if(c1=='t'||c1=='T'){
            return c1;
        }
        else if(c1=='u'||c1=='U'){
            return c1;
        }
        else if(c1=='v'||c1=='V'){
            return c1;
        }
        else if(c1=='w'||c1=='W'){
            return c1;
        }
        else if(c1=='x'||c1=='X'){
            return c1;
        }
        else if(c1=='y'||c1=='Y'){
            return c1;
        }
        else if(c1=='z'||c1=='Z'){
            return c1;
        }
        else{
            cout<<"Only (a,A to z,Z)";
            return 0;
        }

    }

int main(){
    string course;
    cout << "Enter course Name: ";
    // Here cin>>  is used for taking input from the user. 
    cin >> course;
    
    cout<<"Course Name: "<<course<<"\n";
    cout<<implicit<<"\n";
    cout<<changesize<<"\n";
    cout<<"Name:"<<name <<" gpa: "<<gpa <<"\n";
    cout<<"Sum: "<<sum(5,10);
    cout<<"\n";


 // cout<< used for printing any value or anything
// Here cin>> used for taking input from the user
//  you don't any import for that user input

    int marks;
    cout<<"Enter marks: ";
    cin>>marks;

    grades(marks);
    cout<<"\n";

    char c1;
    cout<<"Enter char: ";
    cin>>c1;
    cout<<"char:"<<"Successfully find: "<<findingchar(c1)<<"\n";
    wins(country);
}
