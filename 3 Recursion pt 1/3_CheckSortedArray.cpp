#include<iostream>
using namespace std;
bool IsSorted(int *a,int size)
{
    
    //Base case
    if (a[0]>a[1])
    {
        return false;
    }
    if (size==0||size==1)
    {
        return true;
    }

    //call smaller answer
    return IsSorted(a+1,size-1);

}
int main()
{
    int a[5]={1,2,3,9,5};
    cout<<IsSorted(a,5);
    
}