#include<iostream>
using namespace std;
#include "1_class.cpp"
int main()
{
    /*Student s1;
    Student s2,s3;

    s1.age=25;
    s1.roll=45;
    cout<<"S1 : "<<endl<<"age : "<<s1.age<<endl<<"roll no : "<<s1.roll<<endl;

    Student *s5=new Student;
    (*s5).age=29;
    (*s5).roll=3;
    s5->age=99;
    s5->roll=2;
    cout<<"S5 heap : "<<endl<<"age : "<<(*s5).age<<endl<<"roll no : "<<s5->roll<<endl;
    delete s5;*/

    
    Student *s2=new Student(1,2);
    Student s1(*s2);
    //s1.set(1,20);
    s1.display();
    //s2->set(2,99);
    s2->display();
    delete s2;
}