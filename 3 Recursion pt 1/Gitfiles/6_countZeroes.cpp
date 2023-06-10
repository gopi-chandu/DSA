#include<iostream>
using namespace std;
int count=0;
int countZero(int n)
{
    if(n==0)
    {
        return count;
    }
    int lastdigit=n%10;
    if(lastdigit==0)
    {
        count++;
        countZero(n/10);
    }
    else{
        countZero(n/10);
    }
    
    return count;    
}
int main()
{
    int n;
    cout<<"Enter a number : "<<endl;
    cin>>n;
    cout<<countZero(n)<<endl;
}