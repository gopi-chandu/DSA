#include<iostream>
using namespace std;
class complex{
    int real;
    int img;
    public:
    //constructors
    complex()
    {

    }
    complex(int real, int img)
    {
        this->real=real;
        this->img=img;
    }
    void display(){
        cout<<real<<"+("<<img<<")i"<<endl;
    }
    void multiply(complex *c2){
        int x=c2->real;
        int y=c2->img;
        this->real*=x;
        this->img*=-y;
        display();
    }
    void add(complex *c2)
    {
        this->real+=c2->real;
        this->img+=c2->img;
        display();
    }
};