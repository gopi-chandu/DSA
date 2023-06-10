#include<iostream>
using namespace std;
#include<stack>
#include<cstring>
int main()
{
    stack<char> s;
    string array;
    //getline(cin,array);
    array="{a+[b-(c*d)]+g}";
    int n=array.size();
    int flag=1;
    for(int i=0;i<n;i++)
    {
        if(array[i]=='{' ||array[i]=='[' ||array[i]=='(')
        {
            s.push(array[i]);
        }
    
        else if(array[i]=='}' ||array[i]==']' ||array[i]==')')
        {
            if(s.empty())
            {
                return false;
            }
            cout<<s.top()<<" "<<array[i]<<endl;
            char ch=s.top();
            s.pop();
            if(ch=='{'&&array[i]=='}')
            {
                continue;
            }
            else if(ch=='['&&array[i]==']')
            {
                continue;
            }
            else if(ch=='('&&array[i]==')')
            {
                continue;
            }
            else{
                return false;
            }
        }
    }
    if(s.empty())
    {
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
       }
}