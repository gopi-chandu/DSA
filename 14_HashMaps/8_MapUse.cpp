#include<iostream>
#include<string>
#include<cstring>
#include "7_HashMapsImplemntation.cpp"
using namespace std;
int main()
{
    ourmap<int> map;
    for(int i=0;i<10;i++)
    {
        char c='0'+i;
        string key="abc";
        key=key+c;
        int value=i+1;
        map.insert(key,value);
        cout<<"Load Factor : "<<map.getloadFactor()<<endl;
    }
    cout<<"Map size : "<<map.size()<<endl;
    map.remove("abc2");
    map.remove("abc7");
    cout<<"Map size : "<<map.size()<<endl;
    for(int i=0;i<10;i++)
    {
        char c='0'+i;
        string key="abc";
        key=key+c;
        cout<<key<<" : "<<map.getValue(key)<<endl;
    }