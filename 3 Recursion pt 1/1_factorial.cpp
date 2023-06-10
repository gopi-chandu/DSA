#include <iostream>
using namespace std;

int factorial(int n)
{
    if(n==0)
    {
        return 1;
    }
    int smallOutput=factorial(n-1);
    return n*smallOutput;
}
int main()
{
    int n,output;
    cout<<"enter n value:"<<endl;
    cin>>n; 
    output=factorial(n);
    cout<<output<<endl; 
    return 0;
}