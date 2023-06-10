#include<iostream>
using namespace std;
class Student{
    public:
    int roll;
    int age;
    //Default constructor
    Student(){
        cout<<"'Constructor 1 is called !"<<endl;
        //do nothing
    }
    Student(int age,int roll)
    {
        cout<<"Constructor 2 is called !"<<endl;
        this->age=age;
        this->roll=roll;
    }
    ~Student(){
        cout<<"Destructor is called !"<<endl;
    }
    void display(){
        cout<<age<<endl;
        cout<<roll<<endl;
    }
    int getAge()
    {
        return age;
    }
    void setAge(int a, int password)
    {
        if (password!=123)
        {
            return ;
        }
        if(a<0)
        {
            return ;
        }
        age=a;
    }
    void set(int a,int r )
    {
        age=a;
        roll=r;
    }
};