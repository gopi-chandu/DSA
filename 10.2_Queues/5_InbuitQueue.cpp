#include<iostream>
using namespace std;
#include<queue>
int main()
{
    queue <char>q1;
    q1.push(65);
    q1.push(66);
    q1.push(67);
    q1.push(68);
    q1.push(69);
    q1.push(70);
    cout<<"Size "<<q1.size()<<endl;
    cout<<"Front "<<q1.front()<<endl;
    cout<<"Empty "<<q1.empty()<<endl;
    while(!q1.empty())
    {
        cout<<q1.front()<<" ";
        q1.pop();
    }
    /*cout<<"Front "<<q1.front()<<endl;
    q1.pop();
    q1.pop();
    cout<<"Size "<<q1.size()<<endl;
    cout<<"Front "<<q1.front()<<endl;
    cout<<"Empty "<<q1.empty()<<endl;*/

}