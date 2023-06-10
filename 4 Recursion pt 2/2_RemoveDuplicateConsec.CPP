#include<iostream>
using namespace std;

int remove(char a[])
{
    //base case
    if(a[0]=='\0')
    {
        return 0;
    }
    
    //small calc
    if (a[0]==a[1])
    {
        int i=1;
        for (i;a[i]!='\0';i++)
        {
            a[i-1]=a[i];
        }
        a[i-1]=a[i];
        remove(a);
    }
    else{
        remove(a+1);
    }

}

int main()
{
    char a[5];
    cin>>a;
    remove(a);
    cout<<endl;
    cout<<a;
    return 0;
}