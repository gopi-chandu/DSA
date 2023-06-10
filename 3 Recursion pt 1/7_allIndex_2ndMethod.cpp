#include<iostream>
using namespace std;
//not working emo
int allindex(int *a,int size,int x,int *output)
{
    //base case
    if(size==0)
    {
        return 0;
    }
    //recursion
    int ans=allindex(a,size-1,x,output);

    //small caculation
    if(*(a+size-1)==x) //same as a[size-1]==x
    {
        output[ans]=size-1;
        ans++;
        return ans;
    }
    else{
        return ans;
    }
}
int main()
{
   
    int a[7]={5,5,6,9,9,5,6};
    int output[10];
    int answer=allindex(a,7,9,output);
    cout<<"Answer : "<<answer<<endl;
   /* //printing in decending order
    for(int i=answer-1;i>=0;i--)
    {
        cout<<output[i]<<endl;
    }*/
    //printing in normal sequence
    for(int i=0;i<answer;i++)
    {
        cout<<output[i]<<endl;
    }
    return 0;
}