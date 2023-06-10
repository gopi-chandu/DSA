#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<string,int> ourmap;
    ourmap["abc1"]=1;
    ourmap["abc2"]=2;
    ourmap["abc3"]=3;
    ourmap["abc4"]=4;
    ourmap["abc5"]=5;
    ourmap["abc6"]=6;
    ourmap["abc7"]=7;
    unordered_map<string,int>:: iterator it=ourmap.begin();
    //here end refers to end after last element but not the last element
    while(it!=ourmap.end())
    {
        cout<<"Key : "<<it->first<<"Value : "<<it->second<<endl;
        it++;
    }

    //find
    unordered_map<string,int>::iterator it2=ourmap.find("abc1");
    ourmap.erase(it2);
    //ourmap.erase(it2);

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    vector<int> ::iterator it3=v.begin();
    
    while(it3!=v.end())
    {
        cout<<*it3<<endl;
        it3++;
    }

}