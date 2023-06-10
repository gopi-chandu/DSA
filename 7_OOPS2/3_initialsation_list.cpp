#include<cstring>
#include<iostream>
using namespace std;
class student{
    public:
    int age;
    const int roll;
    int &x; //age refernce variable 
    //you can initialize the non const as well as const values
    student(int r,int age): roll(r),age(age),x(this->age){

    } 
};

int main(){
    student s1(101,10);
    s1.age=100;

}