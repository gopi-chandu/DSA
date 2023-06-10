#include<iostream>
using namespace std;

int index(int a[],int size,int n)
{
    int smallanswer;
    // p of 1
    if(a[0]==n)
    {
        return 0;
    }
    if (size==0)
    {
        return -1;
    }
    if(smallanswer==-1)
    {
        return smallanswer;
    }
    else{
        smallanswer=index(a+1,size-1,n)+1;
    }
    
}
int main()
{
    int a[7]={5,5,6,9,9,5,6};
    cout<<index(a,7,9);
    
}