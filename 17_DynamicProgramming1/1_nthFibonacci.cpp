#include<iostream>
using namespace std;
//Dynamic Programming == Iterative , the best compared to recursive in terms of space complexity 
int fibo3(int n)
{
    int *ans=new int[n+1];
    ans[0]=0;
    ans[1]=1;
    for(int i=2;i<n+1;i++)
    {
        ans[i]=ans[i-1]+ans[i-2];
    }
    return ans[n];
}
//Memorization== recursion
int fibo2Helper(int n,int * ans)
{
    //base case
    if(n<=1)
    {
        return n;
    }
    //check before recursion calls
    if(ans[n]!=-1)
    {
        return ans[n];
    }
    //recursion calls
    int a=fibo2Helper(n-1,ans);
    int b=fibo2Helper(n-2,ans);

    //save answer for future
    ans[n]=a+b;
    return ans[n];
}
int fibo2(int n)
{
    int * ans=new int[n+1];
    for(int i=0;i<n+1;i++)
    {
        ans[i]=-1;
    }
    return fibo2Helper(n,ans);
}

//Brute Force approach
int fibo(int n)
{
    if(n<=1)
    {
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}
int main()
{
    cout<<fibo3(7)<<endl;
}