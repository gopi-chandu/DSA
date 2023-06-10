#include<bits/stdc++.h>
using namespace std;

//memoization
int minCountMemo(int n,int *arr)
{
    if(arr[n]!=-1) return arr[n];
    if(n==1||n==2||n==3) return  n;
    int ans=n;
    for(int i=1;i*i<=n;i++)
    {
       ans=min(ans,1+minCountMemo(n-i*i,arr));
    }
    arr[n]=ans;
    return arr[n];
}

//recursion
int minCount(int n)
{
    if(n==1||n==2||n==3) return  n;
    int ans=n;
    for(int i=1;i*i<=n;i++)
    {
        ans=min(ans,1+minCount(n-(i*i)));
    }
    return ans;
}
int arr[1000];
int main()
{
    

    for(int i=0;i<1000;i++)
    {
        arr[i]=-1;
    }
    int n;
    cin>>n;
    cout<<minCount(n)<<endl;
    cout<<"HEllo "<<endl;
    cout<<minCountMemo(n,arr)<<endl;
    
}