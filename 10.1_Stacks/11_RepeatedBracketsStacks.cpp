#include<iostream>
using namespace std;
#include<stack>
#include<cstring>
//only one type of braces()
bool repeatedBrackets(string a){
    stack<char> s;
    int count=0;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        if(a[i]=='(')
        {
            count++;
            s.push(a[i]);
        }
        else if(a[i]==')')
        {
            s.pop();
        }
    }
    if(s.empty())
    {
        if(count>1)
        {
            return true;
        }
        else{
            return false;
        }
    }
    else{
        false;
    }
    
}
int main()
{
    string a;
    //a="((a+b))";
    //a="(a+b)";
    a="((a)+(b))";
    bool k=repeatedBrackets(a);
    if(k)
    {
        cout<<"True"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}