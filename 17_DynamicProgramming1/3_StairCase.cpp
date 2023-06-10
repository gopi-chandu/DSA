#include<iostream>
using namespace std;

int stairCase(int n)
{
    if(n==1) return n;
    if(n==2) return n;
    if(n==3) return n;
    int p1=0,p2=0,p3=0;
    p1=stairCase(n-1);
    if(n%2==0) p2=stairCase(n/2);
    if(n%3==0) p3=stairCase(n/3);
    
    return p1+p2+p3;
}

int main()
{
    int n;
    cin>>n;
    cout<<stairCase(n)<<endl;
}