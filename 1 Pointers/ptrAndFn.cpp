#include<iostream>
using namespace std;

void print(int * p)
{
    cout<<*p<<endl;
}

int sum(int *a,int size)
{
    int ans=0;
    for(int i=0;i<size;i++)
    {
        ans+=*(a+i);// adding garbage value
    }
    return ans;
}
int main()
{
    int i=10;
    int *p=&i;
    print(p);

    int a[10];
    cout<<sum(a,10)<<endl;
    // print remaining array from a+3
    cout<<sum(a+3,10)<<endl;
}