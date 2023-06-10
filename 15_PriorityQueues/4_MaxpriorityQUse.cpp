#include<iostream>
#include "3_ClassMaxPriorityQueues.cpp"
using namespace std;

int main()
{
    maxPriorityQueue p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout<<"Get size : "<<p.getSize()<<endl;
    cout<<"Get Min : "<<p.getMax()<<endl;

    while(!p.isEmpty())
    {
        cout<<p.removeMax()<<" ";
    }
    cout<<endl;
}