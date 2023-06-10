#include <bits/stdc++.h>
using namespace std;
//testing 
int gpSum(int n)
{
    if(n>0)
    {
        float ans=gpSum(n-1);
        ans=ans+(1/pow(2,n));
        return 0;
    }
    return 0;
}

// general syntax
int gpSum1(int n)
{
    //base case
    if(n==0)
    {
        return 1;
    }

    //recursion
    float ans=gpSum1(n-1);

    //small calculation
    ans=ans+(1/pow(2,n));
    cout<<ans<<" ";
    return ans;

}
int main()
{
    int n=3;
    //cout<<gpSum(n)<<endl;
    cout<<gpSum1(n-1)<<endl;

}
