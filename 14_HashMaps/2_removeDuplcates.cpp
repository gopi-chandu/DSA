#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>
using namespace std;
/*
vector<int>* removeDup(int *a,int size)
{
    vector<int>* ans=new vector<int>;
    unordered_map<int,int> mymap;
    for(int i=0;i<size;i++)
    {
        if(mymap.count(a[i])>0)
        {
            mymap[a[i]]++;
        }
        else{
            mymap.insert(a[i],1);
            ans->push_back(a[i]);
        }
    }
    return ans;

}*/
vector<int> removeDuplicates(int *a,int size)
{
    vector<int> output;
    unordered_map<int,bool> seen;
    for(int i=0;i<size;i++)
    {
        if(seen.count(a[i])>0)
        {
            continue;
        }
        else{
            seen[a[i]]=true;
            output.push_back(a[i]);
        }
    }
    return output;

}
int main()
{
    int a[25]={7,7,7,1,2,3,3,2,1,4,3,6,5,5},size=14;
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    vector<int> output=removeDuplicates(a,size);
    for(int i=0;i<output.size();i++)
    {
        cout<<output[i]<<endl;
    }

}