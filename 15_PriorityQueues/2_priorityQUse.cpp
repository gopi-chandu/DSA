#include<iostream>
#include "1_ClassPriorityQueue.cpp"
using namespace std;

int main()
{
    PriorityQueue p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout<<"Get size : "<<p.getSize()<<endl;
    cout<<"Get Min : "<<p.getMin()<<endl;

    while(!p.isEmpty())
    {
        cout<<p.removeMin()<<" ";
    }
    cout<<endl;
}