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
    void Sum(fraction *f2)
    {
        int x=this->denominator;
        int y=f2->denominator;
        this->numerator=this->numerator*y+f2->numerator*x;
        this->denominator=this->denominator*f2->denominator;
        simplify();
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
};
int main()
{
    fraction f1(1,9);
    fraction f2(6,9);
    f1.Sum(&f2);
    f1.display();
    //using new f1 we multiply with f2
    f1.multiply(&f2);
    f1.display();
    return 0;
}