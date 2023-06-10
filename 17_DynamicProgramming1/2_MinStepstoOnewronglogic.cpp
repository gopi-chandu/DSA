#include<iostream>
using namespace std;
//bruteForce approach
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

//memoization - recursive
int countStepsRecursive(int n,int *a)
{
    if(n==1)
    {
        return 0;
    }
    //check if it exists
    if(a[n]!=-1)
    {
        return a[n];
    }

    if(n%2==0)
    {
        n=n/2;
    }
    else if(n%3==0)
    {
        n=n/3;
    }
    else{
        n=n-1;
    }
    //Save 
    int ans= 1+countStepsRecursive(n,a);
    a[n]=ans;
    return a[n];
}
int countStepsRecursive(int n)
{
    int *a=new int[200];
    for(int i=0;i<200;i++)
    {
        a[i]=-1;
    }
    return countStepsRecursive(n,a);
}

int main()
{
    int n;
    cin>>n;
    cout<<countStepsRecursive(n)<<endl;
    
}

