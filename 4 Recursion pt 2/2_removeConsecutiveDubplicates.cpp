#include<iostream>
using namespace std;
void removeCD(char s[])
{
    //base case
    if (s[0]=='\0')
    {
        return ;
    }
    //recursion+calculation
    if(s[1]!=s[0])
    {
        removeCD(s+1);
    }
    else if(s[0]==s[1])
    {
        int i=1;
        for (i;s[i]!='\0';i++)
        {
            s[i-1]=s[i];
        }
        s[i-1]=s[i];
        removeCD(s);
    }

}

int main()
{
    char str[100];
    cin>>str;
    cout<<str<<endl;
    removeCD(str);
    cout<<str<<endl;
}