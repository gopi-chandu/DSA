#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>
using namespace std;
int frequency1(int * a,int size)
{
    unordered_map<int,int> freq;
    int max=1;
    int maxInteger=a[0];
    for(int i=0;i<size;i++)
    {
        if(freq.count(a[i])>0)
        {
            freq[a[i]]++;
            if(freq[a[i]]>max)
            {
                max=freq[i];
                maxInteger=a[i];
            }
        }
        else{
            freq[a[i]]=1;
        }
    }
    return maxInteger;
}
int main()
{
    int size;
    cin>>size;
    int *a=new int[size];
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    cout<<frequency1(a,size)<<endl;
    delete a;
}