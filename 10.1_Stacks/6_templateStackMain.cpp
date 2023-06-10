#include<iostream>
using namespace std;
#include "5_StackAfterTemplate.cpp"
int main() 
{
    StackUsingArray <char> s;
    s.push(67);
    s.push(70);
    s.push(69);
    s.push(68);
    s.push(67);
     
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.size()<<endl;
    cout<<s.isempty()<<endl;  
}