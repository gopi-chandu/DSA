#include <iostream>
using namespace std;
//my code
int raisetoPower(int x, int n)
{   
    //Base calculation
    if(n==0)
    {
        return 1;
    }
    if(n==1)
    {
        return x;
    }

    //recursion
    int ans=raisetoPower(x,n-1);

    //small calculation
    ans=x*ans;
    return ans;
}

//git hub code

int raise(int x,int n)
{
    if (n==1)
    {
        return x;
    }
    int ans;
    if(n%2==0)
    {
        ans=raise(x,n/2)*raise(x,n/2);
    }
    else{
        ans=x*raise(x,n/2)*raise(x,n/2);
    }

    return ans;
}
int main()
{
    int x=2,n=10;
    cout<<raisetoPower(x,n)<<endl;;
    cout<<raise(x,n);
}