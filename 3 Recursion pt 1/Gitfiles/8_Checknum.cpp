#include <iostream>
using namespace std;


int checknum(int *a,int size,int x)
{
    //base case
    if(size==0)
    {
        return 0;
    }

    //
    int ans=checknum(a+1,size-1,x);

    if(a[0]==x)
    {
        return 1;
    }

    return ans;
}

int main()
{
    int n,x;
    cin>>n>>x;
    int *pa=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>pa[i];
    }

    cout<<checknum(pa,n,x)<<endl;
    //delete heap array
    delete pa;

}