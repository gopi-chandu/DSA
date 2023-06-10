#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int n,k;
    cin>>n;
    priority_queue<int> p;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        p.push(k);
    }
    cin>>k;
    for(int i=1;i<k;i++)
    {
        p.pop();
    }
    cout<<p.top()<<endl;

}