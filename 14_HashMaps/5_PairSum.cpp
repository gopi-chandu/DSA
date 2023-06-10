// using map o(n)
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>
using namespace std;
int pairSum(int *a,int sum,int size)
{
    vector<pair<int,int>> p;
    int count=0;
    unordered_map<int,int> m;
    for(int i=0;i<size;i++)
    {
        int compliment=sum-a[i];
        if(m[compliment]==0)
        {
            m[a[i]]++;
        }
        else
        {
            cout<<"compliment : "<<m[compliment]<<endl;
            count+=1;
            //count+=m[compliment];
            m[a[i]]++;
            pair<int,int> p1(a[i],compliment);
            p.push_back(p1);
        }
    }
    for(int i=0;i<p.size();i++)
    {
        cout<<"("<<p[i].first<<", "<<p[i].second<<")"<<endl;
    }
    return count;
}
int main()
{
    int n1;
    cin>>n1;
    int *a=new int[n1];
    for(int i=0;i<n1;i++)
    {
        cin>>a[i];
    }
    cout<<pairSum(a,0,n1);
}