#include <iostream>
using namespace std;
int sumofArray(int *a,int size)
{
    //base case 
    if (size==0)
    {
        return 0;
    }

    //recursion
    int ans=sumofArray(a+1,size-1);

    //small calculation
    ans=ans+a[0];
    return ans;
}

int main()
{
    int a[5]={1,2,3,9,5};
    cout<<sumofArray(a,5);
    
}