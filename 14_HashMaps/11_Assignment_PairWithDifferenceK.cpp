#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>
using namespace std;
int pairWithDiffK(int* a,int k,int n)
{
    int count=0;
    int compliment1=0;
    int compliment2=0;
    vector<pair<int,int>> v;
    unordered_map<int,int> map;

    for(int i=0;i<n;i++)
    {
        if(k==0)
        {
            if(map[a[i]]==0)
            {
                map[a[i]]++;
            }
            else
            {
                count=count+1;
                map[a[i]]++;
                pair<int,int> p(a[i],compliment1);
                v.push_back(p);
            }
        }
       else{
            compliment1=a[i]+k;
            compliment2=a[i]-k;
            if(map[compliment1]==0)
            {
                map[a[i]]++;
            }
            else
            {
                count=count+1;
                map[a[i]]++;
                pair<int,int> p(a[i],compliment1);
                v.push_back(p);
            }
            if(map[compliment2]==0)
            {
                map[a[i]]++;
            }
            else
            {
                count=count+1;
                map[a[i]]++;
                pair<int,int> p(a[i],compliment2);
                v.push_back(p);
            }
        }
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<"("<<v[i].first<<", "<<v[i].second<<")"<<endl;
    }
    return count; 
}

int pairWithSumK(int* a,int k,int n)
{
    int count=0;
    unordered_map<int,int> map;
    for(int i=0;i<n;i++)
    {
        int compliment=k-a[i];
        if(map[compliment]==0) //if the element is not found 
        {
            map[a[i]]++;
        }
        else
        {
            count=count+map[compliment];
            map[a[i]]++;
        }
    }
    return count;
}
int main()
{
    int n,k;
    cin>>n;
    int * a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>k;
    cout<<pairWithDiffK(a,k,n)<<endl;
}