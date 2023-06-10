#include<iostream>
using namespace std;
class student{
    public:
    //non static members , copies are created if you create a new object of student 
    int age;
    int roll;
    //static members - a new copy not made rather it is common for rest of the objects 
    static int totalStudents;
    student(){
        totalStudents+=1;
    } 
    int getRollno(){
        return roll;
    }
    static int getTotalStudents(){
        return totalStudents;
    }
};
//we cannot use non static members in static function, ststic members donot have this operator
//as static member property type is integer we type int 
//to access non static members we use class object like s1.age, to access the  static members we use classname::method example : student::display()
int student::totalStudents=0;
int main(){
    student s1,s2;
    cout<<"s1 age"<<s1.age<<endl;
    cout<<student::totalStudents<<endl;
    //we can access static member using objects to but we must not do this logically
   // s1.totalStudents=20;
    cout<<"total students using s1 : "<<s1.totalStudents<<endl;
    cout<<"total students using s2 : "<<s2.totalStudents<<endl;
    cout<<"total students class : "<<student::totalStudents<<endl;
    student s3,s4,s5,s6,s7;
    cout<<"total students class : "<<student::totalStudents<<endl;
    cout<<"total students class : "<<student::getTotalStudents<<endl;
}
