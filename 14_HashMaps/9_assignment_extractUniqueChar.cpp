#include<iostream>
#include<string>
#include<cstring>
#include <unordered_map>
using namespace std;
int main()
{
    string str;
    cin>>str;
    
    unordered_map<char,int> ourmap;
    for(int i=0;i<str.length();i++)
    {
        if(ourmap.count(str[i])>0)
        {
            ourmap[str[i]]++;
        }
        else{
           ourmap[str[i]]=1;
           cout<<str[i];
        }
    }  
}



