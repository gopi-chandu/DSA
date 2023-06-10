#include<iostream>
using namespace std;
//original breaking from first -learning
int lastIndexCN(int *a,int size,int x)
{
    int small;
    //base case
    if (size==0)
    {
        return -1;
    }
    //recursion
    small=lastIndexCN(a+1,size-1,x);

   if (small==-1)
    {
        if(a[0]==x)
        {
        return 0;
        }
        else {
            return -1;
        }
    }
    else{
        return small+1;
    }
}
//trail
int lastIndex(int *a,int size,int x)
{
    int smallercal;
    //base case
    if (a[size-1]==x)
    {
        return size-1;
    }
    if(size==0)
    {
        return -1;
    }

    //recursive part
    smallercal=lastIndex(a,size-1,x);
}
/// Second method -- real method
int lastIndex2(int *a,int size,int x)
{
    int smallercal;
    //base case
    if (*a==x)
    {
        return size-1;
    }
    if(size==0)
    {
        return -1;
    }
    //recursive part

    smallercal=lastIndex2(a-1,size-1,x);
}

//The best code from coding ninjas working fine
int lastindexfromGit(int *a,int size,int x)
{
    //base case 
    if(size==0)
    {
        return -1;
    }

    //recursion
    int ans=lastindexfromGit(a+1,size-1,x);

    //small calculation
    
    if (ans ==-1)
    {
        if(a[0]==x)
        {
             return 0;
        }
        else{
            return -1;
        }
    }
    else{
        return ans+1;
    }
    
}

int main()
{
    int a[7]={5,5,6,9,9,5,6};
    cout<<lastindexfromGit(a,7,9);
    
}


