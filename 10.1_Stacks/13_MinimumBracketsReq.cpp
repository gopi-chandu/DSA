#include<iostream>
using namespace std;
#include<stack>
#include<cstring>
int main()
{
    stack<char> s1;
    string a;
    a="{{{{";
    int count=0;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        if(a[i]=='{')
        {
            count++;
            s1.push(a[i]);
        }
        else if(a[i]=='}')
        {
            //char ch=s1.top();
            s1.pop();
            count--;
        }
    }
    if(s1.empty())
    {
        cout<<0<<endl;
    }
    else if(s1.size()%2==0)
    {
        cout<<s1.size()/2<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    
}