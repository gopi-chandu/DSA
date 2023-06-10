#include <iostream>
using namespace std;
int noOfDigits(int n)
{
    //base for both - ve and +ve 
    if(n==0)
    {
        return 0;
    }
    //recursion + small calculation
    int ans=1+noOfDigits(n/10);
    return ans;
}

int main()
{
    int n=121562;
    cout<<noOfDigits(n);
}