#include<iostream>
using namespace std;
#include<stack>
#include<cstring>
stack<char> reverseStack(stack<char> s1,int n)
{
    stack<char> s2;
    for(int i=0;i<n;i++)
    {
        char ch=s1.top();
        s2.push(ch);
        s1.pop();
    }

    return s2;

}
int main()
{
    stack<char> s1;
    string a="Gopi chandu";
    //getline(cin,a);
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        s1.push(a[i]);
    }
    stack <char> s2=reverseStack(s1,n);
    /*for(int i=0;i<n;i++)
    {
        char ch=s1.top();
        cout<<ch<<" ";
        s1.pop();
    }*/
    for(int i=0;i<n;i++)
    {
        char ch=s2.top();
        cout<<ch<<" ";
        s2.pop();
    }
}