#include<iostream>
using namespace std;
class fraction{
    public:
    int numerator;
    int denominator;
    fraction()
    {

    }
    fraction(int numerator,int denominator){
        this->numerator=numerator;
        this->denominator=denominator;
    }
    void simplify()
    {
        //int small=min(numerator,denominator);
        int small=(numerator<denominator)?numerator:denominator;
        int gcd=1;
        for(int i=1;i<=small;i++)
        {
            
            if((numerator%i==0)&&(denominator%i==0))
            {
                gcd=i;
            }
        }
        numerator=numerator/gcd;
        denominator=denominator/gcd;
    }
    fraction Sum(fraction *f2)
    {
        int x=this->denominator;
        int y=f2->denominator;
        fraction fn;
        fn.numerator=this->numerator*y+f2->numerator*x;
        fn.denominator=this->denominator*f2->denominator;
        fn.simplify();
        return fn;
    }
    void display()
    {
        cout<<numerator<<" / "<<denominator<<endl;
    }
    void multiply(fraction *f2){
        this->denominator*=f2->denominator;
        this->numerator*=f2->numerator;
        simplify();
    }
    //overloaded functions

    //as this fn is not changing the original f1 values so we can make const
    fraction operator+(fraction *f2) const{
        int x=this->denominator;
        int y=f2->denominator;
        fraction fn;
        fn.numerator=this->numerator*y+f2->numerator*x;
        fn.denominator=this->denominator*f2->denominator;
        fn.simplify();
        return fn;
    }
    fraction operator*(fraction &f2) const{
        fraction fn;
        fn.denominator=f2.denominator*this->denominator;
        fn.numerator=f2.numerator*this->numerator;
        fn.simplify();
        return fn;
    }
    bool operator==(fraction &f2){
        return (this->numerator==f2.numerator&&this->denominator==f2.denominator);
    }  
    fraction& operator++(){
        numerator=numerator+denominator;
        simplify();
        return *this;
    }
    //post increment
    fraction operator++(int )
    {
        fraction fnew(numerator,denominator);
        numerator=numerator+denominator;
        simplify();
        fnew.simplify();
        return fnew;
    }
    void operator+=(fraction const &f2)
    {
        int x=this->denominator;
        int y=f2.denominator;
        this->numerator=this->numerator*y+f2.numerator*x;
        denominator=this->denominator*f2.numerator;
        simplify();

    }
};
int main()
{
    
    fraction f1(11,11);
    fraction f2(10,2);
    /*fraction f3=f1.Sum(&f2);
    fraction f4=f1+&f2;
    fraction f5=f1*f2;
    f1.display();
    f2.display();
    f3.display();
    f4.display();
    f5.display();
    if(f4==f3)
    {
        cout<<"True";
    }
    else{
        cout<<"False";
    }*/
    //pre increment
    /*++f2;
    f2.display();
    fraction f4=++(++f1);
    f4.display();*/
    //post increment
    fraction f5=f1++;
    cout<<"f5 : ";f5.display();
    //f1.display();
    fraction f6(1,2);
    cout<<"f6 : ";f6.display();
    f6+=f5;
    cout<<"f6 : ";f6.display();
    f6+=f5;
    cout<<"f6 : ";f6.display();

    return 0;
}