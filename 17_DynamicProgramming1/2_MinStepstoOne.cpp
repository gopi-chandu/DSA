#include<iostream>
using namespace std;
//brute force not working
int bruteForceSteps(int n)
{
    int stepsCount=0;
    if(n%3==0)
    {
        n=n/3;
    }
    else if(n%2==0)
    {
        n=n/2;
    }
    else{
        n=n-1;
    }
    stepsCount++;
    cout<<stepsCount<<endl;
}
//recursion
int CountStepsRecursive1(int n)
{
    int arr[n+1];
    for(int i=0;i<=n;i++)
    {
        arr[i]=0;
    }
    return CountStepsRecursive1(n);
}//memorisation
int CountStepsRecursive(int *arr,int n)
{
    int x=INT8_MAX,y=INT8_MAX,z=INT8_MAX;
    //base case
    if(n<=1)
    {
        return 0;
    }
    //check if it exists
    if(arr[n]!=0)
    {
        return arr[n];
    }
    //small calc + recursion
    x=CountStepsRecursive(arr,n-1);
    if(n%2==0)
    {
       y=CountStepsRecursive(arr,n/2);
    }
    if(n%3==0)
    {
        z=CountStepsRecursive(arr,n/3);
    }
    int  ans= min(x,min(y,z))+1;

    //save
    arr[n]=ans;
    return ans;

}

int minCountsDp(int n)
{
    int ans[n+1];
    ans[0]=0;
    ans[1]=0;
    for(int i=2;i<=n;i++)
    {
        int a=INT8_MAX,b=INT8_MAX;
        int x=ans[i-1];
        if(i%2==0)
        {
            a=ans[i/2];
        }
        if(i%3==0)
        {
            b=ans[i/3];
        }
        ans[i]=1+min(x,min(a,b));
    }
    return ans[n];
}

//Dp CN program-
int minStepsHelper(int n,int *ans)
{
    if(n<=1)
    {
        return 0;
    }
    //check if output exists
    if(ans[n]!=-1)
    {
        return ans[n];
    }
    ans[0]=0;
    ans[1]=0;
    for(int i=2;i<=n;i++)
    {
        int a=INT8_MAX,b=INT8_MAX, c=0;
        c=ans[i-1];
        if(i%2==0) a=ans[i/2];
        if(i%3==0) b=ans[i/3];
        ans[i]=min(a,min(b,c))+1;
    }

    return ans[n];
}
int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<100;i++) a[i]=-1;
    cout<<minCountsDp(n)<<endl;
    cout<<minStepsHelper(n,a)<<endl;
}