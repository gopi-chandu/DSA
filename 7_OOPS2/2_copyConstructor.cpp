#include<cstring>
#include<iostream>
using namespace std;
class student{
    int age;
    
    public:
    char *name;
    //just constructor
    student(int age,char * name)
    {
        this->age=age;
        //Shallow copy - the this->name points to name from the main function and by changing it in main fn  we might change this new object name too. so avoid shallow copy
        this->name=name;

        //deep copy-
        //assign array of lenth of the given name and use strcpy fn
        this->name=new char[strlen(name)+1]; //extra +1 for null charcter t the end
        strcpy(this->name,name);
    }

    //by default implicitly shallow copy occurs 
    //Copy constructor-use reference in copy constructor because by using pass by value we an object gets created in function arguements and this again calls copy constructor and again creation of object 
    student(student &s){
        this->age=s.age;
        //this->name=s.name //shallow copy

        //deep copy
        this->name=new char[strlen(s.name)+1];
        strcpy(this->name,s.name);
    }
    void display(){
        cout<<name<<" "<<age<<endl;
    }
};