#include <iostream>
using namespace std;

int sumOfDigits(int n)
{
    //base case
    if(n==0)
    {
        return 0;
    }

    //recursion
    int r=n%10;
    int ans=sumOfDigits(n/10);
    ans=ans+r;

    return ans;
}

int main()
{
    int n=12345;
    cout<<sumOfDigits(n);

}