#include<iostream>
#include<queue>
using namespace std;
int calcMedian(priority_queue<int> p,int n)
{
    int ans=0;
    if(n%2==0)
    {
        for(int i=1;i<n/2;i++)
        {
            p.pop();
        }
        int a=p.top();
        p.pop();
        int b=p.top();
        ans=(a+b)/2;
    }
    else{
        for(int i=1;i<n/2;i++)
        {
            p.pop();
        }
        //cout<<p.top()<<endl;
        ans=p.top();
    }
    return ans;
}

int calcMedianArray(int *a,int n)
{
    priority_queue<int> p;
    for(int i=0;i<n;i++)
    {
        p.push(a[i]);
    }
    int ans=0;
    if(n%2==0)
    {
        for(int i=1;i<n/2;i++)
        {
            p.pop();
        }
        int a=p.top();
        //cout<<"a : "<<a<<endl;
        p.pop();
        int b=p.top();
        //cout<<"b : "<<b<<endl;
        ans=(a+b)/2;
        //cout<<"ans: "<<ans<<endl;
    }
    else{
        for(int i=1;i<n/2+1;i++)
        {
            //cout<<"Hello"<<endl;
            p.pop();
        }
        //cout<<p.top()<<endl;
        ans=p.top();
        //cout<<"Ans: "<<ans<<endl;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    priority_queue<int> p;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cout<<calcMedianArray(a,i+1)<<endl;
    }
    delete a;
}