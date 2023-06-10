#include <iostream>
using namespace std;
int fibanocci(int n)
{
    if(n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1;
    }
    int smallinput1=fibanocci(n-1);
    int smallinput2=fibanocci(n-2);
    return smallinput1+smallinput2;
}

int main()
{ 
    cout<<fibanocci(9);
    /*for (int i=0;i<n;i++  )
    {
        cout<<fibanocci(i)<<" ";
    }*/
    return 0;
}