#include <iostream>
using namespace std;
int len(char str[])
{
    int length=0;
    for(int i=0;str[i]!='\0';i++)
    {
        length++;
    }
    return length;
}
int palindrome(char str[],int size,int start,int end)
{
    if(str[0]=='\0'|| str[1]=='\0')
    {
        return 1;
    }
    int ans=palindrome(str+1,size-1);
        if(str[0]==str[size-1])
        {
            return 1;
        }
    else
    {
        return 0;
    }
}


int main()
{
    char str[100];
    cout<<"Enter a number : "<<endl;
    cin>>str;
    int size=len(str);
    cout<<palindrome(str,size)<<endl;
}