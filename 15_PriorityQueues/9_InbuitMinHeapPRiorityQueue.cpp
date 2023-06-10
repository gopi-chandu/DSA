#include<iostream>
using namespace std;
#include<queue>
int main()
{
    priority_queue<int,vector<int>,greater<int>> p;
    p.push(16);
    p.push(1);
    p.push(167);
    p.push(7);
    p.push(45);
    p.push(32);

    cout<<"Size : "<<p.size()<<endl;
    cout<<"Top : "<<p.top()<<endl;
    while(!p.empty())
    {
        cout<<p.top()<<" ";
        p.pop();
    }
    cout<<endl;
}