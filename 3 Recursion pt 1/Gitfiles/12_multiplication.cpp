#include <iostream>
using namespace std;
int multi(int f,int s)
{
    int ans;
    //base case
    if (f==0)
    {
        return 0;
    }

    //recursion
    if (f>0)
    {
        ans=multi(f-1,s);
    }
    else{
        ans=multi(f-1,s);
    }

    return ans;
}

//perfectly works 
int multisimplify(int f,int s)
{
    if (f==1) return s;
    if(f==0)
    {
        return 0;
    }
    if(f>0)
    {
        return s+multisimplify(f-1,s);
    }
    if(f<0)
    {
        return -multisimplify(-f,s);
    }
    
}

int main()
{
    int f=3,l=-5;
    cout<<multisimplify(f,l)<<endl;
}