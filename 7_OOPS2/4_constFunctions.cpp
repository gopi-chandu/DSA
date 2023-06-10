//using a constant object you cannot call normal functions but you can call only functions
//const functions- which does not change any property of current object
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
    //we made these functions constant explicitly
    int getNumerator() const{
        return numerator;
    }
    int getDenominator() const{
        return denominator;
    }
    //non const fns---even if you keep const keyword they will give error as we are changing the values
    void setNumerator(int n){
        numerator=n;
    }
    void setDenominator(int d) {
       denominator=d;
    }
    void simplify()
    {
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
    void Sum(fraction *f2)
    {
        int x=this->denominator;
        int y=f2->denominator;
        this->numerator=this->numerator*y+f2->numerator*x;
        this->denominator=this->denominator*f2->denominator;
        simplify();
    }
    void display() const
    {
        cout<<numerator<<" / "<<denominator<<endl;
    }
    void multiply(fraction *f2){
        this->denominator*=f2->denominator;
        this->numerator*=f2->numerator;
        simplify();
    }
};
int main()
{
    fraction f1(1,9);
    fraction const f2(6,9);
    cout<<f2.getDenominator();
    f2.display();
    return 0;
}