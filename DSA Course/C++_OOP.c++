#include<iostream>
#include<string>
using namespace std;
#include<algorithm>
// Single-level Inheritance:
class Teacher{
    protected:
    string name;
    double salary;
    string department;
    public:
    void setName(string name){
        this->name=name;
    }
    string getName(){
        return name;
    }
    void setSalary(double salary){
        this->salary=salary;
    }
    double getSalary(){
        return salary;
    }
    void setDepartment(string department){
        this->department=department;
    }
    string getDepartment(){
        return department;
    }
    public:
    Teacher(string name,double salary,string department){
        this->name=name;
        this->salary=salary;
        this->department=department;
    }
};
class Student:public Teacher{
    public:
    float GPA;
    Student(string name,double salary,string department,float GPA):Teacher(name,salary,department){
        this->GPA=GPA;
    }

    void setGPA(float GPA){
        this->GPA=GPA;
    }
    float getGPA(){
        return GPA;
    }
    void displayInfo(){
        cout<<"Department:"<<this->department<<" Name: "<<this->name<<" GPA: "<<this->GPA<<endl;
    }
};
class Account{
    private:
    string username;
    string password;
    int balance;
    public:
    Account(string username,string password,int balance){
        this->username=username;
        this->password=password;
        this->balance=balance;
    }
    void setuserName(string username){
        this->username=username;
    }
    void setPassword(string password){
        this->password=password;
    }
    void setbalance(int balance){
        this->balance=balance;
    }
    string getuserName(){
        return username;
    }
    string getPassword(){
        return password;
    }
    int getBalance(){
        return balance;
    }

    void withdraw(int withdraw){
        if(withdraw>0&&withdraw<balance){
            balance-=withdraw;
            cout<<"Remaining balance:"<<balance;
        }
        else{
            cout<<"In sufficient Funds"<<endl;
        }
    }

};

class Info{
    public:
    string name;
    double* GPAptr;

    // Shallow copy
    Info(string name,double gpa){
        this->name=name;
        GPAptr=new double;
        *GPAptr=gpa;
    }
    Info(Info &obj){
        this->name=obj.name;
        this->GPAptr=obj.GPAptr;

    }


    // Deep copy:
    // Info(string name,double gpa){
    //     this->name=name;
    //     GPAptr=new double;
    //     *GPAptr=gpa;
    // }
    // Info(Info &obj){
    //     this->name=obj.name;
    //     GPAptr=new double;
    //     *GPAptr=*(obj.GPAptr);

    // }

};

// class Car{
//     public:
//     string name;
//     string* Numptr;
//     Car(string name,string carNumber){
//         this->name=name;
//         Numptr=new string;
//         *Numptr=carNumber;
//     }

    //Create Destructor
    // Default Destructor
    // ~Car(){
    //     cout<<"I delete everthing:"<<endl;
    // }

    // Custom Destructor
    // ~Car(){
    //     cout<<"I delete everthing:"<<endl;
    //     delete Numptr; //this line is specially for deleting dynamic heap memory
    // }

// };

// Multi_level Inheritance:
class Person{
    public:
    string name;
    int age;
};
class Student1:public Person{
    public:
    int rollNo;
};
class GraduateStudents:public Student1{
    public:
    string researchProject;
    void display(){
        cout<<"name:"<<name<<" age:"<<age<<" rollNo:"<<rollNo<<" Research Project:"<<researchProject<<endl;
    }

};

// Mulitple Inheritance:
class Student2{
    public:
    string name;
    int rollNo;
};
class Teacher1{
    public:
    int salary;
};
class StudentsAsTeachers:public Teacher1,public Student2{ //Means such teachers which study like phd
    //  and also teach in that institute
    public:
    string subject; 
    void displayInfo(){
        cout<<"Name:"<<name<<" rollNo: "<<rollNo<<" salary: "<<salary<<" subject: "<<subject;
    }

};

// Polymorphism:
// Dynamic polymorphism(Run time polymorphism):
// the best example for dynamic polymorphism is function overridden or overridding
class Parent{
    public:
    void hello(){
        cout<<"Hello from parent class"<<endl;
    }
};
class Child:public Parent{
    void hello(){
        cout<<"Hello from child class"<<endl;
    }
};

//Compile Time Polymorphism:
// through method overloading and constructor overloading 
class CT{
    public:
    string name;
    string hobby;
    void display(string name){
        this->name=name;
        cout<<"Name:"<<name<<endl;
    }
    void display(string name, string hobby){
        this->name=name;
        this->hobby=hobby;
        cout<<"Name:"<<name<<" Hobby:"<<hobby<<endl;
    }

};

// Abstraction:
class Shape{
    virtual void draw()=0;
};
class ShapeInfo{
    virtual void filled()=0;
};
class Circle:public Shape,public ShapeInfo{
    public:
    void draw(){
        cout<<"Draw a circle:"<<endl;
    }
    void filled(){
        cout<<"Circle is filled internally"<<endl;
    }
};

// static keyword:
// static variable:
class A{
    public:
    int x;
    // static int x; //uncomment this line to check and comment the normal 
    void increamentA(){
        x=x+1;
    }

};
// static objects:
class objects{
    public:
    objects(){
        cout<<"I am the constructor of the object:"<<endl;
    }
    // now built destructor:
    // We built destructor in this class in order to understand the concept of the 
    // static objects
    ~objects(){
        cout<<"Destructor destroy all the things of this object"<<endl;
    }

};

int main(){
    

    // Shallow copy:
    Info i("Zubair",3.5);
    Info i2(i);
    cout<<"Name:"<<i.name<<endl;
    cout<<"Gpa:"<<*i.GPAptr<<endl;
    i2.name="Faisal";
    *i2.GPAptr=3.9;
    cout<<"Name:"<<i.name<<endl;
    cout<<"Gpa:"<<*i.GPAptr<<endl;
    cout<<"Name:"<<i2.name<<endl;
    cout<<"Gpa:"<<*i2.GPAptr<<endl;

    // // Deep copy:
    // Info i("Zubair",3.5);
    // Info i2(i);
    // cout<<"Name:"<<i.name<<endl;
    // cout<<"Gpa:"<<*i.GPAptr<<endl;
    // i2.name="Faisal";
    // *i2.GPAptr=3.9;
    // cout<<"Name:"<<i.name<<endl;
    // cout<<"Gpa:"<<*i.GPAptr<<endl;
    // cout<<"Name:"<<i2.name<<endl;
    // cout<<"Gpa:"<<*i2.GPAptr<<endl;


    // Destructor:
    // Car c("Toyota Supra","LMN123");
    // c.~Car();

    // There is a difference of constructor and destructor calling in code.
    // In inheritance we call child constructor automatically base or
    //  parent constructor is called or built and then child called.
    // Destructor is totally reversed or opposite of this process. 
    // In heritance when destructor is called  firstly child object is destroyed 
    // or child destructor is called and then base or parent destructor is called.

    // Single-level Inheritance
    Student s("Ali",20000,"CS",3.77f);
    s.displayInfo();
    Account a("Furkan","Furkan@123",50000);
    cout<<"Current balance:"<<a.getBalance()<<endl;
    a.withdraw(5000);
    cout<<endl;
    // cout<<s.getGPA()<<endl;

    // Multi-level Inhertance
    GraduateStudents g;
    g.age=20;
    g.name="Faizan";
    g.researchProject="AI&ML";
    g.rollNo=1;
    g.display();

    // Multiple Inheritance
    StudentsAsTeachers st;
    st.name="Danish";
    st.rollNo=1;
    st.salary=60000;
    st.subject="OOP";
    st.displayInfo();

    // There are also types of inheritance like hirarical inheritance,Hybrid inheritance
    // In this type of inheritance more than one child use or inherit from one parent
    //  or in simple language more than one child classes have one parent class.
    // In hybrid inheritance all the inheritance are done or implemented randomly or 
    // in specific order. Sometimes single level apply or sometimes multi level apply.
    // sometimes multiple inheritance.
    

    // static keyword:
    // static variable:
    A th;
    th.increamentA();
    cout<<"Value of x is :"<<th.x<<endl;
    th.increamentA();
    cout<<"Value of x is :"<<th.x<<endl;

    // static objects:
    objects o;
    // static objects o; uncomment this line to check and comment the normal object
    cout<<"Now the main function ends"<<endl;


    

    return 0;
}