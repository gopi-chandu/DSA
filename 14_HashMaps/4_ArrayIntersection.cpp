#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>
using namespace std;
int ArrayIntersection(int * a,int * b,int n1,int n2)
{
    unordered_map<int,int> freq1;
   /* int max=1;
    int maxInteger=a[0];*/
    for(int i=0;i<n1;i++)
    {
        if(freq1.count(a[i])>0)
        {
            freq1[a[i]]++;
        }
        else{
            freq1[a[i]]=1;
        }
    }

    for(int i=0;i<n2;i++)
    {
        if(freq1.count(b[i])>0)
        {
            freq1[b[i]]--;//marking b elements in a and cutting them
            cout<<b[i]<<"";
        }
    }
    cout<<endl;

}


int main()
{
    int t=1;
    cin>>t;
    while(t>0)
    {
        
        int n1,n2;
        cin>>n1;
        int *a=new int[n1];
        for(int i=0;i<n1;i++)
        {
            cin>>a[i];
        }
        cin>>n2;
        int *b=new int[n2];
        for(int i=0;i<n2;i++)
        {
            cin>>b[i];
        }
        ArrayIntersection(a,b,n1,n2);
        delete a;
        delete b;
        t--;
    }
    
}