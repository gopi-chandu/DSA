#include<iostream>
using namespace std;
int removeDuplicate(char str[])
{
    //base case
    if(str[0]=='\0')
    {
        return 0;
    }
    //Recursion
    removeDuplicate(str+1);

    //small calculation
    int i=1;
    if(str[0]==str[1])
    {
        for(i=0;str[i]!='\0';i++)
        {
            str[i]=str[i+1];
        }
       str[i]=str[i+1];
    }

}

int main()
{
    char str[100];
    cin>>str;
    cout<<str<<endl;
    removeDuplicate(str);
    cout<<str<<endl;
}