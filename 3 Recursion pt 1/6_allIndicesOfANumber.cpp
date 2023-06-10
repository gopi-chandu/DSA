#include<iostream>
using namespace std;
int allIndices(int *a,int size,int x, int output[])
{
    //base case
    if (size==0)
    {
        return 0;
    }
    
    //recursion
    int ans=allIndices(a+1,size-1,x,output);

    //small calculation
    if (a[0]==x)
    {
        for (int i=ans-1;i>=0;i--)
        {
            output[i+1]=output[i]+1;
        }
        output[0]=0;
        ans++;
    }
    else{
        //Incrment answer
        for (int i=ans-1;i>=0;i--)
        {
            output[i]=output[i]+1;
        }
    }

    return ans;
}
int main()
{
    int a[7]={5,5,6,9,9,5,6};
    int output[10];
    int answer=allIndices(a,7,9,output);
    cout<<"ans"<<answer<<endl;
    for(int i=answer-1;i>=0;i--)
    {
        cout<<output[i]<<" "<<endl;
    }

}