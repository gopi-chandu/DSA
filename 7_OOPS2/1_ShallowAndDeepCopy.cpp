#include<cstring>
#include<iostream>
using namespace std;
class student{
    int age;
    char *name;
    public:
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

    void display(){
        cout<<name<<" "<<age<<endl;
    }
};