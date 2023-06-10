#include<iostream>
using namespace std;
#include "4.1_ComplexNumberClass.cpp"
int main()
{
    complex c1(1,9),c2(c1),c3(2,6);
    c1.add(&c3);
    c1.multiply(&c3);
}